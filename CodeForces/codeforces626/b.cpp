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
	long long k;
	cin>>n>>m>>k;
	vector<int> a(n,0),b(m,0);
	vector<int> k_factors;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	for(int i=1;i<40000+10;i++){
		if(k%i==0){
			k_factors.pb(i);
		}
	}

	sort(full(k_factors));
	vector<int> dp(m,0);
	for(int i=m-1;i>-1;i--){
		dp[i]=(b[i]==1?1:0);
		if(i<m-1 && b[i]==1){
			dp[i]+=dp[i+1];
		}
	}

	vector<long long> dp1(40000+1,0);
	for(int i=0;i<m;i++){
		dp1[dp[i]]++;
	}

	for(int i=dp1.size()-2;i>=0;i--){
		dp1[i]+=dp1[i+1];
	}

	vector<int> dpa(n,0);
	for(int i=n-1;i>=0;i--){
		dpa[i]=(a[i]==1?1:0);
		if(i<n-1 && a[i]==1)
			dpa[i]+=dpa[i+1];
	}

	long long ans=0;
	long long tmp=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<k_factors.size() && k_factors[j]<=dpa[i];j++){
			tmp=k/k_factors[j];
			if(tmp<dp1.size()){
				ans+=(dp1[int(tmp)]);
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