#include<bits/stdc++.h>
#define iint int
#define pll std::pair<iint,iint>
#define rep(i,a,b) for(iint i=(iint)a;i<(iint)b;i++)
#define per(i,a,b) for(iint i=(iint)a;i>(iint)b;i--)
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
	std::cin >> n;
	std::vector<std::vector<bool>> dp(n,std::vector<bool>(n,false));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(i!=0 && j!=0){
				dp[i][j] = (__gcd(i,j)>1);
			}
			else{
				if(i+j!=1){
					dp[i][j]=true;
				}
			}
		}
	vector<pair<int,int>> ans;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(dp[i][j] && dp[i+1][j] && dp[i][j+1] && dp[i+1][j+1])
				ans.pb({i,j});
		}
	}

	sort(full(ans));
	for(int i=0;i<ans.size();i++){
		long long x = ans[i].F, y = ans[i].S,k1,k2,k3,k4,x1,x2,y1,y2;
		k1 = __gcd(x,y);
		k2 = __gcd(x+1,y);
		k3 = __gcd(x,y+1);
		k4 = __gcd(x+1,y+1);
		x1 = x/(k1*k3/__gcd(k1,k3));
		x2 = (x+1)/(k2*k4/__gcd(k2,k4));
		y1 = y/(k1*k2/__gcd(k1,k2));
		y2 = (y+1)/(k3*k4/__gcd(k3,k4));

		std::cout << x << " " << y << " " << k1 << " " << k2 << " " << k3 << " " << k4 << " " << x1 << " " << x2 << " " << y1 << " " << y2 << "\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// int t;
	// std::cin >> t;
	// while(t--){
	// 	solve();
	// }

	solve();
	return 0;
}