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
	int n,a,b,ma=0,mb=0;
	cin>>n>>a>>b;
	for(int i=0;i<a;i++){
		int x;
		cin>>x;
		ma=max(ma,x);
	}

	for(int i=0;i<b;i++){
		int y;
		cin>>y;
		mb=max(y,mb);
	}

	if(ma>mb){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
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