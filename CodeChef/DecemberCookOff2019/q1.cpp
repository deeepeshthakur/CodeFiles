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

long long get_sum(long long l){
	if(l<1)
		return 0ll;
	return (l*l+l)/2ll;
}

long long f1(long long l){
	if(l<=0)
		return 0;
	long long ans=0;
	{
		long long tmp=1;
		while(tmp<=l){
			ans--;
			tmp*=2ll;
		}
	}

	long long curr=1,a;
	while(curr<l){
		a=curr*2ll;
		ans+=a*get_sum((l-curr)/a);
		curr*=2ll;
	}
	return ans;
}

void solve(){
	long long l,r;
	cin>>l>>r;
	cout<<f1(r)-f1(l-1)<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;       
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}