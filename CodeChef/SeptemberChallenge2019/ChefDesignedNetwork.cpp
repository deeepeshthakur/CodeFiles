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

bool tf(long long n, long long m, long long c){
	if(c < 2 && m < n - 1)
		return false;

	if(c == 2)
		return (m >= n - 1 && m <= n + 1);

	if(c == n){
		return m == (n*n+n)/2;
	}

	if(c%2 == 0){
		return (m <= ((c+1)*n)/2 && std::max(c,n-1) <= m);
	}
	
	return (std::max(c,n-1) <= m) && (m <= (1 + (c-1)/2)*n);
}

long long bs(long long n, long long m){
	if((m < n - 1) || (m > (n*n+n)/2))
		return -1ll;

	long long l = 2, r = n;
	while(r - l > 1){
		long long mid = (l + r)/2;
		if(tf(n,m,mid))
			r = mid;
		else
			l = mid;
	}

	if(tf(n,m,l))
		return l;

	return r;
}

void solve(){
	long long ans = -1ll;
	long long n,m;
	std::cin >> n >> m;

	if(n == 1){
		if(m == 0)
			ans = 0;
		
		if(m == 1){
			ans = 1;
		}

		if(m > 1){
			ans = -1;
		}
	}

	if(n == 2){
		if(m == 0)
			ans = -1;

		if(m == 1)
			ans = 1;

		if(m > 1 && m < 4)
			ans = 2;

		if(m >= 4)
			ans = -1;
	}

	if(n > 2){
		ans = bs(n,m);
	}

	std::cout << ans << "\n";
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

	// 	solve();
	return 0;
}
