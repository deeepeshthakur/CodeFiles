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

void calc_primes(int n, vector<int>& primes){
	vector<bool> tb(n+1,true);
	tb[0]=false;
	tb[1]=false;
	for(int i=2;i<=n;i++){
		if(tb[i]){
			int j=i;
			while(1ll*j*i <= 1ll*n){
				tb[i*j]=false;
				j++;
			}
			primes.pb(i);
		}
	}
}

void solve(){
	int r,c;
	cin>>r>>c;
	// vector<int> primes;
	// calc_primes(8000,primes);
	vector<vector<int>> dp(r,vector<int>(c,1));
	if(r==1&&c==1){
		cout << "0\n";
		return;
	}
	
	if(r==1){
		for(int i=0;i<c;i++){
			cout<<i+2<<(i+1<c?" ":"\n");
		}
		return;
	}

	if(c==1){
		for(int i=0;i<r;i++){
			cout<<i+2<<"\n";
		}
		return;
	}

	vector<int> gcd(r+c,0);
	for(int i=0;i<gcd.size();i++)
		gcd[i]=i+1;

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			dp[i][j]*=gcd[i]*gcd[j+r];
		}
	}

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<dp[i][j]<<(j+1<c ? " ":"\n");
		}
	}

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}