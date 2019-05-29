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

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin>>t;
	while(t--){
		unsigned long long g,l,r;
		std::cin >> l >> r >> g;
		if(l > r){
			std::swap(l,r);
		}
		l = l/g + ((l%g == 0) ? 0 : 1);
		r = r/g;
		if(l > r){
			std::cout<<0<<std::endl;
		}
		else{
			if(l == r){
				if(l == 1){
					std::cout<<1<<std::endl;
				}
				else{
					std::cout<<0<<std::endl;
				}
			}
			else{
				std::cout<<r-l+1<<std::endl;
			}
		}
	}
	return 0;
}