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
	int n,q,k;
	cin>>n>>q>>k;
	vector<pair<long long,int>> s(n,{0ll,0}),e(n,{0ll,0});
	vector<pair<long long,long long>> param(n,{0ll,0ll});
	for(int i=0;i<n;i++){
		s[i].second=i;
		e[i].second=i;
		cin>>param[i].first>>param[i].second>>s[i].first>>e[i].first;
	}

	vector<pair<long long,long long>> queries(q,{0ll,0ll});
	for(int i=0;i<q;i++){
		cin>>queries[i].second >> queries[i].first;
	}

	sort(full(s));
	sort(full(e);
	sort(full(queries));
	long long mul=(1ll*int(1e7))*(1ll*int(1e6)), max_delta=100ll*int(1e8);
	vector<vector<long long>> 

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}