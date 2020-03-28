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

int f6(long long a, long long b){
	a /= b;
	b = int(std::sqrt(1.0*a));
	if(b-1 > 0 && (b-1)*(b-1) == a)
		return b-1;
	if(b*b == a)
		return b;

	return b+1;
}

bool f5(long long a, long long b){
	if(a%b != 0)
		return false;
	a /= b;
	double srt = std::sqrt(1.0*a);
	b = int(srt);

	if((a == (b-1)*(b-1) && b-1 > 0) || a == b*b || a == (b+1)*(b+1))
		return true;
}

bool f4(int x, int y, int a, int b){
	// std::cout << "Here  " << x << " " << y << "\n";
	int x2,y2;
	if(f5(1ll*b*y*y,1ll*x*x + 1ll*y*y)){
		x2 = f6(1ll*b*y*y,1ll*x*x + 1ll*y*y);
		if((x2*x)%y == 0 && x != x2 && y != -x2*x/y){
			y2 = -x2*x/y;

			std::cout << "YES" << "\n";
			std::cout << 0 << " " << 0 << "\n";
			std::cout << x << " " << y << "\n";
			std::cout << x2 << " " << y2 << "\n";
			return true;			
		}
	}

	return false;
}

bool f3(int x, int y, int a, int b){
	if(x*x + y*y != a)
		return f4(x,y,b,a);

	return f4(x,y,a,b);
}

bool f1(int x, int y, int a, int b){
	if(a > b)
		std::swap(a,b);

	if(a != b){
		return (f3(x,y,a*a,b*b) || f3(x,y,a*a,b*b - a*a));
	}
	
	return f3(x,y,a*a,b*b);
}

void solve(int a, int b){
	for(int x = -1000; x <= 1000; x++){
		if(x != 0){
			for(int y = -1000; y <= 1000; y++){
				if(y != 0){
					if((x*x + y*y == a*a) 
						|| (x*x + y*y == b*b) 
						|| (x*x + y*y == std::abs(a*a - b*b))){
						if(f1(x,y,a,b))
							return;
					}

				}
			}
		}
	}

	std::cout << "NO" << std::endl;
	return;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int a,b;
	std::cin >> a >> b;
	solve(a,b);
	return 0;
}