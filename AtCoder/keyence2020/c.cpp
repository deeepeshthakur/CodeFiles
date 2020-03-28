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
const long long MOD=1e9;

void print_vec(vector<int>& a,int n=-1){
	n = (n==-1 ? a.size():n);
	for(int i=0;i<n;i++)
		cout << a[i] << (i<n-1 ? " ":"\n");
}

void print_vec(vector<long long>& a,int n=-1){
	n=(n==-1 ? a.size():n);
	for(int i=0;i<n;i++)
		cout << a[i] << (i<n-1 ? " ":"\n");
}

void solve(){
	int n,k,s;
	cin>>n>>k>>s;
	vector<int> ans;
	if(s<10){
		for(int i=0;i<n;i++){
			if(i<k){
				ans.pb(s);
			}
			else
				ans.pb(s+1);
		}
	}
	else{
		for(int i=0;i<n;i++){
			if(i<k){
				ans.pb(s);
			}
			else
				ans.pb(s-1);
		}
	}

	print_vec(ans);
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}