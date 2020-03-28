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

vector<int> dp;
void precalc(){
	vector<int> tmp;
	for(int i=1;i<100;i++){
		for(int j=i;j<100;j++){
			tmp.pb(i*i*i+j*j*j);
		}
	}
	sort(full(tmp));
	vector<pair<int,int>> dp_table;
	int k=-1;
	for(int i=0;i<tmp.size();i++){
		if(i>0){
			if(dp_table[k].F != tmp[i]){
				dp_table.pb({tmp[i],1});
				k++;
			}
			else{
				dp_table[k].S++;
			}
		}
		else{
			dp_table.pb({tmp[i],1});
			k++;
		}
	}

	for(int i=0;i<dp_table.size();i++){
		if(dp_table[i].S>1){
			dp.pb(dp_table[i].F);
		}
	}
}

void solve(){
	int n;
	cin>>n;
	int ans;
	if(dp[0]>=n)
		ans=-1;
	else{
		int i=0;
		while(i<dp.size() && dp[i]<n){
			ans = dp[i];
			i++;
		}
	}
	cout << ans <<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	precalc();
	int t;       
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}