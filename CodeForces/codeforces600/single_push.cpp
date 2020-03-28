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
	std::vector<int> a(n,0),b(n,0);
	for(int i=0;i<n;i++)
		std::cin >> a[i];

	for(int i=0;i<n;i++)
		std::cin >> b[i];

	std::set<int> k;
	std::vector<int> tmp;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			tmp.pb(i);
			k.insert(b[i]-a[i]);
		}
	}

	if(tmp.size()==0)
		std::cout << "YES\n";
	else{
		bool flag = true;
		for(int i=0;i<tmp.size()-1;i++){
			if(tmp[i+1]-tmp[i]!=1)
				flag=false;
		}

		if(flag && k.size()== 1 && b[tmp[0]]-a[tmp[0]]>0){
			std::cout << "YES\n";
		}
		else{
			std::cout << "NO\n";
		}
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

	// 	solve();
	return 0;
}