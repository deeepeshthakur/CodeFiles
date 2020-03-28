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

bool tf( long long d, int n, int k, vector<long long>& m){
	long long ans=0;
	for(int i=1;i<n;i++){
		if(m[i]-m[i-1]>d){
			ans+=(m[i]-m[i-1]-1)/d;
		}
	}
	return ans<=k;
}

void solve(int test_case){
	int n,k;
	cin>>n>>k;
	vector<long long> m(n,0);
	for(int i=0;i<n;i++)
		cin>>m[i];

	long long l=1,r=int(1e9),mid;
	while(r-l>1){
		mid=(l+r)/2;
		if(tf(mid,n,k,m))
			r=mid;
		else
			l=mid;
	}

	r=(tf(l,n,k,m)?l:r);
	cout<<"Case #"<<test_case<<": "<<r<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int test_cases;
	cin >> test_cases;
	for(int i=1;i<=test_cases;i++){
		solve(i);
	}
	return 0;
}