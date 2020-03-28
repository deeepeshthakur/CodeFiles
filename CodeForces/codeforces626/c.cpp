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

int f1(string& s, int x, int y){
	bool flag=true;
	int sm=0;
	for(int i=x;i<=y;i++){
		sm+=(s[i]=='('?1:-1);
		if(sm<0)
			flag=false;
	}
	if(sm==0&&flag)
		return 0;

	return y-x+1;
}

void solve(){
	int n;
	string s;
	cin>>n;
	cin>>s;
	vector<int> a(n,0);
	int sm=0;
	for(int i=0;i<n;i++){
		a[i]=(s[i]=='('?1:-1);
		sm+=a[i];
	}

	if(sm!=0){
		cout<<"-1\n";
		return;
	}

	for(int i=1;i<n;i++){
		a[i]+=a[i-1];
	}

	int ans=0;
	int x=0,y;
	for(int i=0;i<n;i++){
		if(a[i]==0){
			y=i;
			ans+=f1(s,x,y);
			x=i+1;
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