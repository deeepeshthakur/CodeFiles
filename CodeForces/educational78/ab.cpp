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

void solve(){
	long long a,b;
	cin>>a>>b;
	if(a<b)
		swap(a,b);
	long long diff=a-b;
	long long ans = 0ll;
	long long l=0,r=diff,mid;
	while(r-l>1){
		mid=(l+r)/2;
		if(mid*mid+mid >= 2*diff){
			r=mid;
		}
		else{
			l=mid;
		}
	}

	ans=((l*l+l>=2*diff)?l:r);
	long long tmp=(ans*ans+ans)/2;
	while(tmp<diff || (tmp-diff)%2!=0){
		ans++;
		tmp=((ans+1ll)*ans)/2;
	}
	cout<<ans<<"\n";
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