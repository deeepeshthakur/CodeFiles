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


int f2(int a, int l, int r, std::vector<int>& vec){
	int la, ra;
	if(r - l <= 1){
		la = vec[l];
		ra = vec[r];
	}
	else{
		int	mid = (l+r)/2;
		la = f2(a,l,mid,vec);
		ra = f2(a,mid+1,r,vec);
	}

	if(la%a == 0 && ra%a == 0){
		return std::max(la,ra);
	}
	
	if(la%a == 0 || ra%a == 0){
		if(la%a == 0){
			return ra;
		}
		else{
			return la;
		}
	}

	return __gcd(la,ra);
}


int f1(int i, std::vector<int>& a){
	return a[i] + f2(a[i],0,a.size()-1,a);
}


void solve(){
	int n;
	std::cin >> n;
	std::set<int> raw_a{};
	rep(i,0,n){
		int j;
		std::cin >> j;
		raw_a.insert(j);
	}

	std::vector<int> a(raw_a.size(),0);
	int j = 0;
	for(auto itr = raw_a.begin(); itr != raw_a.end(); itr++){
		a[j++] = *itr;
	}

	int ans = 0;
	if(a.size() == 1){
		std::cout << 2*a[0] << std::endl;
		return;
	}

	std::sort(full(a));
	for(int i = 0; i < a.size(); i++){
		ans = std::max(ans, f1(i,a));
	}
	std::cout<< ans << std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin >>t;
	while(t--){
		solve();
	}
	return 0;
}