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

int f101(int i,int n,std::vector<int>& c){
	int ans=0;
	if(n%i){
		ans=5e6;
	}
	else{
		int alp = n/i;
		std::vector<int> d(c.size(),0);
		rep(i,0,c.size()){
			d[i]=c[i];
		}
		std::sort(full(d));
		ans=0;
		rep(j,0,26-i){
			ans+=d[j];
		}
		rep(j,0,26){
			if(d[j]>alp){
				ans+=d[j] - alp;
			}
		}
	}
	return ans;
}

void f100(){
	std::string s;
	std::vector<int> c(26,0);
	std::cin>>s;
	rep(i,0,s.length()){
		c[s[i]-'A']++;
	}
	int mn=5e6;
	rep(i,1,27){
		int tmp = f101(i,s.length(),c);
		mn > tmp && (mn = tmp);
	}
	std::cout<<mn<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin>>t;
	while(t--){
		f100();
	}
	return 0;
}