#include<bits/stdc++.h>
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

long long get_val(long long h){
	if(h==1)
		return 1ll;
	return 1ll+2ll*get_val(h/2);
}

void solve(){
	unordered_map<long long,long long> ht;
	long long h;
	long long ans=0;
	cin>>h;
	ans=get_val(h);
	cout<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}