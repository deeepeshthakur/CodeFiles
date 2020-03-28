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

bool cmp_fun(const pair<long long,long long>& a,const pair<long long,long long>& b){
	return (a.second<b.second);
}

void solve(){
	int n;
	cin>>n;
	vector<pair<long long,long long>> a(n,{0,0});
	for(int i=0;i<n;i++){
		long long x,y;
		cin>>x>>y;
		a[i].first=x-y;
		a[i].second=x+y;
	}

	sort(full(a),cmp_fun);
	// for(int i=0;i<n;i++){
	// 	cout<<a[i].first<<" " <<a[i].second<<"\n";

	// }
	int ans=1;
	int r=a[0].second;
	for(int i=1;i<n;i++){
		if(r<=a[i].first){
			r=a[i].second;
			ans++;
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