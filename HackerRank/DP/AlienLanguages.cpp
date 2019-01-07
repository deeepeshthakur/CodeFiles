#include<bits/stdc++.h>
#define ll int
#define pll std::pair<ll,ll>
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define per(i,a,b) for(ll i=(ll)a;i>(ll)b;i--)
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
const long long MOD=7+1e8;

long long dpf(int in,std::vector<long long>& dp,std::vector<long long>& eq){
	long long ans=0;
	rep(i,0,eq.size()){
		ans+=(eq[i]*((in-i>=0)?dp[in-i]:(long long)0))%MOD;
		ans%=MOD;
	}
	return ans;
}

void f100(){
	int n,m;
	std::cin>>n>>m;
	std::vector<long long> eqf(15);
	{
		std::vector<std::vector<long long>> eq(n+1,std::vector<long long>(15,0));
		for(int i=n;i>0;i--){
			if(2*i>n){
				eq[i][0]=1;
			}
			else{
				int j=2*i;
				rep(k,1,15){
					eq[i][k]+=eq[j][k-1];
					eq[i][k]%=MOD;
				}
			}
			if(i<n){
				rep(j,0,15){
					eq[i][j]+=eq[i+1][j];
					eq[i][j]%=MOD;
				}
			}
		}	
		rep(j,0,15){
			eqf[j]+=eq[1][j];
			eqf[j]%=MOD;
		}
	}

	std::vector<long long> dp(m+1);
	dp[0]=1;
	rep(i,1,m+1){
		dp[i]=dpf(i-1,dp,eqf);
	}
	std::cout<<dp[m]<<std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int q;
	std::cin>>q;
	while(q--)
		f100();	
	return 0;
}