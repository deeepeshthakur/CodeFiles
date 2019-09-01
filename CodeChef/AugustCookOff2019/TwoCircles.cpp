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

long long f3(int a){
	long long ans = a;
	return ans*ans;
}

void f2(int x1, int y1, int r1, int x2, int y2, int r2){
	x1 -= x2;
	y1 -= y2;

	double xcomp, ycomp, x = x1, y = y1, d = f3(x1) + f3(y1);
	d = std::sqrt(d);
	xcomp = ((x/d)*(d + r1*1.0)) + x2*1.0;
	ycomp = ((y/d)*(d + r1*1.0)) + y2*1.0;
	std::cout << std::fixed << std::setprecision(7) << xcomp << " " << ycomp << std::endl;
}

bool f1(int x, int y, int r1, int r2){
	if(r1 > r2){
		return true;
	}

	return f3(r2 - r1) < (f3(x) + f3(y));
}

void solve(){
	int x1, y1, r1, x2, y2, r2;
	std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	bool flag = false;
	flag = f1(x1 - x2, y1 - y2, r1, r2);

	if(flag){
		std::cout << "YES" << std::endl;
	}
	else{
		std::cout << "NO" << std::endl;
	}

	if(flag){
		f2(x1, y1, r1, x2, y2, r2);
	}
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
	return 0;
}