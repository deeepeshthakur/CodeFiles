#include<bits/stdc++.h>
#define ll long
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
std::vector<long> bc{0,1,2,3,4,5,6,7,8,9,10,11,13};
long dpf(long a,std::map<long,long>& dp){
	auto it = dp.find(a);
	if(it==dp.end()){
		long av = dpf(a/2,dp)+dpf(a/3,dp)+dpf(a/4,dp);
		dp.insert({a,std::max(a,av)});
	}
	return dp.find(a)->S;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	long a;
	std::map<long,long> dp{};
	rep(i,0,bc.size()){
		dp.insert({i,bc[i]});
	}
	while(std::cin>>a){
		std::cout<<dpf(a,dp)<<std::endl;
	}
	return 0;
}