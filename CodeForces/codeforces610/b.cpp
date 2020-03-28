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
	int n,k;
	long long p;
	cin>>n>>p>>k;
	vector<int> a(n,0);
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(full(a));


	int ans=0;
	long long odd=0,even=0;
	for(int i=0;i<n;i++){
		if(i%2==0){
			odd+=a[i];
			if(odd<=p)
				ans=max(ans,i+1);
		}
		else{
			even+=a[i];
			if(even<=p)
				ans=max(ans,i+1);
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