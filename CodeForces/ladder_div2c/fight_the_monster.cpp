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

int f4(int a, int b){
	return (a%b == 0 ? a/b : (a/b + 1));
}

bool f3(int hpy, int ay, int dy, int hpm, int am, int dm, int a, int b, int c){
	return (hpy - f4(hpm, ay - dm)*std::max(0,am - dy) > 0);
}

bool f1(int m, int hpy, int ay, int dy, int hpm, int am, int dm, int a, int b, int c){
	if(ay > dm && f3(hpy,ay,dy,hpm,am,dm,a,b,c))
		return true;
	int x,t;
	for(int y = 0; y <= 500; y++){
		if(ay + y - dm > 0)
			for(int z = 0; z <= 200; z++){
				t = f4(hpm ,ay + y - dm);
				x = hpy - t*std::max(0,am - dy - z);
				if(x > 0)
					x = 0;
				else{
					x = 1 - x;
				}

				if(m >= (a*x + b*y + c*z))
					return true;
			}
	}
	return false;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int hpy,ay,dy,hpm,am,dm,a,b,c;
	std::cin >> hpy >> ay >> dy >> hpm >> am >> dm >> a >> b >> c;
	int s = 0, e = 1000000, mid;
	while(e - s > 1){
		mid = (s+e)/2;
		if(f1(mid,hpy,ay,dy,hpm,am,dm,a,b,c)){
			e = mid;
		}
		else{
			s = mid;
		}
	}

	std::cout << (f1(s,hpy,ay,dy,hpm,am,dm,a,b,c) ? s : e) << std::endl;
	return 0;
}