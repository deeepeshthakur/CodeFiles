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

void printq2(int i, int n, int in2){
	cout << "? ";
	cout << in2 + 1 << " ";
	for(int j=0;j<n;j++){
		cout << j+i+1;
		if(j<n-1)
			cout << " ";
		else
			cout << endl;
	}
}

void print_q(int i,int n){
	cout << "? ";
	for(int j=0;j<n;j++){
		cout << j+i+1;
		if(j<n-1)
			cout << " ";
		else
			cout << endl;
	}
}

void solve(){
	int n;
	vector<int> ans(2*n,0);
	string s="Red",t="Blue",inp;
	vector<char> cl(n+1,'R');

	for(int i=0;i<cl.size();i++){
		string st;
		print_q(i,n);
		cin >> st;
		if(st[0] ==' R'){
			cl[i]='R';
		}
		else{
			cl[i]='B';
		}
	}

	int st_ind=-1;
	for(int i=0;i<cl.size()-1;i++){
		if(cl[i] != cl[i+1]){
			if(st_ind != -1)
				st_ind = i+1;
			ans[i] = (cl[i] == 'R' ? 1 : -1);
			ans[i+n] = (cl[i] == 'R' ? -1 : 1);
		}
	}

	int curr_q = n+1; curr_ind = 0;
	while(curr_ind < 2*n && curr_q < 209){
		if(ans[curr_ind] == 0){
			string tmp_S;
			printq2(st_ind, n-1, curr_ind);
			cin >> tmp_S;
			if(tmp_S[0] == R){
				ans[curr_ind] = 1;
			}
			else{
				ans[curr_ind] = -1;
			}
			curr_ind++;
			curr_q++;
		}
		else{
			curr_ind++;
		}
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