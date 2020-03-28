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
	string s,t;
	cin>>s>>t;
	vector<int> a(26,0);
	for(int i=0;i<s.size();i++)
		a[int(s[i]-'a')]++;

	for(int i=0;i<t.size();i++)
		a[int(t[i]-'a')]++;
	
	bool flag=true;
	for(int i=0;i<26;i++)
		if(a[i]%2!=0)
			flag=false;

	if(flag){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
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