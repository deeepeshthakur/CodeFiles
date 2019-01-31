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

bool is_valid(int i,int j,int n){
	return i>=1&&j>=1&&i<n-1&&j<n-1;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	std::vector<std::vector<bool>> grid(n,std::vector<bool>(n,false));
	rep(i,0,n){
		std::string s;
		std::cin>>s;
		rep(j,0,n){
			if(s[j]=='X'){
				grid[i][j]=true;
			}
		}
	}
	int ans=0;
	rep(i,0,n){
		rep(j,0,n){
			ans += (is_valid(i,j,n)&&grid[i][j]&&grid[i-1][j-1]&&grid[i+1][j-1]&&grid[i-1][j+1]&&grid[i+1][j+1]) ? 1: 0;
		}
	}

	std::cout<<ans<<"\n";
	return 0;
}