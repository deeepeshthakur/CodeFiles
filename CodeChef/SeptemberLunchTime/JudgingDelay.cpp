#include <bits/stdc++.h>

using namespace std;

int main(){
	int testCases;
	std::cin >> testCases;
	while(testCases--){
		int n;
		int ans = 0;
		std::cin >> n;
		int subTime, judTime;
		for(int index = 0; index < n; index++){
			std::cin >> subTime >> judTime;
			if(judTime - subTime > 5){
				ans++;
			}
		}

		std::cout << ans << "\n";
	}
	return 0;
}