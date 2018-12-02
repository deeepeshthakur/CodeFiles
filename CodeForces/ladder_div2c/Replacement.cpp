#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector < int > inputN( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> inputN[index];
	}
	std::sort( inputN.begin(), inputN.end());
	if(inputN[n - 1] != 1){
		inputN[n - 1] = 1;
	}
	else{
		inputN[n - 1] = 2;
	}

	std::sort( inputN.begin(), inputN.end());
	for(int index = 0; index < n; index++){
		std::cout << inputN[index] << " ";
	}
	std::cout << "\n";
	return 0;
}