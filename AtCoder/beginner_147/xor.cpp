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
	cin>>n;
	vector<vector<int>> all_num(n,vector<int>(62,0));
	vector<long long> inp(n,0ll);
	for(int i=0;i<n;i++)
		cin>>inp[i];

	for(int i=0;i<n;i++){
		long long tmp=inp[i];
		for(int j=0;j<62;j++){
			all_num[i][j] = tmp%2;
			tmp/=2;
		}
	}
	long long ans=0,mul=1;
	for(int j=0;j<62;j++){
		long long sm=all_num[n-1][j],ln=1;
		for(int i=n-2;i>=0;i--){
			if(all_num[i][j]==1){
				ans += (mul*(ln-sm))%MOD;
				ans %= MOD;
			}
			else{
				ans += (mul*sm)%MOD;
				ans %= MOD;
			}
			sm += all_num[i][j];
			ln++;
		}
		mul = (mul*2ll)%MOD;
	}
	cout << ans%MOD << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	solve();
	
	return 0;
}