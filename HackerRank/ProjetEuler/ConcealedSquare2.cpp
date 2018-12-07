#include <bits/stdc++.h>

using namespace std;
long long countt = 0;
int n = 0, k = 0;
bool ansNotFound = true;
std::vector< int > givenSquare;
std::vector < std::vector < int > > lastDigits(10);
std::vector< int > firstDigits( 10, 0);
std::vector< std::vector < int > > secondDigits(10);

struct SquareStruct{
	std::vector< int > currNum{};
	std::vector< int > currSq{};
	int currDigits;
};

std::vector< SquareStruct > elementArray{};

void getPrelim( int index1, int index2){
	for(int index = 0; index < elementArray[index1].currNum.size(); index++){
		elementArray[index2].currNum[index] = elementArray[index1].currNum[index];
	}

	for(int index = 0; index < elementArray[index1].currSq.size(); index++){
		elementArray[index2].currSq[index] = elementArray[index1].currSq[index];
	}

	elementArray[index2].currDigits = elementArray[index1].currDigits;
}

void addSquare( int iindex, int num, int dig){
	int sq = num*num;
	int indexToAdd = elementArray[iindex].currDigits;
	elementArray[iindex].currSq[indexToAdd] += sq;
	indexToAdd = elementArray[iindex].currDigits/2;
	elementArray[iindex].currSq[indexToAdd] += (20*num*elementArray[iindex].currNum[0]);

	indexToAdd = (elementArray[iindex].currDigits + 1)/2;
	for(int index = 1; index <= elementArray[iindex].currDigits/2; index++){
		elementArray[iindex].currSq[indexToAdd] += (2*num*elementArray[iindex].currNum[index]);
		indexToAdd++;
	}

	for(int index = 0; index < elementArray[iindex].currSq.size() - 1; index++){
		elementArray[iindex].currSq[index + 1] += (elementArray[iindex].currSq[index]/100);
		elementArray[iindex].currSq[index] %= 100;
	}

	elementArray[iindex].currNum[(elementArray[iindex].currDigits + 1)/2] = num;
	elementArray[iindex].currDigits += dig;
}

void toPrint(int x){
	if(x < 10){
		std::cout << "0" << x;
	}
	else{
		std::cout << x;
	}
}

void ansFound(){
	ansNotFound = false;
	int nn = elementArray[k - 1].currNum.size();
	std::cout << elementArray[k - 1].currNum[nn - 1];
	for(int index = nn - 2; index >= 1; index--){
		toPrint(elementArray[k - 1].currNum[index]);
	}
	std::cout << elementArray[k - 1].currNum[0];
	std::cout << std::endl;
}

void finalCheck(){
	// std::cout << 1;
	int sqfd = givenSquare[givenSquare.size() - 1], fd = firstDigits[sqfd], sd;
	if(n%2 == 1){
		for(int index = 0; index < secondDigits[sqfd].size() && ansNotFound; index++){
			if(ansNotFound){
				sd = secondDigits[sqfd][index];
				getPrelim( k - 2, k - 1);
				addSquare( k - 1, fd*10 + sd, 2);
				bool flag = true;
				for(int index = elementArray[k - 1].currDigits/2; index < n && flag; index++){
					if(givenSquare[index] != (elementArray[k - 1].currSq[index])%10){
						flag = false;
					}
				}
				if(flag){
					ansFound();
				}
			}
		}
	}
	else{
		if(ansNotFound){
			getPrelim( k - 2, k - 1);
			addSquare( k - 1, fd, 1);
			bool flag = true;
			for(int index = elementArray[k - 1].currDigits/2; index < n && flag; index++){
				if(givenSquare[index] != (elementArray[k - 1].currSq[index])%10){
					flag = false;
				}
			}

			if(flag){
				ansFound();
			}
		}		
	}
}

void dfsModified( int kIndex){
	// std::cout << 1;
	if(ansNotFound){
		if(kIndex < k - 2){
			for(int x = 0; x < 100 && ansNotFound; x++){
					getPrelim( kIndex, kIndex + 1);
					addSquare( kIndex + 1, x, 2);
					if(elementArray[kIndex + 1].currSq[kIndex + 1]%10 == givenSquare[kIndex + 1]){
						dfsModified( kIndex + 1);
					}
			}
		}
		else{
			finalCheck();
		}
	}
}

void getResult(){
	for(int index = 0; index < lastDigits[givenSquare[0]].size(); index++){
		if(ansNotFound){
			elementArray[0].currNum[0] = lastDigits[givenSquare[0]][index];
			elementArray[0].currDigits = 1;
			int sq = lastDigits[givenSquare[0]][index]*lastDigits[givenSquare[0]][index];
			int dig = 0;
			while(sq){
				elementArray[0].currSq[dig] = sq%100;
				sq /= 100;
				dig++;
			}
			dfsModified(0);
		}
	}
}

void PrePrelims(){
	elementArray.resize(k);
	for(int index = 0; index < k; index++){
		elementArray[index].currNum.resize( (n/2) + 1, 0);
		elementArray[index].currSq.resize( n, 0);
		elementArray[index].currDigits = 0;
	}
}
void fillLastDigits(){
	for(int index = 0; index < 10; index++){
		int sq = index*index;
		lastDigits[sq%10].push_back(index);
	}
}
void fillFirstDigtis(){
	for(int index = 0; index < 10; index++){
		if(index > 0 && index < 4){
			firstDigits[index] = 1;
		}
		if(index >= 4 && index < 9){
			firstDigits[index] = 2;
		}
		if(index == 9){
			firstDigits[index] = 3;
		}
	}
}
void fillSecondDigits(){
	secondDigits[1] = { 0, 1, 2, 3, 4};
	secondDigits[2] = { 4, 5, 6, 7};
	secondDigits[3] = { 7, 8, 9};
	secondDigits[4] = { 0, 1, 2};
	secondDigits[5] = { 2, 3, 4};
	secondDigits[6] = { 4, 5, 6};
	secondDigits[7] = {	6, 7, 8};
	secondDigits[8] = { 8, 9};
	secondDigits[9] = { 0, 1}; 
}

int main(){
	std::cin >> n;
	k = (n/2) + 1;
	givenSquare.clear();
	givenSquare.resize( n, 0);
	for(int index = givenSquare.size() - 1; index >= 0; index--){
		std::cin >> givenSquare[index];
	}
	int starts = clock();
	PrePrelims();
	fillLastDigits();
	fillFirstDigtis();
	fillSecondDigits();
	getResult();
	int stops = clock();
	std::cout << "time  " << (double(stops - starts))/(CLOCKS_PER_SEC) << std::endl;
	return 0;
}