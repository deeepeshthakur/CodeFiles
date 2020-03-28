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

int n = 5e3;
std::vector<int> lucky_num;
std::vector<std::vector<int>> factors(n);

void pre_calc(){
	// int n = 1e6;
	std::vector<bool> seive(n,true);
	seive[0]=false;
	seive[1]=false;

	for(int i = 2;i < n; i++){
		if(seive[i]){
			int j = i;
			while(1ll*j*i<n){
				seive[j*i]=false;
				j++;
			}


			j = 1;
			while(1ll*j*i<factors.size()){
				factors[j*i].push_back(i);
				j++;
			}
		}
	}

	for(int i = 0; i < factors.size(); i++){
		if(factors[i].size() >= 3){
			lucky_num.push_back(i);
		}
	}
}

void solve(){
	int nn;
	std::cin >> nn;
	std::cout << lucky_num[nn-1] << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	pre_calc();

	int t;
	std::cin >> t;
	while(t--){
		solve();
	}

	// 	solve();
	return 0;
}