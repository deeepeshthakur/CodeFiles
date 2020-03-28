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
	vector<vector<int>> pass(101);
	for(int i=0;i<n;i++){
		cin>>a>>b;
		pass[a].pb(b);
	}

	bool flag = false;
	double fare = 0.0;
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=0;i<=100;i++){
		int curr_out=0,pass_num=pq.size();
		while(!pq.empty() && pq.top() <= i){
			pq.pop();
			curr_out++;
		}

		if(curr_out>0){
			if(pass_num==1){
				
			}
			if(pass_num==2){

			}
			if(pass_num>=3){
				
			}
		}
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