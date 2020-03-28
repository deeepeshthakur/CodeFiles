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
	int n,d;
	cin>>n>>d;
	vector<int> a(n,0);
	for(int i=0;i<n;i++)
		cin>>a[i];

	int ans=0;
	for(int i=0;i<n;i++){
		int tmp=i-0;
		if(d>=tmp*a[i]){
			ans+=a[i];
			d-=tmp*a[i];
		} 
		else{
			ans += (d/tmp);
			d%=tmp;
		}
	}
	cout<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t=1;       
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}