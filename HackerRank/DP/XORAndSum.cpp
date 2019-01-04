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
const long long MOD=7+1e9;
const long long si=314159;
const int ln=1e5+si+1;

void getInp(std::vector<long long>& a,std::vector<long long>& b){
	std::string aa,bb;
	std::cin>>aa>>bb;
	int j=ln-1;
	per(i,aa.length()-1,-1){
		a[j--]=aa[i]-'0';
	}
	j=ln-1;
	per(i,bb.length()-1,-1){
		b[j--]=bb[i]-'0';
	}	
}

long long f102(int i,int j,std::vector<long long>& dp){
	return dp[std::min(j,ln-1)]-dp[std::max(0,i-1)];
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::vector<long long> a(ln,0),b(ln,0),dp(ln,0),pw2(ln,1),ans1(ln,0);
	getInp(a,b);

	rep(i,0,ln){
		dp[i]=b[i];
		if(i){
			dp[i]+=dp[i-1];
		}
	}

	per(i,ln-2,-1){
		pw2[i]=(pw2[i+1]*2)%MOD;
	}

	long long ans=0,os=0;
	rep(i,0,ln){
		if(a[i]==1){
			ans+=((si+1-f102(i,i+si,dp))*pw2[i])%MOD;
		}
		else{
			ans+=(f102(i,i+si,dp)*pw2[i])%MOD;
		}
		ans%=MOD;
	}
	std::cout<<ans<<std::endl;
	return 0;
}