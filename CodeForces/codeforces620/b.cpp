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

bool tf(vector<string>& str, int x, int y, int m){
	bool flag=true;
	for(int i=0;i<m;i++){
		if(str[x][i]!=str[y][m-1-i])
			flag=false;
	}
	return flag;
}

bool tf_itself(vector<string>& str, int x, int m){
	bool flag=true;
	for(int i=0;i<m && m-1>=2*i;i++){
		if(str[x][i]!=str[x][m-1-i])
			flag=false;
	}
	return flag;
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<string> str(n);
	vector<bool> vis(n,true);
	for(int i=0;i<n;i++)
		cin>>str[i];

	vector<string> valid_left;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(vis[i]&&vis[j]&&tf(str,i,j,m)){
				valid_left.pb(str[i]);
				vis[i]=false;
				vis[j]=false;
			}
		}
	}

	int curr_ind=-1,len=0;
	for(int i=0;i<n;i++){
		if(vis[i] && tf_itself(str,i,m)){
			if(str[i].size()>len){
				len=str[i].size();
				curr_ind=i;
			}
		}
	}

	int ans=0;
	for(int i=0;i<valid_left.size();i++){
		ans+=2*valid_left[i].size();
	}

	if(curr_ind>-1){
		ans+=len;
	}

	cout<<ans<<"\n";
	if(ans>0){
		for(int i=0;i<valid_left.size();i++)
			cout<<valid_left[i];
		cout<<str[curr_ind];
		for(int i=valid_left.size()-1;i>=0;i--){
			for(int j=m-1;j>=0;j--){
				cout<<valid_left[i][j];
			}
		}
		cout<<"\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}