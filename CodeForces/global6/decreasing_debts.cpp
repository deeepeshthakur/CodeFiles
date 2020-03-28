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
	int n,m;
	cin>>n>>m;
	vector<pair<long long,int>> dbts(n);
	for(int i=0;i<n;i++){
		dbts[i].second=i+1;
	}

	for(int i=0;i<m;i++){
		int a,b;
		long long d;
		cin>>a>>b>>d;
		dbts[a-1].first-=d;
		dbts[b-1].first+=d;
	}

	sort(full(dbts));
	vector<int> a,b;
	vector<long long> md;
	int l=0,r=n-1;
	while(l<r){
		if(dbts[l].first==0 || dbts[r].first==0){
			if(dbts[l].first==0 && dbts[r].first==0){
				l++;
				r--;
			}
			else
				if(dbts[l].first==0)
					l++;
				else
					r--;
		}
		else{
			if(abs(dbts[l].first)>abs(dbts[r].first)){
				dbts[l].first+=dbts[r].first;
				a.pb(l);
				b.pb(r);
				md.pb(abs(dbts[r].first));
				dbts[r].first=0;
				r--;
			}
			else
				if(abs(dbts[l].first)<abs(dbts[r].first)){
					dbts[r].first+=dbts[l].first;
					a.pb(l);
					b.pb(r);
					md.pb(abs(dbts[l].first));
					dbts[l].first=0;
					l++;
				}
				else{
					a.pb(l);
					b.pb(r);
					md.pb(abs(dbts[l].first));
					dbts[l].first=0;
					dbts[r].first=0;
					r--;
					l++;
				}
		}
	}
	cout<<md.size()<<"\n";
	for(int i=0;i<a.size();i++){
		cout<<dbts[a[i]].second<<" "<<dbts[b[i]].second<<" "<<md[i]<<"\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}