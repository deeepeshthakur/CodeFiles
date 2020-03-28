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
	int in,n;
	cin >> in >> n;
	vector<long long> curr(3,0ll),next(3,0ll);
	curr[in]=1;
	if(n > 0){
		if(curr[0] == 1 ||curr[2] == 1){
			curr[0] = 0;
			curr[1] = 1;
			curr[2] = 0;
			n--;
		}
		for(int i=0;i<n;i++){
			next[0] = curr[0]+curr[1];
			next[1] = curr[0]+curr[2];
			next[2] = curr[1]+curr[2];
			curr[0]=next[0];
			curr[1]=next[1];
			curr[2]=next[2];
		}
	}


	if(max(max(curr[0],curr[1]),curr[2])==curr[0]){
		cout << 0 << "\n";
		return;
	}
	else{
		if(max(max(curr[0],curr[1]),curr[2])==curr[1]){
			cout << 1 << "\n";
			return;
		}
	}
	cout << 2 << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// // CodeChef Template
	int t;       
	cin >> t;
	while(t--){
		solve();
	}

	// // Single test case input
	// solve();

	// // Kick Start Template	
	// int test_cases;
	// cin >> test_cases;
	// for(int i=1;i<=test_cases;i++){
	// 	solve_kick_start(i);
	// }

	return 0;
}