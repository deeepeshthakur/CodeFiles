#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector < int > req( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> req[index];
		if(index > 0){
			req[index] += req[index - 1];
		}
	}

	int maxInterval = 0;
	int reqMax = 0;
	for(int x = 0; x < n; x++){
		for(int y = x; y < n; y++){
			reqMax = req[y];
			if(x > 0){
				reqMax -= req[x - 1];
			}
			if(reqMax > 100*(y - x + 1)){
				if(maxInterval < y - x + 1){
					maxInterval = y - x + 1;
				}
			}
		}
	}
	std::cout << maxInterval << "\n";
	return 0;
}