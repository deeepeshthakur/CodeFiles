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

std::vector<unsigned long long> ttmp{1, 9, 45, 9, 10, 99, 9045, 189,
100, 999, 1395495, 2889,
1000, 9999, 189414495, 38889,
10000, 99999, 23939649495, 488889,
100000, 999999, 2893942449495, 5888889,
1000000, 9999999, 339393974949495, 68888889,
10000000, 99999999, 38939394344949495, 788888889,
100000000, 999999999, 4393939398494949495, 8888888889};

void solve(){
	std::vector<std::vector<unsigned long long>> a(4);
	for(int i=0;i<ttmp.size();i+=4){
		a[0].pb(ttmp[i]);
		a[1].pb(ttmp[i+1]);
		a[2].pb(ttmp[i+2]);
		a[3].pb(ttmp[i+3])
	}
	unsigned long long k;
	std::cin >> k

	unsigned long long l,r, ln,dig;
	for(int i=0;i<a[0].size()-1;i++){
		if(k>=a[2][i] && k<a[2][i+1]){
			k-=a[2][i];
			l = a[0][i];
			r = a[1][i];
			ln = (i > 0 ? a[3][i-1] : 0);
			dig=i+1;
			break;
		}
	}
	unsigned long long mid,ll=l;
	while(r-ll>1){
		mid = (ll+r)/2;
		if(k>ln + ((mid - l  +1)*(2*ln+2*dig+(mid-l)*dig))/2){
			ll = mid;
		}
		else{
			r = mid;
		}
	}

	unsigned long long curr = (k <= ln + ((ll-l+1)*(2*ln+2*dig+(mid-l)*dig))/2) ? ll : r;
	k -= ln + ((curr-l)*(2*ln+2*dig+(curr-1-l)*dig));
	
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