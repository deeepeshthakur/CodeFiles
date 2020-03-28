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
	int n,k;
	cin>>n>>k;
	vector<int> grp(n,0);

	string s;
	cin>>s;
	for(int i=0;i<k;i++){
		int c;
		cin>>c;
		int x;
		for(int j=0;j<c;j++){
			cin>>x;
			grp[x-1]=i;
		}
	}

	vector<int> ans(n,0);
	 
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}