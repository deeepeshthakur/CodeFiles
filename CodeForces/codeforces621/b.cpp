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
	long long x;
	cin>>n>>x;
	vector<long long> a(n,0ll);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	sort(full(a));
	long long ans=3ll*int(1e9);
	for(int i=0;i<n;i++){
		if(x%a[i]==0){
			ans=min(ans,x/a[i]);
		}
		else{
			ans=min(ans,max(2ll,x/a[i] + 1));
		}
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