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
	vector<int> a(n,0);
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ctr=0,curr=1;
	for(int i=0;i<n;i++){
		if(a[i]==curr){
			curr++;
			ctr++;
		}
	}
	if(ctr>0)
		cout<<n-ctr<<"\n";
	else
		cout<<"-1\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}