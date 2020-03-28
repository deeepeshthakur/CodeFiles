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
const long long MOD=1e9+7;
const long long maxn = 2e18;

std::vector<int> dp_table(100,0);

std::vector<int> f5(std::vector<int> a, std::vector<int> b){
	int c1 = (a[0]*b[0] + a[1]*b[2])%10, c2 = (a[0]*b[1] + a[1]*b[3])%10,
	    c3 = (a[2]*b[0] + a[3]*b[2])%10, c4 = (a[2]*b[1] + a[3]*b[3])%10;
	return std::vector<int>({c1,c2,c3,c4});	
}

std::vector<int> f6(std::vector<int> a, long long n){
	if(n == 0)
		return std::vector<int>({1,0,0,1});

	if(n == 1)
		return std::vector<int>({a[0],a[1],a[2],a[3]});

	std::vector<int> ansd2(4,0), ans(4,0);
	
	ansd2 = f6(a,n/2);
	ans = f5(ansd2,ansd2);

	if(n%2)
		return f5(ans,a);

	return ans;
}

long long f3(long long a, long long b){
	if(a == 0)
		return 0ll;

	if(b == 0)
		return 1ll;

	if(b == 1)
		return a;

	long long x = f3(a,b/2);
	if(b%2)
		return x*x*a;

	return x*x;
}

int f2(long long n){
	std::vector<int> fib_arr{1,1,1,0}, ans(4,0);
	ans = f6(fib_arr,n);
	return ans[1]%10;
}

void f0(){
	dp_table[0] = 0;
	dp_table[1] = 1;
	for(int i = 2; i < 100; i++){
		dp_table[i] = f2(f3(2ll,i*1ll) - 1);
	}
}

void solve(){
	long long i = 0, n = 2, p2 = 1;
	std::cin >> n;
	while(p2*2 - 1 < n){
		i++;
		p2 *= 2;
	}

	std::cout << dp_table[i] << std::endl;
	return;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	f0();

	int t;
	std::cin >> t;
	while(t--){
		solve();
	}

	// solve();
	return 0;
}