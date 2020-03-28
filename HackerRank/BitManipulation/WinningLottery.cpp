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

void print_vec(std::vector<bool>& a){
	for(int i=0;i<a.size();i++)
		std::cout << a[i] << (i+1 == a.size() ? "\n" : " ");
}

int bin_to_dec(std::vector<bool>& a){
	int mul = 1, ans = 0;
	for(int i=0;i<10;i++){
		ans += (a[i] ? mul : 0);
		mul*=2;
	}
	return ans;
}

void solve(){
	int n;
	std::cin >> n;
	std::vector<long> dp_table(1024,0);
	for(int i=0;i<n;i++){
		std::string str;
		std::cin >> str;
		std::vector<bool> val(10,false);
		for(int j=0;j<str.size();j++){
			val[int(str[j]-'0')] = true;
		}
		// print_vec(val);
		dp_table[bin_to_dec(val)]++;
	}

	long ans = 0;
	for(int i=0;i<dp_table.size();i++){
		for(int j=i+1;j<dp_table.size();j++){
			if((i|j) == 1023){
				ans += dp_table[i]*dp_table[j];
			}
		}
	}
	ans += (dp_table[1023]*(dp_table[1023]-1))/2;
	std::cout << ans << "\n";
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