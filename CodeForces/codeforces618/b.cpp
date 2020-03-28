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
	vector<long long> a(2*n,0ll);
	for(int i=0;i<2*n;i++){
		cin>>a[i];
	}
	sort(full(a));
	long long mx=MOD;
	for(int i=0;i<2*n;i++){
		long long tmp=abs((i>n-1?a[n-1]:a[n])-a[i]);
		if(mx>tmp){
			mx=tmp;
		}
		// cout<< i << " " << tmp << "\n";
	}
	cout<<mx<<"\n";
}	

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t=1;       
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}