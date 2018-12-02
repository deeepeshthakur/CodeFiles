#include <bits/stdc++.h>

using namespace std;
std::vector < std::vector < bool > > grid( 200, std::vector < bool >( 200, true));

void takeInput( int n, int m){
	for(int index = 0; index < n; index++){
		std::string temp{};
		std::cin >> temp;
		for(int y = 0; y < m; y++){
			if(temp[y] == '0'){
				grid[index][y] = false;
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	takeInput( n, m);
	std::vector < int > queriesArray( 40001, 0);
	queriesArray[0] = 1;
	queriesArray[1] = 1;
	std::vector < std::vector < std::vector < std::pair < int, int > > > > dpTable( 201, std::vector < std::vector < std::pair < int, int > > >( 200, std::vector < std::pair < int, int > >( 200, std::make_pair( 0, 0))));
	int limitSize = std::min( n, m);
	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			if(grid[x][y]){
				dpTable[1][x][y].first = 1;
				dpTable[1][x][y].second = 0;
			}
			else{
				dpTable[1][x][y].first = 0;
				dpTable[1][x][y].second = 1;
			}
		}
	}

	int a, b;
	for(int sqSize = 2; sqSize <= limitSize; sqSize++){
		int xLimit = n + 1 - sqSize;
		for(int x = 0; x < xLimit; x++){
			int yLimit = m + 1 - sqSize;
			for(int y = 0; y < yLimit; y++){
				if( sqSize%2 == 0){
					a = sqSize/2;
					b = sqSize/2;
					if(a%2 == 1){
						dpTable[sqSize][x][y].first = dpTable[a][x][y].first + dpTable[b][x + a][y].second + dpTable[b][x][y + a].second + dpTable[a][x + b][y + b].first;
						dpTable[sqSize][x][y].second = dpTable[a][x][y].second + dpTable[b][x + a][y].first + dpTable[b][x][y + a].first + dpTable[a][x + b][y + b].second;
						if(queriesArray[dpTable[sqSize][x][y].first] < sqSize){
							queriesArray[dpTable[sqSize][x][y].first] = sqSize;
						}
						if(queriesArray[dpTable[sqSize][x][y].second] < sqSize){
							queriesArray[dpTable[sqSize][x][y].second] = sqSize;
						}

					}
					else{
						dpTable[sqSize][x][y].first = dpTable[a][x][y].first + dpTable[b][x + a][y].first + dpTable[b][x][y + a].first + dpTable[a][x + b][y + b].first;
						dpTable[sqSize][x][y].second = dpTable[a][x][y].second + dpTable[b][x + a][y].second + dpTable[b][x][y + a].second + dpTable[a][x + b][y + b].second;
						if(queriesArray[dpTable[sqSize][x][y].first] < sqSize){
							queriesArray[dpTable[sqSize][x][y].first] = sqSize;
						}
						if(queriesArray[dpTable[sqSize][x][y].second] < sqSize){
							queriesArray[dpTable[sqSize][x][y].second] = sqSize;
						}
					}
				}
				else{
					a = (sqSize/2) + 1;
					b = sqSize/2;
					if(a%2 == 1){
						dpTable[sqSize][x][y].first = dpTable[a][x][y].first + dpTable[b][x + a][y].second + dpTable[b][x][y + a].second + dpTable[a][x + b][y + b].first - dpTable[1][x + b][y + b].first;
						dpTable[sqSize][x][y].second = dpTable[a][x][y].second + dpTable[b][x + a][y].first + dpTable[b][x][y + a].first + dpTable[a][x + b][y + b].second - dpTable[1][x + b][y + b].second;
						if(queriesArray[dpTable[sqSize][x][y].first] < sqSize){
							queriesArray[dpTable[sqSize][x][y].first] = sqSize;
						}
						if(queriesArray[dpTable[sqSize][x][y].second] < sqSize){
							queriesArray[dpTable[sqSize][x][y].second] = sqSize;
						}
					}
					else{
						dpTable[sqSize][x][y].first = dpTable[a][x][y].first + dpTable[b][x + a][y].first + dpTable[b][x][y + a].first + dpTable[a][x + b][y + b].first - dpTable[1][x + b][y + b].first;
						dpTable[sqSize][x][y].second = dpTable[a][x][y].second + dpTable[b][x + a][y].second + dpTable[b][x][y + a].second + dpTable[a][x + b][y + b].second - dpTable[1][x + b][y + b].second;
						if(queriesArray[dpTable[sqSize][x][y].first] < sqSize){
							queriesArray[dpTable[sqSize][x][y].first] = sqSize;
						}
						if(queriesArray[dpTable[sqSize][x][y].second] < sqSize){
							queriesArray[dpTable[sqSize][x][y].second] = sqSize;
						}
					}

				}
			}
		}
	}

	int testC = 0;
	std::cin >> testC;

	std::cout << std::endl;
	int currMax = 0;
	for(int index = 0; index < queriesArray.size(); index++){
		if(currMax < queriesArray[index]){
			currMax = queriesArray[index];
		}
		queriesArray[index] = currMax;
	}

	std::cout << std::endl;

	int cI = 0;
	while( testC--){
		std::cin >> cI;
		if(cI > 40000){
			cI = 40000;
		}
		std::cout << queriesArray[cI] << "\n";
	}
	return 0;
}