#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;

long long nCr(int n, int r, std::vector < std::vector < long long > >& dpTable){
	if(n > -1 && r > -1 || r <= n){
		if(dpTable[n][r] != -1ll){
			return dpTable[n][r];
		}
		else{
			if(r == 0 || n == r){
				return 1ll;
			}

			return (nCr(n - 1, r, dpTable) + nCr(n - 1, r - 1, dpTable))%MOD;
		}
	}
	return 0ll;
}

long long f2(int l, int r, int x, std::vector < std::vector < long long > >& dpTable){
	return (MOD + nCr(r + 1, x + 1, dpTable) - nCr(l, x + 1, dpTable))%MOD;
}

void f(std::vector < std::vector < long long > >& dpTable){
	int n;
	std::cin >> n;
	std::vector < int > nArray(n, 0);
	for(int i = 0; i < n; i++){
		std::cin >> nArray[i];
	}

	std::sort(nArray.begin(), nArray.end());
	long long ans = 0;
	for(int i = 0; i < n; i++){
		int e = i;
		while(e + 1 < n && nArray[i] == nArray[e + 1]){
			e++;
		}

		int k = std::min(i, n - i - 1);
		for(int x = 0; x <= k; x++){
			ans += (nCr(i, x, dpTable)*f2(n - e - 1, n - i - 1, x, dpTable))%MOD;
			ans %= MOD;
		}
	}

	std::cout << ans%MOD << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::vector < std::vector < long long > > dpTable(1001, std::vector < long long >(1001, -1ll));
	for(int n = 0; n < 1001; n++){
		for(int r = 0; r < 1001; r++){
			dpTable[n][r] = nCr(n, r, dpTable)%MOD;
		}
	}

	int t;
	std::cin >> t;
	while(t--){
		f(dpTable);
	}	
	return 0;
}