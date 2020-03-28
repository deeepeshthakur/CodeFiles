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
	string s;
	cin>>s;
	n=s.size();
	int x=-1,y=-1;
	for(int i=0;i<n;i++){
		if(x==-1 && s[i]=='1')
			x=i;
	}

	for(int i=n-1;i>=0;i--){
		if(y==-1 && s[i]=='1'){
			y=i;
		}
	}

	int ans=0;
	if(x!=-1 && y!=-1 && x<y){
		for(int i=x;i<=y;i++){
			if(s[i]=='0')
				ans++;
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