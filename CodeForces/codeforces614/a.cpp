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

bool tf(int f, int n, vector<int>& a){
	if(f>0 && f<=n && !binary_search(full(a),f))
		return true;
	return false;
}

void solve(){
	int n,s,k;
	cin>>n>>s>>k;
	vector<int> closed(k,0);
	for(int i=0;i<k;i++)
		cin>>closed[i];
	sort(full(closed));
	for(int i=0;i<n;i++){
		if(tf(s+i,n,closed)||tf(s-i,n,closed)){
			cout<<i<<"\n";
			return;
		}
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