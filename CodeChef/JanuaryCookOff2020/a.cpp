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

void dfs(int ind, vector<vector<int>>& gr, vector<bool>& vis1, vector<long long>& sc, vector<long long>& fin_sc){
	if(vis1[ind]){
		vis1[ind]=false;
		long long ans=0;
		long long tmp=0;
		for(int i=0;i<gr[ind].size();i++){
			if(vis1[gr[ind][i]]){
				dfs(gr[ind][i],gr,vis1,sc,fin_sc);
				tmp+=(sc[gr[ind][i]]*(sc[gr[ind][i]]-1)/2)%MOD;
				tmp%=MOD;
				ans+=sc[gr[ind][i]];
			}
		}

		if(ans==0){
			sc[ind]=1;
		}
		else{
			sc[ind]=ans;
			fin_sc[ind]=((sc[ind]*(sc[ind]-1)/2)%MOD+MOD-tmp)%MOD;
		}
	}	
}

void solve(){
	int n;
	cin>>n;
	vector<long long> a(n,0ll);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<vector<int>> gr(n); 
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		gr[x].pb(y);
		gr[y].pb(x);
	}

	if(n==1){
		cout<<0<<"\n";
		return;
	}
	if(n==2){
		cout<<(a[0]+a[1])%MOD<<"\n";
		return;
	}

	vector<bool> vis(n,true),is_leaf(n,false);
	vector<long long> sc(n,0);
	vector<long long> fin_sc(n,0ll);
	long long leaf=0;
	for(int i=0;i<n;i++){
		if(gr[i].size()==1){
			leaf++;
			is_leaf[i]=true;
		}
	}

	for(int i=0;i<n;i++){
		if(!is_leaf[i]){
			dfs(i,gr,vis,sc,fin_sc);
			break;
		}
	}

	for(int i=0;i<n;i++){
		if(is_leaf[i]){
			fin_sc[i]=(leaf-1);
		}
		else{
			fin_sc[i]+=((sc[i])*(leaf-sc[i]))%MOD;
			fin_sc[i]%MOD;
		}
	}

	// print_vec(sc);
	// print_vec(fin_sc);
	sort(full(fin_sc));
	sort(full(a));
	long long ans=0;
	for(int i=0;i<n;i++){
		ans+=(a[i]*fin_sc[i])%MOD;
		ans%=MOD;
	}
	cout<<ans<<"\n";
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

