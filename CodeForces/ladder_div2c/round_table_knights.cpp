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
const double MOD=1e9+7;

bool f3(int ind, int sk, int n, std::vector<bool>& knts){
	bool flag = true;
	for(int i = ind; i < n; i += sk){
		flag = (flag && knts[i]);
	}
	return flag;
}

bool f1(int a, int b){
	return (a > 2 && b%a == 0);
}

bool f2(int a, int n, std::vector<bool>& knts){
	int b = n/a;
	bool flag = false;
	for(int i = 0; i < b; i++){
		flag = (flag || f3(i,b,n,knts));
	}

	return flag;
}

void solve(){
	int n;
	std::cin >> n;
	std::vector<bool> knts(n,false);
	for(int i = 0; i < n; i++){
		int t;
		std::cin >> t;
		knts[i] = (t == 1);
	}
	bool flag = false;
	std::vector<bool> dp(n+1,true);
	for(int i = 3; i <= n && !flag; i++){
		if(dp[i]){
			if(f1(i,n) && f2(i,n,knts)){
				flag = true;
			}
			else{
				dp[i] = false;
			}

			if(!dp[i]){
				for(int j = 2; j*i <= n; j++)
					dp[j*i] = false;
			}
		}
	}

	if(flag)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}