#include<bits/stdc++.h>
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

void solve(){
	int h,w;
	cin>>h>>w;
	vector<vector<int>> grid(h,vector<int>(w,0));
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++){
			int a;
			cin>>a;
			grid[i][j]=a;
		}
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++){
			int a;
			cin>>a;
			grid[i][j]= abs(grid[i][j]-a);
		}


	vector<vector<vector<pair<bool,bool>>>> dp(h,vector<vector<pair<bool,bool>>>(w,vector<pair<bool,bool>>(6600,{false,false})));
	dp[0][0][grid[0][0]].F = true;
	dp[0][0][grid[0][0]].S = true;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(i>0 || j>0){
				if(i>0){
					int x=i-1,y=j,ab=grid[i][j];
					for(int k=0;k<=6400;k++){
						if(dp[x][x][k].F){
							dp[i][j][k+ab].F=true;
							if(k-ab<0){
								dp[i][j][abs(k-ab)].S=true;
							}
							else{
								dp[i][j][k-ab].F = true;
							}
						}

						if(k > 0 && dp[x][y][k].S){
							dp[i][j][k+ab].S = true;
							if(k-ab<=0){
								dp[i][j][abs(k-ab)].F=true;
							}
							else{
								dp[i][j][k-ab].S=true;
							}
						}
					}
				}

				if(j>0){
					int x=i,y=j-1,ab=grid[i][j];
					for(int k=0;k<=6400;k++){
						if(dp[x][x][k].F){
							dp[i][j][k+ab].F=true;
							if(k-ab<0){
								dp[i][j][abs(k-ab)].S=true;
							}
							else{
								dp[i][j][k-ab].F = true;
							}
						}

						if(k > 0 && dp[x][y][k].S){
							dp[i][j][k+ab].S = true;
							if(k-ab<=0){
								dp[i][j][abs(k-ab)].F=true;
							}
							else{
								dp[i][j][k-ab].S=true;
							}
						}
					}
				}
			}
		} 
	}

	int mn = int(1e5);
	for(int i=0;i<=6400;i++){
		if(dp[h-1][w-1][i].F || dp[h-1][w-1][i].S){
			mn = min(mn,i);
		}
	}

	cout << mn << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	solve();
	
	return 0;
}