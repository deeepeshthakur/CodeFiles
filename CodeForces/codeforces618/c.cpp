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
	vector<long long> a(n,0ll);
	for(int i=0;i<n;i++)
		cin>>a[i];
	vector<long long> l(n,0ll),r(n,0ll);
	for(int i=0;i<n;i++){
		l[i]=a[i];
		r[n-1-i]=a[n-1-i];
		if(i>0){
			l[i]=(l[i]|l[i-1]);
			r[n-1-i]=(r[n-1-i]|r[n-i]);
		}
	}

	int ind=0,mx=0;
	for(int i=0;i<n;i++){
		long long tmp=((i>0?l[i-1]:0)|(i<n-1?r[i+1]:0)),fn=((a[i]|tmp)-tmp);
		if(fn>mx){
			ind=i;
			mx=fn;
		}
	}

	cout<<a[ind]<<" ";
	for(int i=0;i<n;i++){
		if(i!=ind)
			cout<<a[i]<<" ";
	}
	cout<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}