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

void fix_xs(std::vector<std::pair<int,int>>& a){
	std::sort(full(a));
	std::vector<std::pair<int,int>> tmp;
	tmp.pb({a[0].F,a[0].S});
	for(int i=0;i<a.size();i++){
		n=tmp.size()-1;
		if(tmp[n].S < a[i].F){
			tmp.pb({a[i].F,a[i].S});
		}
		else{
			tmp[n].F = min(tmp[n].F,a[i].F);
			tmp[n].S = max(tmp[n].S,a[i].S);
		}
	}
	a=tmp;
}

void solve(){
	int n,m;
	std::cin >> n >> m;
	std::vector<std::pair<int,int>> xs(n,{0,0});
	for(int i=0;i<n;i++){
		int a,b;
		std::cin >> a >> b;
		xs[i].F = a-b;
		xs[i].S = a+b;
	}

	std::sort(full(xs));
	fix_xs(xs);

	bool flag=true;
	while(flag){
		int ind,mx_val;
		n=xs.size();
		ind = 0;
		mx_val = xs[0].F-1;
		if(m-xs[n-1].S>mx_val){
			ind=n;
			mx_val=m=xs[n-1].S;
		}
		for(int i=1;i<n;i++){
			if(xs[i].F - xs[i-1].S - 1 > mx_val){
				mx_val = xs[i].F - xs[i-1].S - 1;
				ind = i;
			}
		}

		
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
