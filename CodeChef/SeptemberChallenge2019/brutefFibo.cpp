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

void solve(int n){
	// int n = int(1e6);
	std::vector<int> arr1(n,true);
	for(int i = 0; i < n; i++)
		arr1[i] = i+1;

	bool flag0 = true, flag = true;
	while(flag0){
		std::vector<int> arr0(arr1.size()/2,0);
		for(int i = 0;i < 20 &&  i < arr1.size(); i++)
			std::cout << arr1[i] << " ";
		std::cout << std::endl;

		for(int i  = 0; i < arr0.size(); i++){
			arr0[i] = arr1[i*2+1];
		}

		arr1.resize(arr0.size());
		for(int i = 0; i < arr1.size(); i++)
			arr1[i] = arr0[i];

		flag0 = (arr1.size() >= 1);
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
	int n;
	std::cin >> n;

	solve(n);
	return 0;
}