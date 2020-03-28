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

bool invert_f(vector<int>& a){
	int n=a.size();
	vector<int> ans;
	for(int i=0;i<n;i++){
		if(i<n-1 && a[i]==-1){
			a[i]=-a[i];
			a[i+1]=-a[i+1];
			ans.pb(i+1);
		}
	}
	if(a[n-1]==1){
		cout<<ans.size()<<"\n";
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<(i<ans.size()-1?" ":"\n");
		}
		return true;
	}
	return false;
}

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int> a(n,0),b(n,0),c(n,0);
	for(int i=0;i<n;i++){
		if(s[i]=='W'){
			a[i]=-1;
			b[i]=1;
		}
		else{
			a[i]=1;
			b[i]=-1;
		}
	}
	if(invert_f(a)){
		return;
	}

	if(invert_f(b)){
		return;
	}

	cout<<"-1\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}