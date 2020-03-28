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

bool is_sub(string& s, string& t){
	if(s.size()>=t.size()){
		
	}
	return false;
}

bool t1(string& s, string& t){
	return is_sub(s,t);
}

void solve(){
	string s,t;
	cin>>s>>t;
	if(t1(s,t)||t2(s,t))
		cout<<"YES\n";
	else
		cout<<"NO\n";
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