#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		std::vector < long long > capArray( n, 0);
		for(int index = 0; index < n; index++){
			std::cin >> capArray[index];
			if(index > 0){
				capArray[index] += capArray[index - 1];
			}
		}

		long long day = 0;
		long long p = capArray[0] + 1;
		while(p < n){
			day++;
			long long temp = p; 
			p += capArray[temp - 1];
		}
		std::cout << day + 1 << "\n";
	}
	return 0;
}