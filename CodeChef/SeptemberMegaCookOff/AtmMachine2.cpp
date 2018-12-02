#include <bits/stdc++.h>

using namespace std;
void solveFor(){
	int n, k;
	std::cin >> n >> k;
	// std::vector < int > inputArray( n, 0);
	int inputX = 0;
	for(int index = 0; index < n; index++){
		std::cin >> inputX;
		if(inputX <= k){
			std::cout << "1";
			k -= inputX;
		}
		else{
			std::cout << "0";
		}
	}
	std::cout << "\n";
}

int main(){
	int testCases = 0;
	std::cin >> testCases;
	while(testCases--){
		solveFor();
	}
	return 0;
}