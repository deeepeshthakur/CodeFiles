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
	long a,b;
	std::cin >> a >> b;
	std::vector<int> a_bin,b_bin,ans;
	while(a>0){
		a_bin.push_back(a%2);
		a/=2;
	}

	while(b>0){
		b_bin.push_back(b%2);
		b/=2;
	}

	if(a_bin.size() != b_bin.size()){
		std::cout << "0\n";
		return;
	}

	ans.resize(a_bin.size());
	for(int i=a_bin.size()-1;i>=0;i--){
		if(a_bin[i] == b_bin[i]){
			ans[i] = a_bin[i];
		}
		else{
			break;
		}
	}

	long ret = 0;
	a = 1;
	for(int i=0;i<ans.size();i++){
		ret += a*ans[i];
		a *= 2;
	}
	std::cout << ret << "\n";
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

	// solve();
	return 0;
}