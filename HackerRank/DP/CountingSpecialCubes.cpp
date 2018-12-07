#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int maxReturn(int x, int y, int z, std::vector < std::vector < std::vector < int > > >& cellIntegers){
	int ans = cellIntegers[x][y][z];
	if(ans < cellIntegers[x][y][z + 1]){
		ans = cellIntegers[x][y][z + 1];
	}

	if(ans < cellIntegers[x][y + 1][z]){
		ans = cellIntegers[x][y + 1][z];
	}

	if(ans < cellIntegers[x][y + 1][z + 1]){
		ans = cellIntegers[x][y + 1][z + 1];
	}

	if(ans < cellIntegers[x + 1][y][z]){
		ans = cellIntegers[x + 1][y][z];
	}

	if(ans < cellIntegers[x + 1][y][z + 1]){
		ans = cellIntegers[x + 1][y][z + 1];
	}

	if(ans < cellIntegers[x + 1][y + 1][z]){
		ans = cellIntegers[x + 1][y + 1][z];
	}

	if(ans < cellIntegers[x + 1][y + 1][z + 1]){
		ans = cellIntegers[x + 1][y + 1][z + 1];
	}

	return ans;
}

void solve(){
	int n = 0;
	std::cin >> n;
	std::vector < int > ansArray(n, 0);
	std::vector < std::vector < std::vector < int > > > cellIntegers( n, std::vector < std::vector < int > >( n, std::vector < int >(n, 0))), 
														dpArray( n, std::vector < std::vector < int > >( n, std::vector < int >(n, 0)));

	for(int x = 0; x < n; x++){
		for(int y = 0; y < n; y++){
			for(int z = 0; z < n; z++){
				std::cin >> cellIntegers[x][y][z];
				if(cellIntegers[x][y][z] == 1){
					ansArray[0]++;
				}
			}
		}
	}

	for(int index = 2; index <= n; index++){
		for(int x = 0; x <= n - index; x++){
			for(int y = 0; y <= n - index; y++){
				for(int z = 0; z <= n - index; z++){
					dpArray[x][y][z] = maxReturn( x, y, z, cellIntegers);
				}
			}
		}

		for(int x = 0; x <= n - index; x++){
			for(int y = 0; y <= n - index; y++){
				for(int z = 0; z <= n -index; z++){
					cellIntegers[x][y][z] = dpArray[x][y][z];
					if(cellIntegers[x][y][z] == index){
						ansArray[index - 1]++;
					}
				}
			}
		}
	}

	for(int index = 0; index < ansArray.size(); index++){
		std::cout << ansArray[index] << " ";
	}
	std::cout << endl;
}

int main(){
	int testCases = 0;
	std::cin >> testCases;
	while(testCases--){
		solve();
	}
	return 0;
}
