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
	long long n;
	int m;
	cin>>n>>m;
	vector<long long> a(m,0ll);
	for(int i=0;i<m;i++)
		cin>>a[i];

	vector<long long> pw2;
	long long mul=1;
	while(mul<1ll*(int(1e9))){
		pw2.pb(mul);
		mul*=2ll;
	}

	vector<vector<long long>> dp(pw2.size(),vector<long long>(40,0ll));
	long long sm=0ll;
	sort(full(a));
	for(int i=0;i<m;i++){
		sm+=a[i];
	}

	if(sm<n){
		cout<<"-1\n";
		return;
	}

	priority_queue<long long,vector<long long>, greater<long long>> pq;
	for(int i=0;i<m;i++){
		pq.push(a[i]);
	}

	long long ans=0;
	mul=1;
	long long tmpn=0;
	while(n>0){

		if(n%2ll==1ll){
			while(pq.top()<mul){
				long long a=pq.top();
				pq.pop();
				long long b=pq.top();
				pq.pop();
				if(a==b){
					pq.push(a+b);
				}
				else{
					pq.push(b);
				}
			}

			while(mul<pq.top()){
				long long a=pq.top();
				pq.pop();
				ans++;
				pq.push(a/2ll);
				pq.push(a/2ll);
			}

			if(mul==pq.top()){
				tmpn+=mul;
				pq.pop();
			}
		}
		mul*=2ll;
		n/=2ll;
	}
	cout<<ans<<"\n";
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