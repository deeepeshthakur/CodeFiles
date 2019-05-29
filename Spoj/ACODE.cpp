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

void f(std::string s){
	std::vector<int> dp(s.length(),0);
	if(s[dp.size()-1]-'0'!=0){
		dp[dp.size()-1]=1;
	}

	if((s[dp.size()-2]-'0')*10+s[dp.size()-1]-'0'>9&&(s[dp.size()-2]-'0')*10+s[dp.size()-1]-'0'<27){
		dp[dp.size()-2]=1;
	}
	per(i,dp.size()-1,-1){
		if(i+1<dp.size()){
			if(s[i]-'0'!=0){
				dp[i]+=dp[i+1];
			}
		}

		if(i+2<dp.size()){
			int n=(s[i]-'0')*10+s[i+1]-'0';
			if(n>9&&n<27){
				dp[i]+=dp[i+2];
			}
		}
	}
	std::cout<<dp[0]<<std::endl;
}

// int main(){
// 	std::ios::sync_with_stdio(false);
// 	std::cin.tie(NULL);
// 	std::cout.tie(NULL);
// 	std::vector<std::string> v{};
// 	std::string s;
// 	std::cin>>s;
// 	while(s[0]!='0'){
// 		v.pb(s);
// 		std::cin>>s;
// 	}

// 	rep(i,0,v.size()){
// 		f(v[i]);
// 	}
// 	return 0;
// }
