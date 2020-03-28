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
	int n;
	long long m;
	cin>>n>>m;
	vector<long long> a(n,0ll),b(n,0ll);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	sort(full(a));
	sort(full(b));
	long long ans=10ll*int(1e9);
	for(int i=0;i<n;i++){
		bool flag=true;
		long long x=(b[i]-a[0]+m)%m;
		for(int j=0;j<n;j++){
			if((a[j]+x)%m != b[(i+j)%n])
				flag=false;
		}
		if(flag)
			ans=min(ans,x);
	}
	cout<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}