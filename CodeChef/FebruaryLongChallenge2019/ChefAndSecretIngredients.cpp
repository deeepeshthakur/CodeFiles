#include<bits/stdc++.h>
#define iint int
#define pll std::pair<iint,iint>
#define rep(i,a,b) for(iint i=(iint)a;i<(iint)b;i++)
#define per(i,a,b) for(iint i=(iint)a;i>(iint)b;i--)
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
const double MOD=1e9+7;

void solve(){
    int n;
    std::cin>>n;
    std::string s;
    std::vector<int> ans(26,0);
    rep(i,0,n){
        std::cin>>s;
        std::vector<int> tmp(26,0);
        rep(j,0,s.length()){
            tmp[s[j]-'a']++;
        }
        rep(j,0,26){
            tmp[j] == 0 || ans[j]++;
        }
    }
    int sm=0;
    rep(i,0,26){
        sm += (ans[i]==n) ? 1:0;
    }
    std::cout<<sm<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}