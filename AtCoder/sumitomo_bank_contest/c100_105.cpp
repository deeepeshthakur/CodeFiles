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

void print_vec(vector<int>& a){
		int n=a.size();

	for(int i=0;i<a.size();i++)
		cout << a[i] << (i<n-1 ? " ":"\n");
}

void print_vec(vector<bool>& a){
		int n=a.size();

	for(int i=0;i<a.size();i++)
		if(a[i])
			cout << i << (i<n-1 ? " ":"\n");
}

void print_vec(vector<long long>& a){
	int n=a.size();
	for(int i=0;i<a.size();i++)
		cout << a[i] << (i<n-1 ? " ":"\n");
	cout << "\n";
}

void solve(){
	int n;
	cin >> n;
	for(int i=int(floor(n/105));i<=int(ceil(n/100));i++){
		if(n-100*i >= 0 && n-100*i <= 5*i){
			cout << "1\n";
			return;
		}
	}
	cout<<"0\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	solve();
	
	return 0;
}