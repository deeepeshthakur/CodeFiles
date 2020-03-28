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

bool is_inside(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	return (x3<=x1 && x2 <= x4 && y3 <= y1 && y2 <= y4);
}

void solve(){
	int x1 ,y1 ,x2 ,y2 ,x3 ,y3 ,x4 ,y4 ,x5 ,y5 ,x6 ,y6;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
	std::vector<int> x{x1,x2,x3,x4,x5,x6},y{y1,y2,y3,y4,y5,y6};
	std::sort(full(x));
	std::sort(full(y));
	bool flag = false;

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			flag = flag || (is_inside(x[i],y[j],x[i+1],y[j+1],x1,y1,x2,y2) && !is_inside(x[i],y[j],x[i+1],y[j+1],x3,y3,x4,y4) && !is_inside(x[i],y[j],x[i+1],y[j+1],x5,y5,x6,y6));
		}
	}

	if(flag){
		std::cout << "YES\n";
	}
	else{
		std::cout << "NO\n";
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

	solve();
	return 0;
}