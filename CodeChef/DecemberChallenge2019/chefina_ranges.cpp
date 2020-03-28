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
	vector<int> starts(n,0),ends(n,0);
	for(int i=0;i<n;i++){
		cin>>starts[i]>>ends[i];
	}
	sort(full(starts));
	sort(full(ends));
	int ans = int(1e8);
	int s_ind=0,e_ind=0;
	for(int i=0;i<n;i++){
		int pnt=starts[i],l=0,r=n;
		if(pnt>=ends[0]){
			while(e_ind<n-1 && ends[e_ind+1]<=pnt)
				e_ind++;
			l=e_ind+1;
		}
		if(pnt>=starts[0]){
			while(s_ind<n-1 && starts[s_ind+1]<=pnt)
				s_ind++;
			r=n-s_ind-1;	
		}
		ans=((l>0&&r>0) ? min(ans,n-l-r):ans);
	}
	s_ind=0;e_ind=0;
	for(int i=0;i<n;i++){
		int pnt=ends[i],l=0,r=n;
		if(pnt>=ends[0]){
			while(e_ind<n-1 && ends[e_ind+1]<=pnt)
				e_ind++;
			l=e_ind+1;
		}
		if(pnt>=starts[0]){
			while(s_ind<n-1 && starts[s_ind+1]<=pnt)
				s_ind++;
			r=n-s_ind-1;	
		}
		ans=((l>0&&r>0) ? min(ans,n-l-r):ans);
	}
	cout << (ans>=n-1 ? -1:ans) << "\n";		
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