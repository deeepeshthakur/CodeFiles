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
	long long a,b,c;
	cin>>a>>b>>c;
	long long x=max(a,max(b,c)),z=min(a,min(b,c)),y=a+b+c-x-z;
	long long ans = 0;
	ans += (y-z);
	x -= (y-z);
	y=z;

	if(2*z <= x){
		ans+=2*z;
	}
	else{
		ans += (x+y+z)/2;
	}

	cout <<ans<<"\n";
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