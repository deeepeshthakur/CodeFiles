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

void print_out(long long a, long long b){
	if(a == 0ll && b == 1ll){
		std::cout << "0\n";
		return;
	}

	if(a == 1ll && b == 1ll){
		std::cout << "1\n";
		return;
	}

	std::cout << a << "/" << b << "\n";
}

bool solve(){
	long long x,y;
	std::cin >> y >> x;
	if(x == -1 && y == -1)
		return false;

	long long n,d;
	n = ((x/2)-1ll)*(x/2) + (x%2)*(x/2);
	d = (y*(y-1))/2;

	long long gc = __gcd(n,d);
	n = n/gc;
	d = d/gc;

	print_out(n,d);
	return true;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	bool flag = true;
	while(flag){
		flag = solve();
	}

	// 	solve();
	return 0;
}
