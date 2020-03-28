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
	int b,g,n;
	std::cin >> b >> g >> n;
	if(b > g){
		std::swap(b,g);
	}

	if(n == b + g){
		std::cout << 1 << std::endl;
		return 0;
	}

	if(n > g){
		std::cout << b + 1 - (n - g) << std::endl;
		return 0;
	}
	
	std::cout << std::min(n + 1,b + 1) << std::endl;
	return 0;
}