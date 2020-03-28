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

int getf(int n){
	if(n==0)
		return 6;
	if(n==1)
		return 9;
	if(n==2)
		return 8;
	if(n==3)
		return 9;
	if(n==4)
		return 8;
	return 9;
}

void solve(){
	int n;
	cin>>n;
	int t=getf(n%6);
	cout<< t+n << " " << t << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}