#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector < int > a( n, 0), b( n, 0), counter( n, 0);
	int currBooks = 0;
	for(int index = 0; index < n; index++){
		int temp;
		std::cin >> temp;
		counter[temp - 1] = index + 1;
	}

	for(int index = 0; index < n; index++){
		int temp = 0;
		std::cin >> temp;
		std::cout << std::max( 0, counter[temp - 1] - currBooks) << " ";
		currBooks = std::max( counter[temp - 1], currBooks);
	}
	std::cout << "\n";

	return 0;
}