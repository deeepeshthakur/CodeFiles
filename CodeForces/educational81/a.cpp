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
	if(n==2){
		cout<<1<<"\n";
	}

	if(n==3){
		cout<<"7\n";
	}

	if(n==4){
		cout<<"11\n";
	}

	if(n>4){
		vector<int> ans;
		while(n>0){
			if(n>3){
				n-=2;
				ans.pb(1);
			}
			else{
				if(n==3){
					n-=3;
					ans.pb(7);
				}
				else{
					n-=2;
					ans.pb(1);
				}
			}
		}
		for(int i=ans.size()-1;i>=0;i--){
			cout<<ans[i];
		}
		cout<<"\n";
	}
	return;
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