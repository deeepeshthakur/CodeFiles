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
	std::string str;
	std::cin >> str;
	std::vector<int> a(str.size(),0);
	for(int i=0;i<a.size();i++)
		a[i] = int(str[a.size()-1-i]-'0');

	int i=0;
	while(i < a.size() && a[i]%2 == 1){
		i++;
	}

	if(a[i]%2 == 1)
		std::cout << "-1\n";
	else{
		
	}
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
