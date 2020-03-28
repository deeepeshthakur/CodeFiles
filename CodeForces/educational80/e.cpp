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
	int n,m;
	cin>>n>>m;
	vector<vector<int>> gr(n);
	vector<int> ctr(n,0);	
	vector<pair<int,int>> pos(n,{0,0});
	vector<int> mes(m,0);
	for(int i=0;i<n;i++){
		pos[i].first=i+1;
		pos[i].second=i+1;
	}
	for(int i=0;i<m;i++){
		cin>>mes[i];
		mes[i]--;
		gr[mes[i]].pb(i+1);
		pos[mes[i]]=1;
		ctr[mes[i]]=1;
	}

	for(int i=0;i<n;i++){
		if(i){
			ctr[i]+=ctr[i-1];
		}
	}
	

	for(int i=0;i<n;i++){
		if(pos[i].first!=1){

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