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
	std::cin >> n;
	int dif = 0;
	std::vector<int> vecDiff(n,0);

	for(int i = 0; i < n; i++){
		std::string str;
		std::cin >> str;
		for(int j = 0; j < n; j++){
			if(j < n/2){
				vecDiff[i] += int(str[j] -'0');
			}
			else{
				vecDiff[i] -= int(str[j] -'0');
			}
		}
		dif += vecDiff[i];
	}

	int ans = std::abs(dif);
	for(int i = 0; i < n; i++){
		ans = std::min(ans,std::abs(dif-2*vecDiff[i]));
	}

	std::cout << ans << std::endl;
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