#include <bits/stdc++.h>

using namespace std;

int main(){
	int testCases = 0;
	std::cin >> testCases;
	while(testCases--){
		int n = 0;
		std::cin >> n;
		std::vector < bool > inputArray( n, false);
		int temp;
		for(int index = 0; index < n; index++){
			std::cin >> temp;
			if(temp >= 1 && temp <= n)
				{
					inputArray[temp - 1] = true;
				}
		}

		int count = 0;
		for(int index = 0; index < n; index++){
			if(inputArray[index] == false){
				count++;
			}
		}
		std::cout << count << "\n";
	}
	return 0;
}