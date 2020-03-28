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
	long long m;
	cin>>n>>m;
	vector<long long> t;
	vector<pair<long long, long long>> temp_range;
	for(int i=0;i<n;i++){
		int l=t.size();
		long long a,b,c;

		cin>>a>>b>>c;
		if(l==0 || t[l-1]!=a){
			t.pb(a);
			temp_range.pb({b,c});
		}
		else{
			temp_range[l-1].first = max(temp_range[l-1].first,b);
			temp_range[l-1].second = min(temp_range[l-1].second,c);
		}
	}

	bool flag=true;
	long long curr_time=0,del_t,high=m,low=m;
	for(int i=0;i<t.size();i++){
		del_t=t[i]-curr_time;
		curr_time=t[i];
		low=max(low-del_t,temp_range[i].first);
		high=min(high+del_t,temp_range[i].second);

		// cout<<curr_time << " " << del_t << " " << low << " " << high << "\n";
		if(high<temp_range[i].first || low>temp_range[i].second)
			flag=false;
	}

	if(flag)
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