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

void solve(){
	int x,y;
	cin >> x >> y;
	long long smm = 0;
	if(x == 1 && y == 1)
		smm += 400000;

	if(x==1){
		smm += 300000;
	}
	if(x==2){
		smm+=200000;
	}
	if(x==3)
		smm+=100000;
	x = y;
	if(x==1){
		smm += 300000;
	}
	if(x==2){
		smm+=200000;
	}
	if(x==3)
		smm+=100000;
	cout<<smm<<"\n";
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