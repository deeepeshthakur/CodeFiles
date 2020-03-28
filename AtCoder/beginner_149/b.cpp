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
	long long a,b,k;
	cin>>a>>b>>k;
	if(k<=a){
		a-=k;
		k=0;
	}
	else{
		k-=a;
		a=0;
	}

	if(k<=b){
		b-=k;
		k=0;
	}
	else{
		k-=b;
		b=0;
	}

	cout<<a<<" "<<b<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}