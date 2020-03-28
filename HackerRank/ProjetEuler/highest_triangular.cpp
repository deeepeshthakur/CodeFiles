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
bool _is_pre_calc=true;

void pre_calc(vector<long long>& dp){
	
}

void solve(){
	vector<long long> dp;
	if(_is_pre_calc){
		pre_calc(dp);
		_is_pre_calc=false;
	}

	int n;
	cin>>n;
	cout<<dp[n]<<"\n";
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