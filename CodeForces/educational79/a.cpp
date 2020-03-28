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
	long long r,g,b;
	cin>>r>>g>>b;
	long long l1=max(r,max(g,b)),l3=min(r,min(g,b)),l2=r+g+b-l1-l3;
	if(l1<=l2+l3+1)
		cout<<"Yes\n";
	else
		cout<<"No\n";
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