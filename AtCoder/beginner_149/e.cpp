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

long long pow_mod(long long a, long long b){
	if(a == 0)
		return 0ll;
	if(b == 0)
		return 1ll;
	if(b == 1)
		return a%MOD;
	long long x = pow_mod(a,b/2);
	x = (x*x)%MOD;
	if(b%2==1)
		return (x*a)%MOD;
	return x;
}

void dfs(int ind,vector<bool>& vis, vector<vector<int>>& gr, vector<vector<int>>& val, vector<int>& tot){
	if(vis[ind]){
		int tmp=0;
		vis[ind]=false;
		for(int i=0;i<gr[ind].size();i++){
			if(vis[gr[ind][i]]){
				dfs(gr[ind][i],vis,gr,val,tot);
				val[ind][i]=tot[gr[ind][i]];
				tmp+=tot[gr[ind][i]];
			}
		}
		bool flag=false;
		for(int i=0;i<gr[ind].size();i++){
			if(val[ind][i]==-1){
				if(flag){
					cout<<"Something wrong\n";
				}
				val[ind][i]=n-1-tot;
				flag=true;
			}
		}
	}
}

long long get_val(int n,int& num, int& den, vector<int>& val){
	int sm=n-1;
	long long tmp_num=num,tmp_den=den;
	for(int i=0;i<val.size();i++){
		if(val.size()>2){

		}

		if(val.size()==1){

		}
	}
}

void solve(){
	int n;
	cin>>n;
	vector<vector<int>> gr(n);
	vector<vector<int>> val(n);
	vector<int> tot(n);
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		gr[x-1].pb(y);
		gr[y-1].pb(x);
		val[x-1].pb(-1);
		val[y-1].pb(-1);
	}
	vector<bool> vis(n,true);

	dfs(0,vis,gr,val,tot);
	long long num=0,den=1;
	for(int i=0;i<n;i++){
		get_val(n,num,den,val[i]);
	}
	cout<<(num*pow_mod(den,MOD-2))%MOD<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}