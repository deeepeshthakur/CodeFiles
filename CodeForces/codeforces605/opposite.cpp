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

inline int cmp(int a,int b){
	if(a!=-1&&b!=-1)
		return (b<a ? b : a);
	if(a==-1)
		return b;
	return a;
}

void solve(){
	int n;
	cin>>n;
	vector<int> a(n,0);
	for(int i=0;i<n;i++)
		cin>>a[i];

	vector<vector<int>> dp(n,vector<int>(2,-1));
	vector<vector<int>> gr_in(n),gr_out(n);
	for(int i=0;i<n;i++){
		if(i+a[i]<n){
			gr_out[i].pb(i+a[i]);
			gr_in[i+a[i]].pb(i);
		}
		if(i-a[i]>=0){
			gr_out[i].pb(i-a[i]);
			gr_in[i-a[i]].pb(i);
		}
	}
	queue<pair<int,int>> qu;
	for(int i=0;i<n;i++){
		for(int j=0;j<gr_out[i].size();j++){
			if(a[gr_out[i][j]]%2==1){
				dp[i][1]=1;
				for(int k=0;k<gr_in[i].size();k++){
					if(dp[gr_in[i][k]][1]==-1){
						qu.push({gr_in[i][k],1});
					}
				}
			}
			else{
				dp[i][0]=1;
				for(int k=0;k<gr_in[i].size();k++){
					if(dp[gr_in[i][k]][0]==-1){
						qu.push({gr_in[i][k],0});
					}
				}
			}
		}
	}

	pair<int,int> tp;
	while(!qu.empty()){
		tp=qu.front();
		qu.pop();
		if(dp[tp.first][tp.second]==-1){
			if(gr_out[tp.first].size()==1){
				dp[tp.first][tp.second] = dp[gr_out[tp.first][0]][tp.second]+1;
			}
			else{
				dp[tp.first][tp.second] = cmp(dp[gr_out[tp.first][0]][tp.second],dp[gr_out[tp.first][1]][tp.second])+1;
			}

			for(int i=0;i<gr_in[tp.first].size();i++){
				if(dp[gr_in[tp.first][i]][tp.second]==-1){
					qu.push({gr_in[tp.first][i],tp.second});
				}
			}
		}	
	}

	for(int i=0;i<n;i++){
		cout << dp[i][1-(a[i]%2)] << (i<n-1 ? " ":"\n");
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}