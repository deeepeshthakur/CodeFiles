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

bool check_f(string& p, string& h, int ind){
	vector<int> dp(26,0);
	for(int i=0;i<p.size();i++){
		dp[int(p[i]-'a')]++;
		dp[int(h[i+ind]-'a')]--;
	}
	bool flag=true;
	for(int i=0;i<26;i++){
		flag=(flag&&(dp[i]==0));
	}
	return flag;
}

void solve(){
	string p,h;
	cin>>p>>h;
	int ps=p.size(),hs=h.size();
	bool flag=false;
	for(int i=0;i<hs && i+ps-1<hs;i++){
		flag=(flag||check_f(p,h,i));
	}
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