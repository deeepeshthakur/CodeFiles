#include <bits/stdc++.h>

using namespace std;
std::vector < int > powersOfTwo{ 1};
std::vector < int > validNumbers{};

void preProcess(){
	for(int index = 1; index < 31; index++){
		powersOfTwo.push_back(powersOfTwo[index - 1]*2);
	}
	
	for(int x = 0; x < powersOfTwo.size(); x++){
		for(int y = x + 1; y < powersOfTwo.size(); y++){
			validNumbers.push_back(powersOfTwo[x] + powersOfTwo[y]);
		}
	}
	std::sort( validNumbers.begin(), validNumbers.end());
}


void solve(){
	int number = 0;
	std::cin >> number;
	if(number <= 3){
		std::cout << 3 - number << "\n";
	}
	else{
		int bigIndex = 0, smallIndex = 0;
		bigIndex = std::lower_bound( validNumbers.begin(), validNumbers.end(), number) - validNumbers.begin();
		smallIndex = bigIndex - 1;
		int ans = validNumbers[bigIndex] - number;
		if(ans > (number - validNumbers[smallIndex])){
			ans = number - validNumbers[smallIndex];
		}
		std::cout << ans << "\n";
	}
}

int main(){

	int testCases;
	std::cin >> testCases;
	preProcess();
	while(testCases--){
		solve();
	}
	return 0;
}