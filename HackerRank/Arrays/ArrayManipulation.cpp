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
	std::vector<std::pair<int,int>> am(2*m,{0,0});
	rep(i,0,m){
		int a,b,k;
		std::cin>>a>>b>>k;
		am[2*i]={a-1,k};
		am[2*i+1]={b,-k};
	}
	std::sort(full(am));
	long long ans=0,mx=0;
	rep(i,0,am.size()){
		ans+=am[i].S;
		mx=ans>mx?ans:mx;
	}
	std::cout<<mx<<std::endl;
	return 0;
}