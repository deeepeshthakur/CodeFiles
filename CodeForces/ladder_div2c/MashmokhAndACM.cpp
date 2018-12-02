#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector < std::vector < long long > > dpTable( n, std::vector < long long >( k, 0ll));
	for(int index = 0; index < n; index++){
		dpTable[index][k - 1] = 1ll;
	}
	for(int y = k - 2; y >= 0; y--){
		for(int x = 0; x < n; x++){
			int i = 1;
			while((x + 1)*i <= n){
				dpTable[x][y] += dpTable[(x + 1)*i - 1][y + 1];
				dpTable[x][y] %= 1000000007ll;
				i++;
			}
		}
	}

	long long ans = 0;
	for(int index = 0; index < n; index++){
		ans += dpTable[index][0];
	}
	ans %= 1000000007;
	std::cout << ans << "\n";
	return 0;
}