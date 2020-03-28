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
	int n,q;
	cin>>n>>q;
	vector<bool> a1(n,false),a2(n,false),a3(n,false);
	vector<vector<bool>> grid(n,vector<bool>(2,false));
	int cnt=0;
	for(int i=0;i<q;i++){
		int x,y;
		cin>>y>>x;
		y--;
		x--;
		if(grid[x][y]){

		}
		else{
			grid[x][y]
		}

	} 

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}