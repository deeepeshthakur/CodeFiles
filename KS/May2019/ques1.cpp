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

void solve(int t){
	 int n,sr,sc,r,c,tr,tc;
	 std::cin >> n >> r >> c >> sr >> sc;
	 std::unordered_set<long long> visited;
	 visited.insert(sr*100000ll + sc);
	 std::string st;
	 std::cin >> st;
	 rep(i,0,n){
	 	if(st[i] == 'N'){
	 		tr=sr;
	 		tc=sc;
	 		while(visited.find(tr*100000ll+tc) != visited.end()){
	 			tr = tr - 1; 
	 		}
	 		visited.insert(tr*100000ll + tc);
	 		sr = tr;
	 		sc = tc;
	 	}
	 	if(st[i] == 'S'){
	 		tr=sr;
	 		tc=sc;
	 		while(visited.find(tr*100000ll+tc) != visited.end()){
	 			tr = tr + 1; 
	 		}
	 		visited.insert(tr*100000ll+tc);
	 		sr = tr;
	 		sc = tc;
	 	}
	 	if(st[i] == 'E'){
	 		tr=sr;
	 		tc=sc;
	 		while(visited.find(tr*100000ll+tc) != visited.end()){
	 			tc = tc + 1; 
	 		}
	 		visited.insert(tr*100000ll+tc);
	 		sr = tr;
	 		sc = tc;
	 	}
	 	if(st[i] == 'W'){
	 		tr=sr;
	 		tc=sc;
	 		while(visited.find(tr*100000ll+tc) != visited.end()){
	 			tc = tc - 1; 
	 		}
	 		visited.insert(tr*100000ll+tc);
	 		sr = tr;
	 		sc = tc;
	 	}
	 }

	 std::cout<<"Case #"<<t<<": "<<sr<<" "<<sc<<std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int testC,t=1;
	std::cin >> testC;
	while(t<=testC){
		solve(t);
		t++;
	}
	return 0;
}