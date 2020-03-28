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
	long long t=0;
	cin>>n>>t;
	vector<long long> a(n,0ll);
	for(int i=0;i<n;i++)
		cin>>a[i];
	// priority_queue<long long> pq;
	long long s=0,mx=a[0];
	int ans=0,ind=0,del_ind;
	bool is_delete=false;
	for(int i=0;i<n;i++){
		if(mx<a[i]){
			mx=a[i];
			ind=i;
		}

		s+=a[i];
		if(s<=t && ans<i+1){
			ans=i+1;
			is_delete=false;
		}

		if(s-mx<=t && ans < i){
			is_delete=true;
			ans=i;
			del_ind=ind;
		}
	}
	
	if(is_delete){
		cout<<del_ind+1<<"\n";
	}
	else{
		cout<<"0\n";
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