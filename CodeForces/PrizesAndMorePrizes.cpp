#include <bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector < long long > inpA(n, 0);
	for(int i = 0; i < n; i++){
		std::cin >> inpA[i];
	}

	std::vector < std::vector < long long > > costs(5, std::vector < long long >(2, 0ll));
	for(int i = 0; i < 5; i++){
		std::cin >> costs[i][0];
	}

	long long currP = 0;
	for(int i = 0; i < n; i++){
		currP += inpA[i];
		for(int y = 4; y > -1; y--){
			if(currP >= costs[y][0]){
				costs[y][1] += currP/costs[y][0];
				currP %= costs[y][0];
			}
		}
	}

	for(int i = 0; i < 5; i++){
		std::cout << costs[i][1] << " ";
	}
	std::cout << "\n";
	std::cout << currP << "\n";
	
	return 0;
}