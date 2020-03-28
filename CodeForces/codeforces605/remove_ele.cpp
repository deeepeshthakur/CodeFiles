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
	vector<int> a(n,0),sti(n,0),ite(n,0);
	for(int i=0;i<n;i++)
		cin>>a[i];
	int mx=0;
	for(int i=0;i<n;i++){
		if(i>0 && a[i]>a[i-1]){
			sti[i]=sti[i-1]+1;
		}
		else{
			sti[i]=1;
		}
		mx=max(mx,sti[i]);
	}

	for(int i=n-1;i>-1;i--){
		if(i<n-1 && a[i]<a[i+1]){
			ite[i]=ite[i+1]+1;
		}
		else{
			ite[i]=1;
		}
	}

	for(int i=1;i<n-1;i++){
		if(a[i-1]<a[i+1]){
			mx=max(mx,sti[i-1]+ite[i+1]);
		}
	}
	cout<<mx<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}	