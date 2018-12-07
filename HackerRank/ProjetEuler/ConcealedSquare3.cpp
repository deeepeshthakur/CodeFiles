#include <bits/stdc++.h>

using namespace std;
long long countt = 0;
int n = 0, k = 0;
bool ansNotFound = true;
unsigned long long divisor = 100000000;
std::vector < unsigned long long > multiTable{ 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
unsigned long long divisorDigits = 8;
std::vector< int > givenSquare;
std::vector < std::vector < int > > lastDigits(10);
std::vector< int > firstDigits( 10, 0);
std::vector< std::vector < int > > secondDigits(10);


struct SquareStruct{
	std::vector < unsigned long long > currNum;
	std::vector < unsigned long long > currSq;
	int currDigits, digitTocheck; 
};

std::vector < SquareStruct > elementArray{};

void getPrelim( int index1, int index2){
	elementArray[index2].currDigits = elementArray[index1].currDigits;
	elementArray[index2].currNum[0] = elementArray[index1].currNum[0];
	elementArray[index2].currNum[1] = elementArray[index1].currNum[1];
}

void printVec( std::vector < unsigned long long >& vec){
	for(int xx = vec.size() - 1; xx >= 0; xx--){
		std::cout << vec[xx] << " ";
	}
}

void addSquare( int index, int num, int digits){
	int ii1 = elementArray[index].currDigits/divisorDigits, ii2 = elementArray[index].currDigits%divisorDigits;
	elementArray[index].currNum[ii1] += ((unsigned long long)(num*multiTable[ii2]));
	elementArray[index].currNum[1] += elementArray[index].currNum[0]/divisor;
	elementArray[index].currNum[0] = elementArray[index].currNum[0]%divisor;

	elementArray[index].currSq[0] = elementArray[index].currNum[0]*elementArray[index].currNum[0];
	elementArray[index].currSq[1] = ((unsigned long long)2)*elementArray[index].currNum[0]*elementArray[index].currNum[1];
	elementArray[index].currSq[2] = elementArray[index].currNum[1]*elementArray[index].currNum[1];
	elementArray[index].currSq[3] = 0;

	for(int x = 0; x < 3; x++){
		elementArray[index].currSq[x + 1] += (elementArray[index].currSq[x]/divisor);
		elementArray[index].currSq[x] = elementArray[index].currSq[x]%divisor;
	}
	elementArray[index].currDigits += digits;
	elementArray[index].digitTocheck = ((elementArray[index].currSq[(elementArray[index].currDigits - 1)/divisorDigits])/multiTable[(elementArray[index].currDigits - 1)%divisorDigits])%10;
}

void ansFound(){
	// ansNotFound = false;
	std::vector < int > ans(n, 0);
	unsigned long long temp0 = elementArray[k - 1].currNum[0], temp1 = elementArray[k - 1].currNum[1];
	// std::cout << temp1 << " "  << temp0 << std::endl;
	for(int index = 0; index < 8 && index < n; index++){
		ans[index] = temp0%10;
		temp0 /= 10;
	}

	for(int index = 8; index < n; index++){
		ans[index] = temp1%10;
		temp1 /= 10;
	}

	for(int index = n - 1; index >= 0; index--){
		std::cout << ans[index];
	}
	std::cout << std::endl;
}

bool allDigitCheckFunction(){
	for(int index = elementArray[k - 1].currDigits + 1; index < 2*n - 2; index += 2){
		if(givenSquare[index] != ((elementArray[k - 1].currSq[index/divisorDigits])/multiTable[index%divisorDigits])%10){
			return false;
		}
	}
	return true;
}

void finalCheck(){
	int sqfd = givenSquare[givenSquare.size() - 1], fd = firstDigits[sqfd], sd;
		if(n%2 == 1){
			for(int index = 0; index < secondDigits[sqfd].size() && ansNotFound; index++){
				if(ansNotFound){
					sd = secondDigits[sqfd][index];
					getPrelim( k - 2, k - 1);
					addSquare( k - 1, fd*10 + sd, 0);
					if(allDigitCheckFunction()){
						ansFound();
					}
				}
			}
		}
		else{
			if(ansNotFound){
				getPrelim( k - 2, k - 1);
				addSquare( k - 1, fd, 0);
				if(allDigitCheckFunction()){
					ansFound();
				}
			}		
		}
}

void dfsModified( int kIndex)
{
	if(ansNotFound){
		if(kIndex < k - 2){
			for(int x = 0; x < 100 && ansNotFound; x++){
					getPrelim( kIndex, kIndex + 1);
					addSquare( kIndex + 1, x, 2);
					if(elementArray[kIndex + 1].digitTocheck == givenSquare[elementArray[kIndex + 1].currDigits - 1]){
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
			elementArray[0].currNum[0] = (unsigned long long)lastDigits[givenSquare[0]][index];
			elementArray[0].currDigits = 1;
			int sq = lastDigits[givenSquare[0]][index]*lastDigits[givenSquare[0]][index];
			elementArray[0].currSq[0] = (unsigned long long)sq;
			dfsModified(0);
		}
	}
}

void PrePrelims(){
	elementArray.resize(k);
	for(int index = 0; index < k; index++){
		elementArray[index].currNum.resize( 2, 0);
		elementArray[index].currSq.resize( 4, 0);
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
	givenSquare.resize( 2*n - 1, 0);
	for(int index = givenSquare.size() - 1; index >= 0; index = index - 2){
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