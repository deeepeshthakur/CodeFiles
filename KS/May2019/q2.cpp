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


void make_tree(int index,int left,int right,std::vector<std::pair<int,int>>& st,std::vector<std::pair<int,int>>& min_max){
	if(left==right){
		st[index].F = min_max[left].F;
		st[index].S = min_max[left].S;		
	}
	else{
		int mid = (left+right)/2;
		make_tree(2*index+1,left,mid,st,min_max);
		make_tree(2*index+2,mid+1,right,st,min_max);
		st[index].F = std::max(st[2*index+1].F,st[2*index+2].F);
		st[index].S = std::min(st[2*index+1].S,st[2*index+2].S);
	}	
}

void search_tree(std::pair<int,int>& ans,int index, int x, int y, int l, int r, std::vector<std::pair<int,int>>& st){
	if(l<=x && y<=r){
		ans.F = std::max(ans.F,st[index].F);
		ans.S = std::min(ans.S,st[index].S);
	}
	else{
		if(x<=r&&l<=y){
			int mid = (x+y)/2;
			search_tree(ans,2*index+1,x,mid,l,r,st);
			search_tree(ans,2*index+2,mid+1,y,l,r,st);
		}
	}
}

int get_diff(int left, int right, int c, std::vector<std::pair<int,int>>& st){
	std::pair<int,int> ans = {0,10000};
	search_tree(ans,0,0,c-1,left,right,st);
	return ans.F-ans.S;
}

bool checkF(int wid,int diff,int c, std::vector<std::pair<int,int>>& st){
	bool flag = false;
	for(int i=0;i<=c-wid&&(!flag);i++){
		int currDiff = get_diff(i,wid+i-1,c,st);
		if(currDiff<=diff){
			flag = true;
		}
	}
	return flag;
}

int f1(int x, int r, int c, int k, std::vector<std::vector<int>>& grid){
	int ans = 0;
	std::vector<std::pair<int,int>> st(1000,{0,10000});
	std::vector<std::pair<int,int>> min_max(c,{0,10000});
	for(int i=x;i<r;i++){
		for(int j=0;j<c;j++){
			min_max[j].F = (min_max[j].F < grid[i][j]) ? grid[i][j] : min_max[j].F;
			min_max[j].S = (min_max[j].S > grid[i][j]) ? grid[i][j] : min_max[j].S;
		}

		make_tree(0,0,c-1,st,min_max);
		int slimit=1,mlimit=c;
		while(mlimit-slimit > 1){
			int midlimit = (slimit+mlimit)/2;
			if(checkF(midlimit,k,c,st)){
				slimit = midlimit;
			}
			else{
				mlimit = midlimit;
			}
		}
		if(checkF(slimit,k,c,st)){
			ans = std::max(ans,slimit*(i-x+1));
		}
		if(checkF(mlimit,k,c,st)){
			ans = std::max(ans,mlimit*(i-x+1));
		}
	}
	return ans;
}

int solve(){
	int r,c,k;
	std::cin >> r >> c >> k; 
	std::vector<std::vector<int>> grid(r,std::vector<int>(c,0));
	rep(i,0,r){
		rep(j,0,c){
			std::cin >> grid[i][j];
		}
	}
	int ans=0;
	rep(i,0,r){
		ans = std::max(ans,f1(i,r,c,k,grid));
	}
	return ans;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin >> t;
	for(int i=1;i<=t;i++){
		int j = solve();
		std::cout<<"Case #"<<i<<": "<<j<<std::endl;
	}
	return 0;
}