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

bool check_digit_fact(int num, vector<long long>& fact){
	long long sm=0,n=num;
	while(n){
		sm+=fact[n%10];
		n/=10;
	}

	return (sm%num==0);
}

void solve(){
	int n;
	cin>>n;
	vector<long long> fact(10,1ll);
	for(int i=2;i<10;i++)
		fact[i]=fact[i-1]*i;

	vector<bool> dp(n+1,false);

	for(int i=10;i<dp.size();i++){
		dp[i] = check_digit_fact(i,fact);
	}

	long long sm = 0;
	for(int i=0;i<=n;i++){
		sm += (dp[i] ? i : 0);
	}
	cout<<sm<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	solve();
	
	return 0;
}