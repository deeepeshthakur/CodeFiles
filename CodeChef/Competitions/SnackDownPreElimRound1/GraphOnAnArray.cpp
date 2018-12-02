
#include <bits/stdc++.h>

using namespace std;

std::vector < std::vector < bool > > gcdTable( 51, std::vector < bool >( 51, false));

void solve(){
	int n;
	std::cin >> n;
	std::vector < int > inpA( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> inpA[index];
	}

	std::vector < bool > discoverArray( n, false);
	// std::vector < std::vector < bool > > pathMartix( n, std::vector < bool >( n, false));
	std::queue < int > discoverQ{};
	discoverQ.push(0);
	discoverArray[0] = true;
	while(!discoverQ.empty()){
		int curr = inpA[discoverQ.front()];
		discoverQ.pop();
		for(int index = 0; index < n; index++){
			if(gcdTable[curr][inpA[index]]){
				if(!discoverArray[index]){
					discoverArray[index] = true;
					discoverQ.push( index);
				}
			}
		}
	}

	int ans = 0;
	for(int index = 0; index < n; index++){
		if(!discoverArray[index]){
			ans = 1;
		}
	}

	if(ans == 1){
		inpA[0] = (inpA[0] != 47 ? 47 : 37);
	}
	std::cout << ans << "\n";
	for(int index = 0; index < n; index++){
		std::cout << inpA[index] << " ";
	}
	std::cout << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	for(int x = 2; x < 51; x++){
		for(int y = x; y < 51; y++){
			if(__gcd( x, y) == 1){
				gcdTable[x][y] = true;
				gcdTable[y][x] = true;
			}
		}
	}
	int test;
	std::cin >> test;
	while( test--){
		solve();
	}
	return 0;
}