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
	vector<int> even,odd;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x%2==0){
			even.pb(i+1);
		}
		else{
			odd.pb(i+1);
		}
	}

	if(even.size()>0 || odd.size()>1){
		if(even.size()>0){
			cout<<"1\n"<<even[0]<<"\n";
		}
		else{
			cout<<"2\n"<<odd[0]<<" "<<odd[1]<<"\n";
		}
	}
	else{
		cout<<"-1\n";
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