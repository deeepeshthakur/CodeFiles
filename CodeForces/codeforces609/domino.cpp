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

void print_vec(vector<int>& a,int n=-1){
	n = (n==-1 ? a.size():n);
	for(int i=0;i<n;i++)
		cout << a[i] << (i<n-1 ? " ":"\n");
}

void print_vec(vector<long long>& a,int n=-1){
	n=(n==-1 ? a.size():n);
	for(int i=0;i<n;i++)
		cout << a[i] << (i<n-1 ? " ":"\n");
}

void solve(){
	int n;
	cin>>n;
	long long ans=0;
	vector<int> a(n,0);
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		if(t%2==1){
			ans+=max(0,(t-1)/2);
			a[i]=1;
		}
		else{
			ans+=max(0,(t-2)/2);
			a[i]=2;
		}
	}

	// print_vec(a);
	vector<long long> dp(n,0ll);
	vector<vector<long long>> dp_star(n,vector<long long>(3,0ll));
	if(a[n-2]==2 && a[n-1]==1){
		dp[n-2]=1;
		dp[n-1]=0;
		dp_star[n-1][1]=0;
		dp_star[n-1][2]=0;
		dp_star[n-1][0]=0;
		dp_star[n-2][1]=1;
		dp_star[n-2][2]=0;
		dp_star[n-2][0]=1;
	}

	if(a[n-2]==1 && a[n-1]==1){
		dp[n-2]=1;
		dp[n-1]=0;
		dp_star[n-1][1]=0;
		dp_star[n-1][2]=0;
		dp_star[n-1][0]=0;
		dp_star[n-2][1]=1;
		dp_star[n-2][2]=0;
		dp_star[n-2][0]=0;
	}

	if(a[n-2]==1 && a[n-1]==2){
		dp[n-2]=1;
		dp[n-1]=1;
		dp_star[n-1][1]=0;
		dp_star[n-1][2]=0;
		dp_star[n-1][0]=1;
		dp_star[n-2][1]=1;
		dp_star[n-2][2]=0;
		dp_star[n-2][0]=0;
	}

	if(a[n-2]==2 && a[n-1]==2){
		dp[n-2]=2;
		dp[n-1]=1;
		dp_star[n-1][1]=0;
		dp_star[n-1][2]=0;
		dp_star[n-1][0]=1;
		dp_star[n-2][1]=1;
		dp_star[n-2][2]=1;
		dp_star[n-2][0]=2;
	}

	for(int i=n-3;i>=0;i--){
		if(a[i]==1){
			dp_star[i][2]=0;
			dp_star[i][0]=0;
			if(a[i+1]==1){
				dp_star[i][1]=max(dp[i+1],1+dp[i+2]);
				dp[i]=dp_star[i][1];
			}
			else{
				dp_star[i][1]=max(dp[i+1],1+dp_star[i+1][2]);
				dp[i]=dp_star[i][1];
			}
		}
		else{
			if(a[i+1]==1){
				dp_star[i][1]=max(dp[i+1],1+dp[i+2]);
				dp_star[i][2]=dp[i+1];
				dp_star[i][0]=max(1+dp[i+1],1+dp[i+2]);
				dp[i]=dp_star[i][0];
			}
			else{
				dp_star[i][1]=max(1+dp_star[i+1][2],dp[i+1]);
				dp_star[i][2]=max(dp[i+1],1+dp_star[i+1][1]);
				dp_star[i][0]=max(max(1+dp[i+1],2+dp[i+2]),max(1+dp_star[i+1][1],1+dp_star[i+1][2]));
				dp[i]=dp_star[i][0];
			}
		}

		// cout<< i << " -- " << dp[i] << " " << dp_star[i][0] << " " << dp_star[i][1] << " " << dp_star[i][2] << "\n";
	}

	ans+=dp[0];
	cout<<ans<<"\n";

	// print_vec(dp);
	// for(int i=0;i<n;i++){
	// 	print_vec(dp_star[i]);
	// }
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}