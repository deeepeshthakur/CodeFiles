#include <bits/stdc++.h>

using namespace std;
int nMax, mMax;
bool validityCheck( int x, int y){
	if( x > -1 && y > -1 && x < nMax && y < mMax){
		return true;
	}
	return false;
}

void solve(){
	int n, m;
	std::cin >> n >> m;
	nMax = n;
	mMax = m;
	std::vector < std::vector < bool > > grid( n, std::vector < bool >( m, false));
	for(int x = 0; x < n; x++){
		std::string inps{};
		std::cin >> inps;
		for(int y = 0; y < m; y++){
			if(inps[y] == '1'){
				grid[x][y] = true;
			}
		}
	}

	// for(auto x : grid){
	// 	for(auto y : x){
	// 		std::cout << y << " ";
	// 	}
	// 	std::cout << "\n";
	// }

	std::vector < int > finalAns( n + m - 1, 0);
	std::vector < std::vector < std::vector < int > > > dpTable( n, std::vector < std::vector < int > >( m, std::vector < int >( n + m - 1, 0)));
	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			if(/*grid[x][y] && */validityCheck( x , y - 1) && grid[x][y - 1]){
				dpTable[x][y][1]++;
			}

			if(/*grid[x][y] && */validityCheck( x - 1, y) && grid[x - 1][y]){
				dpTable[x][y][1]++;
			}

			if(validityCheck( x, y - 1)){
				for(int index = 0; index < n + m - 2; index++){
					dpTable[x][y][index + 1] += dpTable[x][y - 1][index];
				}
			}

			if(validityCheck( x - 1, y)){
				for(int index = 0; index < n + m - 2; index++){
					dpTable[x][y][index + 1] += dpTable[x - 1][y][index];
				}
			}

			if(validityCheck( x - 1, y - 1)){
				for(int index = 0; index < n + m - 3; index++){
					dpTable[x][y][index + 2] -= dpTable[x - 1][y - 1][index];
				}
			}

			if(grid[x][y])
			for(int index = 0; index < finalAns.size(); index++){
				finalAns[index] += dpTable[x][y][index];
			}
		}
	}

	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			for(int index = 0; index < n + m - 1; index++){
				dpTable[x][y][index] = 0;
			}
		}
	}

	for(int x = 0; x < n; x++){
		for(int y = m - 1; y >= 0; y--){
			if(/*grid[x][y] &&*/ validityCheck( x , y + 1) && grid[x][y + 1]){
				dpTable[x][y][1]++;
			}

			if(/*grid[x][y] &&*/ validityCheck( x - 1, y) && grid[x - 1][y]){
				dpTable[x][y][1]++;
			}

			if(validityCheck( x, y + 1)){
				for(int index = 0; index < n + m - 2; index++){
					dpTable[x][y][index + 1] += dpTable[x][y + 1][index];
				}
			}

			if(validityCheck( x - 1, y)){
				for(int index = 0; index < n + m - 2; index++){
					dpTable[x][y][index + 1] += dpTable[x - 1][y][index];
				}
			}

			if(validityCheck( x - 1, y + 1)){
				for(int index = 0; index < n + m - 3; index++){
					dpTable[x][y][index + 2] -= dpTable[x - 1][y + 1][index];
				}
			}

			if(grid[x][y])
			for(int index = 0; index < finalAns.size(); index++){
				finalAns[index] += dpTable[x][y][index];
			}
		}
	}

	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			for(int index = 0; index < n + m - 1; index++){
				dpTable[x][y][index] = 0;
			}
		}
	}

	for(int x = n - 1; x >= 0; x--){
		for(int y = 0; y < m; y++){
			if(/*grid[x][y] &&*/ validityCheck( x , y - 1) && grid[x][y - 1]){
				dpTable[x][y][1]++;
			}

			if(/*grid[x][y] &&*/ validityCheck( x + 1, y) && grid[x + 1][y]){
				dpTable[x][y][1]++;
			}

			if(validityCheck( x, y - 1)){
				for(int index = 0; index < n + m - 2; index++){
					dpTable[x][y][index + 1] += dpTable[x][y - 1][index];
				}
			}

			if(validityCheck( x + 1, y)){
				for(int index = 0; index < n + m - 2; index++){
					dpTable[x][y][index + 1] += dpTable[x + 1][y][index];
				}
			}

			if(validityCheck( x + 1, y - 1)){
				for(int index = 0; index < n + m - 3; index++){
					dpTable[x][y][index + 2] -= dpTable[x + 1][y - 1][index];
				}
			}

			if(grid[x][y])
			for(int index = 0; index < finalAns.size(); index++){
				finalAns[index] += dpTable[x][y][index];
			}
		}
	}

	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			for(int index = 0; index < n + m - 1; index++){
				dpTable[x][y][index] = 0;
			}
		}
	}

	for(int x = n - 1; x >= 0; x--){
		for(int y = m - 1; y >= 0; y--){
			if(/*grid[x][y] &&*/ validityCheck( x , y + 1) && grid[x][y + 1]){
				dpTable[x][y][1]++;
			}

			if(/*grid[x][y] &&*/ validityCheck( x + 1, y) && grid[x + 1][y]){
				dpTable[x][y][1]++;
			}

			if(validityCheck( x, y + 1)){
				for(int index = 0; index < n + m - 2; index++){
					dpTable[x][y][index + 1] += dpTable[x][y + 1][index];
				}
			}

			if(validityCheck( x + 1, y)){
				for(int index = 0; index < n + m - 2; index++){
					dpTable[x][y][index + 1] += dpTable[x + 1][y][index];
				}
			}

			if(validityCheck( x + 1, y + 1)){
				for(int index = 0; index < n + m - 3; index++){
					dpTable[x][y][index + 2] -= dpTable[x + 1][y + 1][index];
				}
			}

			if(grid[x][y])
			for(int index = 0; index < finalAns.size(); index++){
				finalAns[index] += dpTable[x][y][index];
			}
		}
	}

	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			for(int index = 0; index < n + m - 1; index++){
				dpTable[x][y][index] = 0;
			}
		}
	}

	for(int index = 1; index < finalAns.size(); index++){
		std::cout << finalAns[index]/4 << " ";
	}
	std::cout << "\n";

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int test;
	std::cin >> test;
	while( test--){
		solve();
	}
	return 0;
}