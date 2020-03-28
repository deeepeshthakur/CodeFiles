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
	int n,k;
	std::cin >> n >> k;
	std::vector<int> a(n,0);
	
	for(int i = 0; i < n; i++)
		std::cin >> a[i];

	std::sort(full(a));
	std::vector<int> dis, ctr;
	for(int i = 0; i < n; i++){
		if(i == 0 || a[i] != a[i-1]){
			dis.push_back(a[i]);
			ctr.push_back(1);
		}
		else{
			ctr[ctr.size() - 1]++;
		}
	}

	n = dis.size();
	std::vector<long long> eq1(n+5,0ll), eq2(n+5,0ll);
	eq1[0] = 1;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n + 5; j++){
			eq2[j] = (eq2[j] + eq1[j])%MOD;
			if(j + 1 < eq2.size()){
				eq2[j+1] = (eq2[j+1] + (ctr[i]*eq1[j])%MOD)%MOD;
			}
		}

		for(int j = 0; j < n + 5; j++){
			eq1[j] = eq2[j];
			eq2[j] = 0;
		}
	}

	long long sumk = 0ll;
	k = std::min(k+1,n+5);
	for(int i = 0; i < k; i++){
		sumk = (sumk + eq1[i])%MOD;
	}

	std::cout << sumk << std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// int t;
	// std::cin >> t;
	// while(t--){
	// 	solve();
	// }

	solve();
	return 0;
}
