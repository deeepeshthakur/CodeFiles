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
	int n, q;
	std::cin >> n >> q;
	std::string s;
	std::cin >> s;
	std::vector<int> dir(n,0);
	for(int i=0;i<n;i++)
		dir[i] = int(s[i]-'0');

	std::vector<std::pair<int,int>> query(q,{0,0});
	for(int i=0;i<q;i++){
		std::cin >> query[i].F >> query[i].S;
	}

	for(int i=1;i<n;i++){
		dir[i] += dir[i-1];
		dir[i] %= 6;
	}

	std::vector<std::vector<int>> dp(n,std::vector<int>(6,0));
	for(int i=0;i<n;i++){
		if(i>0){
			for(int j=0;j<6;j++){
				dp[i][j] += dp[i-1][j];
			}
		}
		dp[i][dir[i]]++;
	}

	for(int i=0;i<q;i++){
		int l = query[i].F-1, r = query[i].S-1;
		std::vector<int> delta(6,0);
		for(int j=0;j<6;j++){
			delta[j] = dp[r][j] - (l>0 ? dp[l-1][j]:0);
		}
		long long a=delta[0]-delta[3],b=delta[1]-delta[4],c=delta[2]-delta[5];
		long double p5 = 0.5,p25=0.25, sqr3 = 3.0, sqrt3 = sqrt(sqr3);

		long double x = (2*a + b - c)*p5, y = (b-c)*sqrt(1-p25);
		std::cout << std::fixed << std::setprecision(8) << x << " " << y << "\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;
	std::cin >> t;
	while(t--){
		solve();
	}

	// 	solve();
	return 0;
}