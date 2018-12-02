#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	std::string fp{};
	std::cin >> n;
	std::cin >> fp;
	std::vector < std::string > inps( n);
	for(int index = 0; index < n; index++){
		std::cin >> inps[index];
	}

	int e = 0, u = 0;
	for(int index = 0; index < n; index++){
		char temp = inps[index][0];
		for(int x = 0; x < inps[index].length(); x++){
			if(inps[index][x] == '0'){
				if(x + 1 < inps[index].length()){
					if(inps[index][x + 1] == '1')
						e++;
				}
				else{
					e++;
				}
			}

		}
		for(int x = 0; x < inps[index].length(); x++){
			if(inps[index][x] == '1'){
				if(x + 1 < inps[index].length()){
					if(inps[index][x + 1] == '0')
						u++;
				}
				else{
					u++;
				}
			}
		}
		
	}
	// std::cout << e << " " << u << "\n";

	if(e > u){
		std::cout << "Dum\n";
	}

	if(u > e){
		std::cout << "Dee\n";
	}

	if(u == e){
		if(fp == "Dee"){
			std::cout << "Dee\n";
		}
		else{
			std::cout << "Dum\n";
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int testC;
	std::cin >> testC;
	for(int index = 0; index < testC; index++){
		solve();
	}
	return 0;
}