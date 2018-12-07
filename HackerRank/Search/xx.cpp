#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	std::cin >> n;
	std::vector < int > temp(n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> temp[index];
	}

	std::cout << n << "\n";
	for(int index = 0; index < n; index++){
		std::cout << temp[index] << "\n";
	}
	return 0;
}