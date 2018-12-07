#include <bits/stdc++.h>

using namespace std;
unsigned long long divisor = 100000000;
std::vector < unsigned long long > multip( std::vector < unsigned long long >& currNum, int strIndex, int lstIndex){
	std::vector < unsigned long long > ans(lstIndex - strIndex + 1, 0);
	int mid = strIndex + lstIndex;
	mid /= 2;
	for(int x = strIndex; x <= mid; x++){
		for(int y = mid + 1; y <= lstIndex; y++){
			ans[x - strIndex + y - mid - 1] += (currNum[x]*currNum[y]);
		}
	}

	for(int x = 0; x < ans.size() - 1; x++){
		ans[x + 1] += (ans[x]/divisor);
		ans[x] %= divisor;
	}

	while(ans[ans.size() - 1] > divisor){
			ans.push_back(ans[ans.size() - 1]/divisor);
			ans[ans.size() - 2]%divisor;
	}

	return ans;
}

std::vector < unsigned long long > squareIT( std::vector < unsigned long long >& currNum, int strIndex, int lstIndex){
	std::vector < unsigned long long > ans{};
	if(strIndex == lstIndex){
		unsigned long long temp = currNum[strIndex]*currNum[strIndex];
		while(temp){
			ans.push_back(temp%divisor);
			temp /= divisor;
		}
	}
	else{
		int mid = (strIndex + lstIndex)/2;
		std::vector < unsigned long long  > ans1{}, ans2{}, ans3{};
		ans1 = squareIT( currNum, strIndex, mid);
		ans2 = squareIT( currNum, mid + 1, lstIndex);
		ans3 = multip( currNum, strIndex, lstIndex);
		ans.resize(ans2.size() + (2*(mid - strIndex + 1)), 0);

		for(int x = 0; x < ans1.size(); x++){
			ans[x] += ans1[x];
		}

		for(int x = 0; x < ans2.size(); x++){
			ans[x + 2*(mid - strIndex + 1)] += ans2[x];
		}

		for(int x = 0; x < ans3.size(); x++){
			ans[x + mid - strIndex + 1] += (ans3[x] + ans3[x]);
		}

		for(int x = 0; x < ans.size() - 1; x++){
			ans[x + 1] += (ans[x]/divisor);
			ans[x] %= divisor;
		}

		while(ans[ans.size() - 1] > divisor){
			ans.push_back(ans[ans.size() - 1]/divisor);
			ans[ans.size() - 2]%divisor;
		}

	}
	return ans;
}

void squareNum( std::vector < std::vector < unsigned long long > >& numbers, std::vector < std::vector < unsigned long long > >& squares, int index){
	std::vector < unsigned long long > sq = squareIT( numbers[index], 0, numbers[index].size() - 1);
	squares[index].resize( sq.size());
	for(int x = 0; x < sq.size(); x++){
		squares[index][x] = sq[x];
	}
}

void calcNext( std::vector < std::vector < unsigned long long > >& numbers, std::vector < std::vector < unsigned long long > >& squares, int index){
	numbers[index].clear();
	numbers[index].resize( squares[index - 1].size(), 0);
	for(int x = 0; x < numbers[index].size(); x++){
		if(x < numbers[index - 2].size()){
			numbers[index][x] += numbers[index - 2][x];
		}

		numbers[index][x] += squares[index - 1][x];
	}

	for(int x = 0; x < numbers[index].size() - 1; x++){
		numbers[index][x + 1] += numbers[index][x]/divisor;
		numbers[index][x] = numbers[index][x]%divisor;
	}

	while(numbers[index][numbers[index].size() - 1] >= divisor){
		numbers[index].push_back(numbers[index][numbers[index].size() - 1]/divisor);
		numbers[index][numbers[index][numbers[index].size() - 2]] %= divisor;
	}
}

void toPrint( unsigned long long x){
	unsigned long long temp = 10;
	// if(x < divisor/ temp){
	// 	std::cout << "     ";
	// }
	while(x < divisor/temp){
		std::cout << "0";
		temp *= (unsigned long long)10;
	}
	std::cout << x;
}

void furtherCalc( int n, unsigned long long sixthTerm, unsigned long long senventhTerm){
	std::vector < std::vector < unsigned long long > > numbers( n), squares( n);
	while( sixthTerm){
		numbers[0].push_back(sixthTerm%divisor);
		sixthTerm /= divisor;
	}

	while( senventhTerm){
		numbers[1].push_back(senventhTerm%divisor);
		senventhTerm /= divisor;
	}

	squareNum( numbers, squares, 0);
	squareNum( numbers, squares, 1);

	for(int index = 2; index < n - 1; index++){
		calcNext( numbers, squares, index);
		squareNum( numbers, squares, index);
	}

	calcNext(numbers, squares, n - 1);
	std::cout << numbers[n - 1][numbers[n - 1].size() - 1];
	for(int index = numbers[n - 1].size() - 2; index >= 0; index--){
		toPrint( numbers[n - 1][index]);
	}
	std::cout << std::endl;
}

void basicCalc( std::vector < unsigned long long >& uptoSeven){
	for(int index = 2; index < 7; index++){
		uptoSeven[index] = uptoSeven[index - 2] + (uptoSeven[index - 1]*uptoSeven[index - 1]);
	}
}

int main(){
	int aOne = 0, aTwo = 0, n = 0;
	std::cin >> aOne >> aTwo >> n;
	std::vector < unsigned long long > uptoSeven( 7, 0);
	uptoSeven[0] = aOne;
	uptoSeven[1] = aTwo;
	basicCalc( uptoSeven);

	if(n <= 7){
		std:cout << uptoSeven[n - 1] << std::endl;
	}
	else{
		furtherCalc( n - 5, uptoSeven[5], uptoSeven[6]);
	}	 
	return 0;
}