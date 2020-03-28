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

int get_fact(int n){
	if(n==0 || n == 1){
		return 1;
	}
	return n*get_fact(n-1);
}

long double dist_f(long long a, long long b, long long c, long long d){
	return sqrt(1.0*(a-c)*(a-c) + 1.0*(b-d)*(b-d));
}

long double get_dist(int n, std::vector<int>& a, std::vector<std::pair<long long, long long>>& arr){
	long double ans =0;
	for(int i=0;i<n-1;i++){
		ans += dist_f(arr[a[i]].F, arr[a[i]].S, arr[a[i+1]].F, arr[a[i+1]].S);
	}
	return ans;
}

void solve(){
	int n;
	std::cin >> n;
	std::vector<std::pair<long long, long long>> arr(n,{0ll,0ll});
	for(int i=0;i<n;i++){
		std::cin >> arr[i].F >> arr[i].S;
	}

	std::vector<int> ind;
	for(int i=0;i<n;i++)
		ind.pb(i);

	long double dist = 0ll;
	do{
		dist += get_dist(n,ind,arr);
	}while(next_permutation(ind.begin(),ind.end()));

	std::cout << std::fixed << std::setprecision(10) << dist/(get_fact(n)*1.0) << "\n";
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
