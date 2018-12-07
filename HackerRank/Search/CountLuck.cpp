#include <bits/stdc++.h>

using namespace std;

int capN, capM;
bool pathNotFound = true;
std::vector < std::vector < int > > ansPath{};

bool validityCheck( int x, int y){
	if(x >= 0 && x < capN && y >=0 && y < capM){
		return true;
	}
	return false;
}

int getPaths( int x, int y, std::vector< string >& grid){
	int ans = 0;
	if(validityCheck( x - 1, y) && grid[x - 1][y] != 'X'){
		ans++;
	}
	if(validityCheck( x + 1, y) && grid[x + 1][y] != 'X'){
		ans++;
	}
	if(validityCheck( x, y - 1) && grid[x][y - 1] != 'X'){
		ans++;
	}
	if(validityCheck( x, y + 1) && grid[x][y + 1] != 'X'){
		ans++;
	}
	return ans;
}

void startDFS( int x1, int y1, int x2, int y2, std::vector < std::string >& grid, std::vector < std::vector < bool > >& gridSearchCheck){
	if(pathNotFound && validityCheck( x1, y1) && gridSearchCheck[x1][y1]){
		gridSearchCheck[x1][y1] = false;
		if( x1 == x2 && y1 == y2){
			pathNotFound = false;
		}
		if(pathNotFound){
			startDFS( x1 - 1, y1, x2, y2, grid, gridSearchCheck);
			startDFS( x1 + 1, y1, x2, y2, grid, gridSearchCheck);
			startDFS( x1, y1 - 1, x2, y2, grid, gridSearchCheck);
			startDFS( x1, y1 + 1, x2, y2, grid, gridSearchCheck);
		}

		if(!pathNotFound){
			ansPath.push_back( std::vector < int >{ x1, y1});
		}
	}
}

void solve(){
	int n, m;
	std::cin >> n >> m;
	capN = n, capM = m;
	std::vector < std::string > grid(n);
	std::vector < std::vector < bool > > gridSearchCheck( n, std::vector < bool > ( m, true));
	for(int index = 0; index < n; index++){
		std::cin >> grid[index];
	}

	std::vector < int > startPoint( 2, 0), endPoint( 2, 0);
	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			if(grid[x][y] == 'M'){
				startPoint[0] = x;
				startPoint[1] = y;
			}

			if(grid[x][y] == '*'){
				endPoint[0] = x;
				endPoint[1] = y;
			}

			if(grid[x][y] == 'X'){
				gridSearchCheck[x][y] = false;
			}
		}
	}

	startDFS( startPoint[0], startPoint[1], endPoint[0], endPoint[1], grid, gridSearchCheck);
	// for(int index = 0; index < ansPath.size(); index++){
	// 	std::cout << "(" << ansPath[index][0] << ", " << ansPath[index][1] << ") ";
	// }
	// std::cout << std::endl;
	int calcK = 0;
	if(getPaths( startPoint[0], startPoint[1], grid) != 1){
		calcK++;
	}

	for(int index = ansPath.size() - 2; index >= 0; index--){
		if(getPaths( ansPath[index][0], ansPath[index][1], grid) > 2)
				calcK++;
	}
	// std::cout << calcK << "\n";
	int inpK;
	std::cin >> inpK;
	// std::cout << inpK << " " << calcK << "  ";
	if(inpK == calcK){
		std::cout << "Impressed\n";
	}
	else{
		std::cout << "Oops!\n";
	}

	ansPath.clear();
	pathNotFound = true;
}

int main(){
	int testCases = 0;
	std::cin >> testCases;
	while(testCases--){
		solve();
	}
	return 0;
}