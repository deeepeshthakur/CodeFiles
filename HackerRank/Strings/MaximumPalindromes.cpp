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

long long f4(long long a, long long b){
	if(a == 0ll)
		return 0ll;

	if(b == 0ll)
		return 1ll;

	if(b == 1ll)
		return a%MOD;

	long long x = f4(a,b/2)%MOD;
	x = (x*x)%MOD;
	if(b%2 == 1ll){
		x = (x*(a%MOD))%MOD;
	}
	return x%MOD;
}

long long f2(std::vector<int>& query, std::vector<long long>& fac){
	int sm = 0, ones = 0;
	for(int i = 0; i < 26; i++){
		ones += query[i]%2;
		sm += (query[i]/2)*2;
	}
	
	long long num = fac[sm/2], den = 1ll;
	if(ones > 0)
		num = (num*ones)%MOD;
	for(int i = 0; i < 26; i++){
		den = (den*fac[query[i]/2])%MOD;
	}
	
	return (num*f4(den,MOD - 2))%MOD;
}

void f1(std::string& s, std::vector<std::vector<int>>& dp,std::vector<long long>& fac){
	int n = dp.size();
	for(int i = 0; i < n ; i++){
		dp[i][s[i]-'a']++;
		if(i > 0){
			for(int j  = 0; j < 26; j++){
				dp[i][j] += dp[i-1][j];
			}
		}
	}

	for(int i = 2; i < n; i++){
		fac[i] = (fac[i-1]*i)%MOD;
	}
}

void solve(){
	int n,q;
	std::string str;
	std::cin >> str;
	std::cin >> q;
	n = str.length();
	std::vector<std::vector<int>> dp(n,std::vector<int>(26,0));
	std::vector<long long> fac(n+1,1ll);
	f1(str,dp,fac);

	int l,r;
	std::vector<int> query(26,0);
	for(int i = 0; i < q; i++){
		std::cin >> l >> r;
		l--;
		r--;
		for(int j = 0; j < 26; j++){
			query[j] = dp[r][j] - ((l > 0) ? dp[l-1][j] : 0);
		}

		std::cout << f2(query,fac) << std::endl;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}