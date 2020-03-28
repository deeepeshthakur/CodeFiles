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
	int n,m;
	cin>>n>>m;
	vector<vector<long long>> rdp(n+1,vector<long long>(m+1,0ll)),sdp(n+1,vector<long long>(m+1,0ll));

	for(int i=1;i<=n;i++){
		sdp[i][1]=1;
		rdp[i][1]=1;
	}


	long long ans=0;
	for(int j=2;j<=m;j++){
		for(int i=1;i<=n;i++){
			ans=0;
			for(int x=1;x<=i;x++){
				ans+=sdp[x][j-1];
			}
			sdp[i][j]=ans%MOD;
		}
	}

	ans=0;
	for(int j=2;j<=m;j++){
		for(int i=n;i>=1;i--){
			ans=0;
			for(int x=n;x>=i;x--){
				ans+=rdp[x][j-1];
			}
			rdp[i][j]=ans%MOD;
		}
	}

	ans=0;
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){
			if(a<=b){
				ans+=(sdp[a][m]*rdp[b][m])%MOD;
				ans%=MOD;
			}
		}
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