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
const long long expo = int(1e9);

bool is_valid(long long x, long long y){
	return (x >= 0ll) && (y >= 0ll) && (x < int(1e9)) && (y < int(1e9));
}

long long f3(long long x, long long y){
	return x*expo + y;
}

bool f2(long long x, long long y, std::vector<long long>& pnts){
	return std::binary_search(full(pnts), f3(x,y));
}

int f1(long long x, long long y, std::vector<long long>& points){
	return int(std::distance(points.begin(), std::lower_bound(full(points),f3(x,y))));
}

void f5(long long x, long long y, std::vector<long long>& pnts, std::vector<long long>& path, std::queue<std::pair<long long, long long>>& bfsQ, long long pl){
	if(is_valid(x,y) && f2(x,y,pnts)){
		int ind = f1(x,y,pnts);
		if(path[ind] == -1){
			path[ind] = pl + 1;
			bfsQ.push({x,y});
		}
	}
}

void bfs(long long x, long long y, std::vector<long long>& pnts, std::vector<long long>& path, std::queue<std::pair<long long, long long>>& bfsQ){
	long long pt = path[f1(x,y,pnts)]; 
	f5(x-1,y,pnts,path,bfsQ,pt);
	f5(x+1,y,pnts,path,bfsQ,pt);
	f5(x,y-1,pnts,path,bfsQ,pt);
	f5(x,y+1,pnts,path,bfsQ,pt);
	f5(x-1,y-1,pnts,path,bfsQ,pt);
	f5(x+1,y-1,pnts,path,bfsQ,pt);
	f5(x-1,y+1,pnts,path,bfsQ,pt);
	f5(x+1,y+1,pnts,path,bfsQ,pt);
}

long long f0(long long sx, long long sy, long long ex, long long ey, std::vector<long long>& pnts){
	int n = pnts.size();
	std::vector<long long> path(n,-1ll);
	std::queue<std::pair<long long, long long>> bfsQ;
	path[f1(sx,sy,pnts)] = 0ll;
	bfsQ.push({sx,sy});
	while(!bfsQ.empty()){
		long long x = bfsQ.front().F, y = bfsQ.front().S;
		bfsQ.pop();
		bfs(x,y,pnts,path,bfsQ);
	}

	return path[f1(ex,ey,pnts)];
}

void solve(){
	long long x1,y1,x2,y2,n;
	std::vector<long long> all_points;
	std::cin >> x1 >> y1 >> x2 >> y2 >> n;
	x1--;y1--;x2--;y2--;
	for(int i = 0; i < n; i++){
		long long a,b,r;
		std::cin >> r >> a >> b;
		a--;
		b--;
		r--;
		for(;a <= b; a++){
			all_points.push_back(r*expo + a);
		}
	}

	std::sort(full(all_points));
	long long ans = f0(x1,y1,x2,y2,all_points);
	std::cout << ans << std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}