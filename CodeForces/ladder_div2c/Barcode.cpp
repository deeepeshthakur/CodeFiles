#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, m, lenMin, lenMax;
	std::cin >> m >> n >> lenMin >> lenMax;
	std::vector < std::string > grid( m);
	for(int index = 0; index < m; index++){
		std::cin >> grid[index];
	}

	std::vector < std::vector < int > > totalChanges( n, std::vector < int >( 2, 0));
	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			if(grid[y][x] == '.'){
				totalChanges[x][0]++;
			}
		}
		totalChanges[x][1] = m - totalChanges[x][0];
	}

	std::vector < std::vector < int > > dpTable( n, std::vector < int >( 2, 1000000));
	int intiLimit = std::min( lenMax, lenMin*2 - 1);
	for(int index = 0; index < lenMax && index < n; index++){
		dpTable[index][0] = totalChanges[index][0];
		dpTable[index][1] = totalChanges[index][1];
		if(index){
			dpTable[index][0] += dpTable[index - 1][0];
			dpTable[index][1] += dpTable[index - 1][1];
		}
	}

	for(int index =  lenMin*2 - 1; index < n; index++){
		int sum0 = 0, sum1 = 0;
		for(int i = index; i > index - lenMin; i--){
			sum0 += totalChanges[i][0];
			sum1 += totalChanges[i][1];
		}
		// sum0 += dpTable[index - lenMin][1];
		// sum1 += dpTable[index - lenMin][0];
		if(dpTable[index][0] > sum0 + dpTable[index - lenMin][1]){
			dpTable[index][0] = sum0 + dpTable[index - lenMin][1];
		}

		if(dpTable[index][1] > sum1 + dpTable[index - lenMin][0]){
			dpTable[index][1] = sum1 + dpTable[index - lenMin][0];
		}

		for(int i = index - lenMin; i > index - lenMax && i >= 0; i--){
			sum0 += totalChanges[i][0];
			sum1 += totalChanges[i][1];
			if(i > lenMin - 1){
				if(dpTable[index][0] > dpTable[i - 1][1] + sum0){
					dpTable[index][0] = dpTable[i - 1][1] + sum0;
				}

				if(dpTable[index][1] > dpTable[i - 1][0] + sum1){
					dpTable[index][1] = dpTable[i - 1][0] + sum1;
				}
			}
		}
	}
	
	int ans = std::min( dpTable[n - 1][0], dpTable[n - 1][1]);
	std::cout << ans << "\n";
	return 0;
}