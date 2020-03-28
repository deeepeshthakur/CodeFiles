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

void solve(){
	int n,k,d;
	std::cin >> n >> k >> d;
	std::vector<int> arr(n,0);
	for(int i=0;i<n;i++){
		std::cin >> arr[i];
	}

	int ans = int(1e5);
	for(int i=0;i<n;i++){
		if(i+d-1<n){
			std::set<int> st;
			for(int j=i;j<i+d;j++){
				st.insert(arr[j]);
			}
			ans = std::min(int(st.size()),ans);
		}
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
