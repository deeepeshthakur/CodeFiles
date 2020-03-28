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
	cin>>n;
	vector<int> a(n,0);
	for(int i=0;i<n;i++)
		cin>>a[i];

	vector<bool> ltr(n,false),rtl(n,false);

	for(int i=0;i<n;i++){
		if(i>0){
			if(ltr[i-1]&&a[i]>=i){
				ltr[i]=true;
			}
			else{
				ltr[i]=false;
			}
		}
		else{
			ltr[i]=true;
		}
	}

	for(int i=n-1;i>=0;i--){
		if(i<n-1){
			if(rtl[i+1]&&a[i]>=n-1-i){
				rtl[i]=true;
			}
			else{
				rtl[i]=false;
			}
		}
		else{
			rtl[i]=true;
		}
	}
	bool flag=false;
	for(int i=0;i<n;i++){
		if(ltr[i]&&rtl[i]){
			flag=true;
			break;
		}
	}
	if(flag){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
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