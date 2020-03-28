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

bool cmp_fun(const pair<int,int>& a,const pair<int,int>& b){
	return a.second<b.second || (a.second==b.second && a.first<b.first);
}

void solve(){
	int n;
	cin>>n;
	vector<pair<int,int>> pnts(n,{0,0});
	for(int i=0;i<n;i++)
		cin>>pnts[i].first>>pnts[i].second;
	sort(full(pnts),cmp_fun);
	bool flag=true;
	for(int i=0;i<n;i++){
		if(i+1<n){
			if(!(pnts[i].first<=pnts[i+1].first && pnts[i].second<=pnts[i+1].second)){
				flag=false;
			}
		}
	}
	if(flag){
		cout<<"YES\n";
		int x=0,y=0;
		for(int i=0;i<n;i++){
			int delx=pnts[i].first-x,dely=pnts[i].second-y;
			for(int j=0;j<delx;j++){
				cout<<"R";
			}
			for(int j=0;j<dely;j++)
				cout<<"U";
			x=pnts[i].first;
			y=pnts[i].second;
		}
		cout<<"\n";
	}else{
		cout<<"NO\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;       
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}