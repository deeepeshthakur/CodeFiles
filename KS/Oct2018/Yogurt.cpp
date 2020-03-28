#include <bits/stdc++.h>

using namespace std;

int solveFor(int n, int k){
	std::vector < int > expiryArray( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> expiryArray[index];
	}

	std::sort( expiryArray.begin(), expiryArray.end());
	bool flag = true;
	int currDay = 1, ans = 0, currIndex = 0;
	while(flag){
		int currDayYogurtCount = 0;
		while( currDayYogurtCount < k && currIndex < n){
			if( expiryArray[currIndex] >= currDay){
				ans++;
				currDayYogurtCount++;
				currIndex++;
			}
			else{
				currIndex++;
			}			
		}

		currDay++;
		if(currIndex >= n){
			flag = false;
		}
	}
	return ans;
}

int main(){
	int testCases;
	std::cin >> testCases;
	for(int index = 0; index < testCases; index++){
		int n, k;
		std::cin >> n >> k;
		std::cout << "Case #" << index + 1 << ": " << solveFor( n, k) << "\n";
	}
	return 0;
}