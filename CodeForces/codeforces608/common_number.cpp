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

long long get_paths(long long n,long long y,unordered_map<long long,long long>& ht){
	if(y>n)
		return 0ll;
	// cout << ht.size() << endl;
	auto itr=ht.find(y);
	if(itr==ht.end()){
		long long tmp=1ll+get_paths(n,2ll*y,ht);
		if(y%2==0)
			tmp+=get_paths(n,y+1,ht);
		ht.insert({y,tmp});
		return tmp;
	}
	return itr->second;
}

void solve(){
	long long n,k;
	cin>>n>>k;
	unordered_map<long long,long long> ht;
	long long l=1,r=n,mid;
	// r=2ll;
	// while(r*2ll<=n  && get_paths(n,r,ht)>=k){
	// 	r*=2;
	// }

	while(r-l>1ll){
		// cout << l << " " << r <<endl;
		mid=(l+r)/2;
		if(get_paths(n,mid,ht)>=k)
			l=mid;
		else
			r=mid;
	}
	// for(auto itr=ht.begin();itr!=ht.end();itr++){
	// 	cout<<itr->first<<" "<<itr->second<<"\n";
	// }
	long long curr;
	if(get_paths(n,r,ht)>=k)
		curr=r;
	else
		curr=l;
	while(curr*2ll<=n && get_paths(n,curr*2ll,ht)>=k){
		curr*=2ll;
	}
	cout<<curr<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}