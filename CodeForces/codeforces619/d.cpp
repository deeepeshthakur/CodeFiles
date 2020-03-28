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

// r=1 
// l=2
// u=3
// d=4

void solve(){
	int n,m,k;
	cin>>n>>m;
	cin>>k;
	if(k>4*m*n-2*n-2*m){
		cout<<"NO\n";
		return;
	}

	if(n==1 && m == 1){
		cout<<"NO\n";
		return;
	}

	vector<pair<int,char>> pth;
	int curr_row=0;
	while(curr_row<m-1){
		if(n-1>0){
			pth.pb({n-1,'D'});
			pth.pb({n-1,'U'});
		}		
		pth.pb({1,'R'});
		curr_row++;
	}
	if(n-1>0)
		pth.pb({n-1,'D'});
	int curr_col=n-1;
	while(curr_col>0){
		if(m-1>0){
			pth.pb({m-1,'L'});
			pth.pb({m-1,'R'});
		}
		pth.pb({1,'U'});
		curr_col--;
	}
	if(m-1>0)
		pth.pb({m-1,'L'});
	vector<pair<int,char>> ans;

	for(int i=0;i<pth.size();i++){
		if(k>0){
			ans.pb({min(k,pth[i].first),pth[i].second});
			k-=pth[i].first;
		}
	}

	cout<<"YES\n";
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++)
		cout<<ans[i].first << " " << ans[i].second << "\n";

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t=1;
	while(t--){
		solve();
	}
	return 0;
}