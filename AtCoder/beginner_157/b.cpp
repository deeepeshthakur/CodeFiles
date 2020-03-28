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
	vector<vector<int>> gr(3,vector<int>(3,0));
	vector<vector<bool>> vis(3,vector<bool>(3,false));

	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			cin>>gr[i][j];

	cin>>n;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++)
				if(gr[j][k]==x)
					vis[j][k]=true;
		}
	}

	bool flag=false;
	for(int i=0;i<3;i++){
		flag=(flag||(vis[i][0]&&vis[i][1]&&vis[i][2]));
		flag=(flag||(vis[0][i]&&vis[1][i]&&vis[2][i]));
	}
	if((vis[0][0]&&vis[1][1]&&vis[2][2])||(vis[0][2]&&vis[1][1]&&vis[2][0])){
		flag=true;
	}
	if(flag){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}