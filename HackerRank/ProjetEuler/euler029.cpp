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
	int n;
	cin>>n;
	vector<bool> vis(n+1,true);
	vis[0]=false;
	vis[1]=false;
	vector<long long> ctr(17,0ll);
	set<int> all_well;
	for(int i=1;i<=17;i++){
		for(int j=2;j<=n;j++){
			all_well.insert(i*j);
		}
		ctr[i-1]=all_well.size();
	}
	long long ans=0;
	for(int i=0;i<vis.size();i++){
		if(vis[i]){
			int x=0;
			long long p=i;
			while(p<=n*1ll){
				x++;
				vis[int(p)]=false;
				p*=i;
			}
			ans+=ctr[x-1];
		}
	}
	cout<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}