#include<bits/stdc++.h>
#define iint int
#define pll std::pair<iint,iint>
#define rep(i,a,b) for(iint i=(iint)a;i<(iint)b;i++)
#define per(i,a,b) for(iint i=(iint)a;i>(iint)b;i--)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define full(a) a.begin(),a.end()
#define rfull(a) a.rbegin(),a.rend()

using namespace std;
const double pi=acos(-1.0);
const double pii=2*pi;
const double eps=1e-6;
const double MOD=1e9+7;

int f1(std::string& str, int ind, int n){
	if(ind + 2 >= n){
		return 0;
	}

	if(str[ind] == str[ind+1] || str[ind + 1] == str[ind + 2] || str[ind] == str[ind + 2]){
		return 1;
	}

	return 0;
}

void solve(){
	int n, q;
	std::cin >> n >> q;
	std::string str;
	std::cin >> str;
	std::vector<int> countr(n,0);
	for(int i = 0; i < n; i++){
		countr[i] = f1(str, i, n);
	}

	for(int i = 1; i < n; i++){
		countr[i] += countr[i-1];
	}

	for(int i = 0; i < q; i++){
		int l,r;
		std::cin >> l >> r;
		l--;
		r--;
		if(r - l + 1 >= 3){
			int tmp = l > 0 ? countr[l-1] : 0;
			tmp = countr[r-2] - tmp;
			if(tmp > 0){
				std::cout << "YES" << std::endl;
			}
			else{
				std::cout << "NO" << std::endl;
			}
		}
		else
			std::cout << "NO" << std::endl;
	}	
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin >> t;
	while(t--){
		solve();
	}
	return 0;
}