#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector < std::vector < int > > timeTable( n, std::vector < int >( 2, 0));
	for(int index = 0; index < n; index++){
		std::cin >> timeTable[index][0] >> timeTable[index][1];
	}

	int currD = 0;
	for(int index = 0; index < n; index++){
		int k = 0;
		// std::cout << ((currD - timeTable[index][0])/timeTable[index][1]) << "\n";
		k = std::max( 0, (int)((1.0*currD - timeTable[index][0])/timeTable[index][1] + 1));
		currD = timeTable[index][0] + k*timeTable[index][1];
		// std::cout << currD << "\n";
	}

	std::cout << currD << "\n";
	return 0;
}