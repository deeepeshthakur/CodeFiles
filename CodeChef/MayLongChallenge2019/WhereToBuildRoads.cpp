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

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		std::vector<long long> xs(n),ys(n);
		rep(i,0,n){
			long long x,y;
			std::cin >> x >> y;
			xs[i]=x-y;
			ys[i]=x+y;
		}
		std::sort(full(xs));
		std::sort(full(ys));
		long long minm = 2*(1e9);
		rep(i,0,n-1){
			minm = std::min(minm,std::min(xs[i+1]-xs[i],ys[i+1]-ys[i]));
		}
		std::cout<<std::fixedcd <<std::setprecision(6)<<0.5*minm<<std::endl;
	}
	return 0;
}