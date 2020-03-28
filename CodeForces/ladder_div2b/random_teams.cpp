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

long long f1(long long a){
	return (a*(a-1))/2;
}

void solve(){
	long long n,m;
	std::cin >> n >> m;
	long long a1, a2;
	a2 = f1(1+n-m);
	a1 = (n%m)*f1(n/m + 1) + (m - n%m)*f1(n/m);
	std::cout << a1 << " " << a2 << std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}