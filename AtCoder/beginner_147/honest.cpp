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

void print_vec(vector<int>& a,int n=-1){
	n = (n==-1 ? a.size():n);
	for(int i=0;i<n;i++)
		cout << a[i] << (i<n-1 ? " ":"\n");
}

void print_vec(vector<long long>& a,int n=-1){
	n=(n==-1 ? a.size():n);
	for(int i=0;i<n;i++)
		cout << a[i] << (i<n-1 ? " ":"\n");
}

void solve(){
	int n;
	cin>>n;
	int m=(1<<n)-1;
	vector<vector<int>> all_poss(m+1,vector<int>(n,0));
	for(int i=0;i<all_poss.size();i++){
		int j=i;
		for(int k=0;k<n;k++){
			all_poss[i][k]=j%2;
			j/=2;
		}
	}

	vector<vector<pair<int,int>>> que(n);
	for(int i=0;i<n;i++){
		int an;
		cin>>an;
		for(int j=0;j<an;j++){
			int x,y;
			cin>>x>>y;
			que[i].pb({x-1,y});
		}
	}

	int ans=0;
	for(int i=0;i<all_poss.size();i++){
		bool flag = true;
		for(int j=0;j<n;j++){
			for(int k=0;k<que[j].size();k++){
				if(all_poss[i][j]==1){
					if(que[j][k].S == 1){
						if(all_poss[i][que[j][k].F] == 0)
							flag=false;
					}
					else{
						if(all_poss[i][que[j][k].F] == 1)
							flag = false;
					}
				}
			}
		}

		if(flag){
			int sm = 0;
			for(int j=0;j<n;j++){
				sm+=all_poss[i][j];
				ans = max(ans,sm);
			}
		}
	}
	cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	solve();
	return 0;
}