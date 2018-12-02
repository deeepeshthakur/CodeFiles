#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector < int > seq( n + 1, 0);
	for(int index = 2; index <= n; index++){
		std::cin >> seq[index];
	}

	std::vector < int > pathR(1, n);
	int k = n;
	while(k > 1){
		pathR.push_back( seq[k]);
		k = seq[k];
	}

	for(int index = pathR.size() - 1; index >= 0; index--){
		std::cout << pathR[index];
		if(index){
			std::cout << " ";
		}
		else{
			std::cout << "\n";
		}
	}
	return 0;
}