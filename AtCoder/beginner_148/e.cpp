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

long long no_of(long long a, long long b){
	long long ans=0,p_b=b;
	while(p_b<=a){
		ans+=(a/p_b);
		if(a/p_b >= b){
			p_b*=b;
		}
		else{
			p_b=a+1;
		}
	}
	return ans;
}

void solve(){
	long long n;
	cin>>n;
	if(n%2==1){
		cout<<0<<"\n";
		return;
	}

	long long ans = min(no_of(n/2,5ll),n/2+1+no_of(n/2,2ll));
	cout<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}