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
	string s;
	cin>>s;
	int n=s.size();
	vector<int> ans;
	for(int i=0;i<n;i++){
		if(i+4<n){
			if(s[i]=='t' && s[i+1]=='w' && s[i+2]=='o' && s[i+3]=='n' && s[i+4]=='e'){
				ans.pb(i+2);
				s[i]='z';
				s[i+1]='z';
				s[i+2]='z';
				s[i+3]='z';
				s[i+4]='z';
			}
		}
	}

	for(int i=0;i<n;i++){
		if(i+2<n){
			if(s[i]=='t' && s[i+1]=='w' && s[i+2]=='o'){
				ans.pb(i+1);
				s[i]='z';
				s[i+1]='z';
				s[i+2]='z';
			}
		}
	}

	for(int i=0;i<n;i++){
		if(i+2<n){
			if(s[i]=='o' && s[i+1]=='n' && s[i+2]=='e'){
				ans.pb(i+1);
				s[i]='z';
				s[i+1]='z';
				s[i+2]='z';
			}
		}
	}
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]+1<<(i+1<ans.size()?" ":"");
	}
	cout<<"\n";
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