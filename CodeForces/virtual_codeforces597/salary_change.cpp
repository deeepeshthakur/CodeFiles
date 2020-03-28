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

void pr_pq(std::priority_queue<long long> pq){
	while(!pq.empty()){
		std::cout << pq.top() << " ";
		pq.pop();
	}

	std::cout << "\n";
}

bool check_fun(long long med, int n, long long s_tot, std::vector<std::pair<long long, long long>>& sal, std::vector<long long>& sum_sal){
	std::cout << med << " ";
	if(sal[n/2 - 1].F > med){
		return false;
	}

	long long s = s_tot, min_max = 0ll;
	std::priority_queue<long long> pq;

	s -= sum_sal[n-1];
	for(int i=0;i<n;i++){
		if(sal[i].S >= med){
			pq.push(sal[i].F);
		}
		else{
			min_max = std::max(min_max,sal[i].F);
		}
	}

	// pr_pq(pq);

	if(pq.size() <= n/2){
		return false;
	}

	for(int i=0;i<=n/2;i++){
		s -= std::max(0ll,med-pq.top());
		pq.pop();
	}

	if(pq.size() > 0){
		min_max = std::max(min_max,pq.top());
	}

	if(s >= 0 && min_max <= med){
		return true;
	}

	return false;
}

void solve(){
	int n;
	long long s;
	std::cin >> n >> s;
	std::vector<std::pair<long long, long long>> sal(n,{0ll,0ll});
	std::vector<long long> sum_sal(n,0ll);

	for(int i=0;i<n;i++)
		std::cin >> sal[i].F >> sal[i].S;

	if(n == 1){
		std::cout << std::min(s,sal[0].S) << "\n";
		return;
	}
	

	std::sort(full(sal));

	for(int i=0;i<n;i++){
		if(i!=0){
			sum_sal[i] = sum_sal[i-1] + sal[i].F;
		}
		else{
			sum_sal[i] = sal[i].F;
		}
	}

	long long l = 0ll, r = s, mid;
	while(r - l > 1){
		mid = (r+l)/2;
		if(check_fun(mid,n,s,sal,sum_sal)){
			l = mid;
			std::cout << 1 << "\n";
		}
		else{
			r = mid;
			std::cout << 0 << "\n";
		}
	}

	std::cout << (check_fun(r,n,s,sal,sum_sal) ? r : l) << "\n";
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