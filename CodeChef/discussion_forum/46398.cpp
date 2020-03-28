#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const long long mod = 1000000007ll;

int main(){
	int m,n,p;
	cin>>m>>n>>p;
	ll dp[m+1][n+1];
	for(int i=0;i<m+1;i++)
	    for(int j=0;j<n+1;j++)
	        dp[i][j]=0;

	while(p>0){
		int a, b;
		cin>>a>>b;   
		dp[a][b]=-1;   
		p--;
	}

	for(int i=m-1;i>=1;i--)
		if(dp[i][n]!=-1)
			dp[i][n]=1;
		else
			break;

	for(int i=n-1;i>=1;i--)
		if(dp[m][i]!=-1)
			dp[m][i]=1;
		else
			break;

	for(int i = m-1;i>=1;i--)
		for(int j = n-1;j>=1;j--)
			if(dp[i][j]!=-1){
				long long tmp=0;
				if(dp[i][j+1]!=-1)
					tmp=dp[i][j+1]%mod;
				if(dp[i+1][j]!=-1)
					tmp=(dp[i+1][j]+tmp)%mod;
				dp[i][j]=tmp%mod;
			}

	if(dp[m][n]==-1)
		dp[1][1]=0;

	if(dp[1][1]==-1)
		dp[1][1]=0;
	std::cout << dp[1][1] << std::endl;
	return 0;
}