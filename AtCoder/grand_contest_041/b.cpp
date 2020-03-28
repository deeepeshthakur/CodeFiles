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

bool tf(int num, vector<long long>& a, int n, int v, int p, long long m){
	if(a[p-1]>a[num-1]+m)
		return false;
	long long s1=0,s2=m*max(0,(v-n+num-p));
	for(int i=p-1;i<num-1;i++){
		s1+=(a[num-1]+m-a[i]);
	}
	return s1>=s2;
}

void solve(){
	int n,v,p;
	long long m;
	cin>>n>>m>>v>>p;
	vector<long long> a(n,0ll);
	for(int i=0;i<n;i++)
		cin>>a[i];

	sort(rfull(a));
	int l=p,r=n;
	while(r-l>1){
		int mid=(r+l)/2;
		if(tf(mid,a,n,v,p,m))
			l=mid;
		else
			r=mid;
	}
	int ans=(tf(r,a,n,v,p,m)?r:l);
	cout<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}