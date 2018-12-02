#include <bits/stdc++.h>

using namespace std;

bool possibleCheck( int x, int y, std::vector < std::vector < bool > >& grid){
	if(x - 1 >= 0 && y - 1 >= 0 && x + 1 < grid.size() && y + 1 < grid[0].size()){
		return true;
	}
	return false;
}

bool neccCheck( int x, int y, std::vector < std::vector < bool > >& grid){
	bool flag = true;

	for(int xx = -1; xx <= 1 && flag; xx++){
		for(int yy = -1; yy <= 1 && flag; yy++){
			if(xx != 0 || yy != 0){
				if(!grid[x + xx][y + yy]){
					flag = false;
				}
			}
		}
	}

	if(flag){
		return true;
	}

	return false;
}

int main(){
	std::ios::sync_with_stdio(false);
	int m, n;
	std::cin >> n >> m;
	std::vector < std::vector < bool > > grid( n, std::vector < bool > ( m, false)), secondaryGrid( n, std::vector < bool > ( m, false));
	for(int index = 0; index < n; index++){
		std::string temp{};
		std::cin >> temp;
		for(int y = 0; y < m; y++){
			if( temp[y] == '#'){
				grid[index][y] = true;
			}
		}
	}


	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			if(possibleCheck( x, y, grid) && neccCheck( x, y, grid)){
				for(int xx = -1; xx <= 1; xx++){
					for(int yy = -1; yy <= 1; yy++){
						if(xx != 0 || yy != 0){
							secondaryGrid[x + xx][y + yy] = true;
						}
					}
				}
			}
		}
	}

	bool flag = true;
	for(int x = 0; x < n && flag; x++){
		for(int y = 0; y < m && flag; y++){
			if(grid[x][y] != secondaryGrid[x][y]){
				flag = false;
			}
		}
	}

	if(flag){
		std::cout << "YES\n";
	}
	else{
		std::cout << "NO\n";
	}

	return 0;
}