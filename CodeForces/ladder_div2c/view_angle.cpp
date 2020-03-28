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

void f4(std::vector<double>& v){
	std::vector<double> tmp;
	tmp.push_back(v[0]);
	for(int i = 1; i < v.size(); i++){
		if(v[i] != v[i-1])
			tmp.push_back(v[i]);
	}

	v.resize(tmp.size());
	for(int i = 0 ; i < v.size(); i++){
		v[i] = tmp[i];
	}
}

double f3(int x, int y){
	return std::atan(std::abs(1.0*y/x))*180.0/pi;
}

double f2(double a, double b){
	return (b >= a ? (b - a) : (b + 360.0 - a)); 
}

double f1(int x, int y){
	if(x >= 0 && y == 0) return 0.0;
	if(x > 0 && y > 0) return f3(x,y);
	if(x == 0 && y > 0) return 90.0;
	if(x < 0 && y > 0) return 180.0 - f3(-x,y);
	if(x < 0 && y == 0) return 180.0;
	if(x < 0 && y < 0) return 180.0 + f3(-x,-y);
	if(x == 0 && y < 0) return 270.0;
	if(x > 0 && y < 0) return 360.0 - f3(x,-y);
	return 0.0;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,x,y;
	std::cin >> n;
	std::vector<double> angles(n,0.0);
	for(int i = 0; i < n; i++){
		std::cin >> x >> y;
		angles[i] = f1(x,y);
	}

	std::sort(full(angles));
	f4(angles);
	double mxd = 0.0;
	n = angles.size();

	if(n == 1){
		std::cout << std::fixed << std::setprecision(10) << 0.0 << std::endl;
		return 0;
	}
	for(int i = 0; i < n ; i++){
		mxd = std::max(mxd,f2(angles[i],angles[(i+1)%n]));
	}
	mxd = 360.0 - mxd;
	std::cout << std::fixed << std::setprecision(10) << mxd << std::endl;
	return 0;
}