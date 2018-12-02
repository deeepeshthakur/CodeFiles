#include <bits/stdc++.h>

using namespace std;
int n, m;
std::vector < std::string > maze;
std::vector < std::vector < bool > > checkArray;
bool checkValidity( int x, int y){
	if(x > -1 && x < n && y > -1 && y < m){
		return true;
	}
	return false;
}

void dfsFun( int x, int y, int& k){
	checkArray[x][y] = false;
	if(checkValidity( x, y + 1) && checkArray[x][y + 1]){
		dfsFun( x, y + 1, k);
	}
	if(checkValidity( x, y - 1) && checkArray[x][y - 1]){
		dfsFun( x, y - 1, k);
	}
	if(checkValidity( x - 1, y) && checkArray[x - 1][y]){
		dfsFun( x - 1, y, k);
	}
	if(checkValidity( x + 1, y) && checkArray[x + 1][y]){
		dfsFun( x + 1, y, k);
	}

	if(k > 0){
		maze[x][y] = 'X';
		k--;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	int k;
	std::cin >> n >> m >> k;
	maze.resize( n);
	checkArray.resize( n, std::vector < bool >( m, true));
	for(int index = 0; index < n; index++){
		std::cin >> maze[index];
	}
	bool isStart = true;
	int xStart = 0, yStart = 0;
	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			if(maze[x][y] == '#'){
				checkArray[x][y] = false;
			}
			else{
				if(isStart){
					isStart = false;
					xStart = x;
					yStart = y;
				}
			}
		}
	}

	dfsFun( xStart, yStart, k);

	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			std::cout << maze[x][y];
		}
		std::cout << "\n";
	}

	return 0;
}