#include <bits/stdc++.h>

using namespace std;
long long countR = 0;
int n, m;
std::vector < std::string > grid;
bool validityCheck( int x, int y){
	if(x > -1 && x < n && y > -1 && y < m){
		return true;
	}
	return false;
}

struct node{
	int index, right, left;
	node( int i, int r, int l){
		index = i;
		right = r;
		left = l;
	}
};

void discoverFunction( std::queue < node >& discoveryQueue, std::vector < std::vector < bool > >& gridCheck, std::vector < std::vector < node > >& gridNodes){
	node curr = discoveryQueue.front();
	int x = curr.index/2000;
	int y = curr.index%2000;
	if(gridCheck[x][y]){
		countR++;
		gridCheck[x][y] = false;
	}

	if(curr.left > gridNodes[x][y].left || curr.right > gridNodes[x][y].right){
		gridNodes[x][y].left = curr.left;
		gridNodes[x][y].right = curr.right;

		if( validityCheck( x + 1, y) && grid[x + 1][y] == '.'){
			discoveryQueue.push({(x + 1)*2000 + y, curr.right, curr.left});
		}
		if(validityCheck( x - 1, y) && grid[x - 1][y] == '.'){
			discoveryQueue.push({(x - 1)*2000 + y, curr.right, curr.left});
		}
		if(validityCheck( x, y - 1) && grid[x][y - 1] == '.' && curr.left > 0){
			discoveryQueue.push({x*2000 + y - 1, curr.right, curr.left - 1});
		}
		if(validityCheck( x, y + 1) && grid[x][y + 1] == '.' && curr.right > 0){
			discoveryQueue.push({x*2000 + y + 1, curr.right - 1, curr.left});
		}
	}
	else{
		return;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	int r, c;
	int right, left;
	std::cin >> n >> m >> r >> c >> left >> right;
	grid.resize( n);
	for( int index = 0; index < n; index++){
		std::cin >> grid[index];
	}
	std::vector < std::vector < bool > > gridCheck( n, std::vector < bool >( m, true));
	std::vector < std::vector < node > > gridNodes( n, std::vector < node >(m, { 0, -1, 1}));

	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			gridNodes[x][y].index = x*2000 + y;
		}
	}

	node temp( (r - 1)*2000 + c - 1, right, left);
	std::queue< node > discoveryQueue{};\
	discoveryQueue.push( temp);
	while(!discoveryQueue.empty()){
		discoverFunction(discoveryQueue, gridCheck, gridNodes);
		discoveryQueue.pop();
	}

	std::cout << countR << "\n";
	return 0;
}
