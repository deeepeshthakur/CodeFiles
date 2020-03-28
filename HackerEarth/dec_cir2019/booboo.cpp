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

bool tf(long long lim,int n, int m, vector<long long>& a){
	int m_count=0;
	long long curr_size=lim;
	for(int i=0;i<n;i++){
		if(curr_size>=a[i]){
			curr_size-=a[i];
		}
		else{
			m_count++;
			curr_size=lim-a[i];
		}
	}
	return m_count<m;
}

void solve(){
	int n,m;
	long long l=1ll,r=0ll,mid;
	cin>>n>>m;
	vector<long long> a(n,0ll);
	for(int i=0;i<n;i++){
		cin>>a[i];
		r+=a[i];
		l=max(l,a[i]);
	}

	// sort(rfull(a));
	while(r-l>1){
		mid=(l+r)/2ll;
		if(tf(mid,n,m,a))
			r=mid;
		else
			l=mid;
	}
	long long ans=(tf(l,n,m,a)?l:r);
	cout<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}