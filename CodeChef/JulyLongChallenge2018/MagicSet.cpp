#include <bits/stdc++.h>

using namespace std;

void auxFunction( int n, int divisor, std::vector < int > inps){
	std::vector < long > prevRow( divisor, 0), currRow( divisor, 0);
	long ans = 0, summ = 0;
	// std::cout << n << "         " << divisor <<"\n";
	// for(auto x : inps){
	// 	std::cout << x << " ";
	// }
	// std::cout << "\n\n\n\n";
	for(int index = 0; index < n; index++){
		summ += inps[index];
		for(int x = 0; x < divisor; x++){
			currRow[(inps[index] + x)%divisor] += prevRow[x];
			// cuulrrRow[x] += prevRow[x];
		}
		currRow[inps[index]%divisor]++;
		for(int x = 0; x < divisor; x++){
			prevRow[x] = currRow[x];
		}

		// for(auto x : prevRow){
		// 	std::cout << x << " ";
		// }
		// std::cout << "\n";
		// for(auto x : currRow){
		// 	std::cout << x << " ";
		// }
		// std::cout << "\n\n";
	}

	if(summ%divisor == 0){
		ans = -1;
	}

	ans += currRow[0];
	std::cout << ans << "\n";
}

int main(){
	int testcases = 0;
	std::cin >> testcases;

	while(testcases--){
		int n = 0, divisor = 0;
		std::cin >> n >> divisor;
		std::vector < int > inps( n, 0);
		for(int index = 0; index < n; index++){
			std::cin >> inps[index];
			inps[index] %= divisor;
		}

		auxFunction( n, divisor, inps);
	}

	return 0;
}