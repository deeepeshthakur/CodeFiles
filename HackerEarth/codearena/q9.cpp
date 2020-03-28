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

// long long pow_mod(long long a, long long b){
// 	if(a == 0)
// 		return 0ll;
// 	if(b == 0)
// 		return 1ll;
// 	if(b == 1)
// 		return a%MOD;
// 	long long x = pow_mod(a,b/2);
// 	return ((b%2 == 1) ? (((x*x)%MOD)*a)%MOD : (x*x)%MOD);
// }

// long long pow_int(long long a, long long b){
// 	if(a==0)
// 		return a;
// 	if(b==0)
// 		return 1;
// 	if(b==1)
// 		return a;
// 	long long x = pow_int(a,b/2);
// 	return ((b%2 == 1) ? x*x*a : x*x);
// }

// int pow_int(int a, int b){
// 	if(a==0)
// 		return a;
// 	if(b==0)
// 		return 1;
// 	if(b==1)
// 		return a;
// 	int x = pow_int(a,b/2);
// 	return ((b%2 == 1) ? x*x*a : x*x);
// }


// void print_vec(vector<int>& a){
// 	for(int i=0;i<a.size();i++)
// 		cout << a[i] << (i<n-1 ? " ":"\n");
// }

// void print_vec(vector<long long>& a){
// 	for(int i=0;i<a.size();i++)
// 		cout << a[i] << (i<n-1 ? " ":"\n");
// }

// void solve_kick_start(int test_case){

// }

int f1(vector<int>& s){
	int n=s.size();
	int ans=0,i=0;
	while(i<n-1 && s[i]==s[n-1-i]){
		ans++;
		i++;
	}
	return ans;
}

void solve(){
	int n,q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<vector<int>> ctr(n,vector<int>(26,0));
	for(int i=0;i<n;i++){
		if(i > 0){
			for(int j=0;j<26;j++)
				ctr[i][j] += ctr[i-1][j];
		}
		ctr[i][int(s[i]-'a')]++;
	}

	vector<int> st(26,0);
	for(int i=0;i<q;i++){
		int l,r;
		cin >> l >> r;
		l--;
		r--;
		for(int j=0;j<26;j++){
			st[j] = (ctr[r][j] - (l > 0 ? ctr[l-1][j] : 0))%26;
		}
		// for(int j=0;j<26;j++)
		// 	cout<<char('a'+st[j]);
		// cout << "\n";
		int ans = f1(st);
		if(ans > 0)
			for(int j=0;j<ans;j++)
				cout<<char('a'+st[j]);
		else
			cout << "None";
		cout<<"\n";
	}

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// // CodeChef Template
	// int t;       
	// cin >> t;
	// while(t--){
	// 	solve();
	// }

	// Single test case input
	solve();

	// // Kick Start Template	
	// int test_cases;
	// cin >> test_cases;
	// for(int i=1;i<=test_cases;i++){
	// 	solve_kick_start(i);
	// }

	return 0;
}
