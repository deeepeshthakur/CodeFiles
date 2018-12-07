#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	long long limitF = 4ll*100000000ll*100000000ll;
	std::vector < long long > fibonacci( 2, 0);
	fibonacci[1] = 1;
	int currNum = 2;
	while(fibonacci[ currNum - 1] + fibonacci[currNum - 2] <= limitF){
		fibonacci.push_back( fibonacci[ currNum - 1] + fibonacci[currNum - 2]);
		currNum++;
	}
	std::vector < long long > evenFibonacci{};
	for(int index = 0; index < fibonacci.size(); index++){
		if(fibonacci[index]%2ll == 0){
			evenFibonacci.push_back( fibonacci[index]);
		}
	}

	std::vector < long long > sumEven( evenFibonacci.size(), 0ll);
	for(int index = 0; index < evenFibonacci.size(); index++){
		sumEven[index] += evenFibonacci[index];
		if(index){
			sumEven[index] += sumEven[index - 1];
		}
	}


	int test = 0;
	std::cin >> test;
	while( test--){
		long long n;
		std::cin >> n;
		int currIndex = 0;
		while(currIndex + 1 < evenFibonacci.size() && evenFibonacci[currIndex + 1] <= n){
			currIndex++;
		}
		std::cout << sumEven[currIndex] << "\n";
	}
	return 0;
}