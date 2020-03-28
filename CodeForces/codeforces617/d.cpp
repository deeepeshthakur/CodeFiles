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

bool cmp_f(const pair<long long, long long>& a,const pair<long long, long long>& b){
	return a.second<b.second;
}

long long get_k(long long a,long long b,long long hp){
	long long r=hp%(a+b);
	if(r>0 && r<=a)
		return 0ll;

	if(r==0)
		r=a+b;
	if(r%a==0)
		return r/a-1;
	return r/a;
}

void solve(){
	int n;
	long long a,b,k;
	cin>>n>>a>>b>>k;
	vector<pair<long long,long long>> h(n);
	for(int i=0;i<n;i++){
		cin>>h[i].first;
		h[i].second=0;
	}
	for(int i=0;i<n;i++){
		h[i].second=get_k(a,b,h[i].first);
	}

	sort(full(h),cmp_f);
	int ans=0;
	for(int i=0;i<n;i++){
		if(k>=h[i].second){
			ans++;
			k-=h[i].second;
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