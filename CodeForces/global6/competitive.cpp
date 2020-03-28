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

bool val_fun(string s){
	int n=s.size();
	vector<int> a(n,0);
	for(int i=0;i<n;i++){
		a[i]=int(s[i]-'0');
	}
	sort(full(a));
	int sm=0;
	bool flag1=false,flag2=false;
	flag1=(a[0]==0);
	for(int i=1;i<n;i++){
		sm+=a[i];
		flag2=(flag2||(a[i]%2==0));
	}
	return (flag1&&flag2&&(sm%3==0));
}

void solve(){
	int n;
	cin>>n;
	vector<int> ans(n,0);
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		ans[i]=(val_fun(s)?1:0);
	}
	for(int i=0;i<n;i++){
		cout<<(ans[i]==1?"red\n":"cyan\n");
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t=1;
	while(t--){
		solve();
	}
	return 0;
}