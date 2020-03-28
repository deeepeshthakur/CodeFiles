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
const long long MOD=1e9+7;

void solve(){
	int n;
	std::cin >> n;
	std::string str;
	std::cin >> str;
	int z = 0,o = 0;
	for(int i = 0; i < n ; i++){
		if(str[i] == 'z')
			z++;
		if(str[i] == 'n')
			o++;
	}

	for(int i = 0; i < o; i++)
		std::cout << 1 << " ";

	for(int i = 0; i < z; i++)
		std::cout << 0 << (i + 1 < z ? " " : "\n");
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// int t;
	// std::cin >> t;
	// while(t--){
	// 	solve();
	// }

	solve();
	return 0;
}