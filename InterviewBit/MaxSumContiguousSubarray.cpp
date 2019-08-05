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

int solve(std::vector<int>& A){
	int ans = -1e8, curr = A[0], n = A.size();
	for(int i = 0; i < n; i++){
		if(i == 0){
			curr = A[i];
		}
		else{
			int a1 = curr, a2 = A[i], a3 = curr + A[i];
			curr = max(a1, a2) >= a3 ? a2 : a3;
		}


		ans = ans < curr ? curr : ans;
	}

	return ans;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n,0);
	for(int i = 0; i < n; i++){
		std::cin >> a[i];
	}

	std::cout << solve(a) << std::endl;
	return 0;
}