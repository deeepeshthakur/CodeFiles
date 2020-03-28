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

bool tf(string s, int l, int r){
	l--;
	r--;
	for(int i=0;l+i<=r-i;i++)
		if(s[l+i]!=s[r-i])
			return false;

	return true;
}

void solve(){
	int n;
	string s;
	cin>>s;
	n=s.size();
	if(tf(s,1,n) && tf(s,1,(n-1)/2) && tf(s,(n+3)/2,n))
		cout<<"Yes\n";
	else
		cout<<"No\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}