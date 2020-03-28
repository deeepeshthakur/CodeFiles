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
	int n;
	std::cin >> n;
	std::vector<int> arr(n,0);

	for(int i=0;i<n;i++){
		std::cin >> arr[i];
	}
	bool possiblity = true;
	bool flag = true;
	int i=0,ctr=0;
	std::vector<int> dp(int(1e6)+1,0);
	std::vector<int> ans;
	while(flag){
		ctr=0;
		std::set<int> emp;
		for(int j=i;j<n;j++){
			if(emp.find(arr[j]) != emp.end()){
				break;
			}
			else{
				dp[abs(arr[j])] += arr[i];
				if(dp[abs(arr[j])] < 0){
					possiblity = false;
				}
				emp.insert(arr[j]);
				i = j+1;
				ctr++;
			}
		}
		for(auto itr=emp.begin();itr!=emp.end();itr++){
			if(dp[abs(*itr)] != 0){
				possiblity =false;
			}
		}
		ans.pb(ctr);

		flag = (i<n);
	}

	if(possiblity){
		std::cout << ans.size() << "\n";
		for(int j=0;j<ans.size();j++)
			std::cout << ans[j] << " ";
		std::cout << "\n";
	}
	else{
		std::cout << "-1\n";
	}
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