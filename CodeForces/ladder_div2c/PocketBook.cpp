#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	std::cin >> n >> m;
	std::vector < std::string > stringsArray( n);
	for(int index = 0; index < n; index++){
		std::cin >> stringsArray[index];
	}

	long long ans = 1, divi = 1000000007;
	for(int y = 0; y < m; y++){
		std::vector < bool > checkArray( 26, false);
		for(int x = 0; x < n; x++){
			checkArray[ stringsArray[x][y] - 'A'] = true;
		}

		long long multi = 0;
		for(int index = 0; index < 26; index++){
			if(checkArray[index]){
				multi++;
			}
		}

		ans *= multi;
		ans %= divi;
	}

	std::cout << ans << "\n";
	return 0;
}