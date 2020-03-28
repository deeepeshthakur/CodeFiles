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

std::vector<unsigned long long> vec(39);

void print_vec(std::vector<unsigned long long>& a){
	for(int i = 0; i < a.size(); i++){
		std::cout << a[i] << (i < a.size() - 1 ? " ": "\n");
	}
}

void print_vec(std::vector<bool>& a){
	for(int i = 0; i < a.size(); i++){
		std::cout << a[i] << (i < a.size() - 1 ? " ": "\n");
	}
}


void pre_calc(){
	vec[0] = 1;
	for(int i = 1; i < vec.size(); i++){
		vec[i] = vec[i-1]*3;
	}
}

void solve(){
	unsigned long long n,m;
	std::cin >> m;
	n = m;
	std::vector<bool> arr(39,true);
	for(int i = 38; i >= 0; i--){
		if(n >= vec[i]){
			n = n - vec[i];
			arr[i] = false;
		}
	}

	// print_vec(arr);

	if(n > 0){
		for(int i = 0; i < 39; i++){
			if(arr[i] && vec[i] >= n){
				arr[i] = false;
				i = 40;
			}
		}
	}	

	unsigned long long ans = 0;
	for(int i = 0; i < 39; i++){
		if(!arr[i]){
			ans += vec[i];
		}
	}

	for(int i = 38; i >=0; i--){
		if(!arr[i]){
			if(ans >= vec[i] + m){
				ans -= vec[i];
			}
		}
	}

	for(int i = 0; i < 39; i++){
		if(vec[i] > m && vec[i] < ans){
			ans = vec[i];
		}
	}

	std::cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	pre_calc();
	// print_vec(vec);

	int t;
	std::cin >> t;
	while(t--){
		solve();
	}

	// 	solve();
	return 0;
}