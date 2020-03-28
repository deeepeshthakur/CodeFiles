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
	vector<vector<int>> arr(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			int t;
			cin>>t;
			arr[i].pb(t);
		}
	}
	for(int i=n-2;i>-1;i--){
		for(int j=0;j<arr[i].size();j++){
			arr[i][j]=arr[i][j]+max(arr[i+1][j],arr[i+1][j+1]);
		}
	}
	cout<<arr[0][0]<<"\n";
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