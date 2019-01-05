#include<bits/stdc++.h>
#define ll int
#define pll std::pair<ll,ll>
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define per(i,a,b) for(ll i=(ll)a;i>(ll)b;i--)
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

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	std::vector<std::pair<int,int>> a(n,{0,0}),b(m,{0,0});
	rep(i,0,n){
		std::cin>>a[i].F;
		a[i].S=i;
	}
	rep(i,0,m){
		std::cin>>b[i].F;
		b[i].S=i;
	}
	std::sort(full(a));
	std::sort(full(b));
	rep(i,0,n){
		std::cout<<a[i].S<<" "<<b[0].S<<"\n";
	}
	rep(i,1,m){
		std::cout<<a[n-1].S<<" "<<b[i].S<<"\n";
	}
	return 0;
}