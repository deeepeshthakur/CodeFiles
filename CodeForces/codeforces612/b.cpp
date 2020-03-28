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

long long get_ele(long long a, long long b){
	int x,y;
	long long ans=0,mul=1;
	while(a>0 || b>0){
		x=a%3;
		y=b%3;
		if(x==y){
			ans=ans+x*mul;
		}
		else{
			ans=ans+(3-x-y)*mul;
		}
		a/=3ll;
		b/=3ll;
		mul*=3ll;
	}
	// cout<<ans<<" --------\n";
	return ans;
}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<long long> a(n,0ll);
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<k;j++){
			a[i]=a[i]*3ll+(s[j]=='S'?0ll:(s[j]=='E'?1:2));
		}
		// cout<<a[i]<<"   inp \n";
	}

	sort(full(a));
	long long ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans+=(binary_search(full(a),get_ele(a[i],a[j]))?1ll:0ll);
		}
	}
	cout<<ans/3<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}