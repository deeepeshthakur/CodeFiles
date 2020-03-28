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
	int n;
	std::cin>>n;
	std::vector<int> a(n,0);
	rep(i,0,n){
		std::cin>>a[i];
	}
	std::sort(full(a));
	std::vector<int> ans(n/2,0);
	long long sm=0;
	rep(i,0,n/2){
		ans[i]=a[i]+a[n-1-i];
		ans[i]*=ans[i];
		sm+=ans[i];
	}
	std::cout<<sm<<"\n";
	return 0;
}