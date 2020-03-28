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
	long long x;
	cin>>n>>x;
	vector<int> sc(n,0);
	string s;
	cin>>s;
	long long capx=0;
	for(int i=0;i<n;i++){
		if(i>0){
			sc[i]+=sc[i-1];
		}

		sc[i]+=(s[i]=='0'?1:-1);
	}

	capx=sc[n-1];
	if(capx==0){
		bool flag=false;
		for(int i=0;i<n;i++){
			if(sc[i]==x)
				flag=true;
		}
		if(flag){
			cout<<"-1\n";
			return;
		}
		else{
			cout<<"0\n";
			return;
		}
	}
	else{
		int ans=0;
		long long tmp=0;
		for(int i=0;i<n;i++){
			tmp=x-sc[i];
			if(tmp%capx==0&&(tmp/capx)>=0){
				ans++;
			}
		}
		if(x==0){
			ans++;
		}
		cout<<ans<<"\n";
		return;
	}
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