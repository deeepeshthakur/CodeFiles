#include<bits/stdc++.h>
#define iint int
#define pll std::pair<iint,iint>
#define rep(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define per(i,a,b) for(int i=(int)a;i>(int)b;i--)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define full(a) a.begin(),a.end()
#define rfull(a) a.rbegin(),a.rend()

using namespace std;
const double pi=acos(-1.0);
const double pii=2*pi;
const double eps=1e-13;
const double MOD=1e9+7;

double f1(long long a, long long n, long long x){
	if(2*n*a + n*n - n + 2*x == 0)
		return 1.0;
	double ans = 0.0;

}

void solve(){
	long long a,d,n,x;
	std::cin >> a >> d >> n >> x;
	double ans = f1(a-d,n,x);
	std::cout << std::fixed << std::setprecision(13) << ans << std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin >> t;
	while(t--){
		solve();
	}
	return 0;
}