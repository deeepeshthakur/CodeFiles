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

inline long long tn(long long a){
	if(a%2==1)
		return a*((a+1)/2);
	return (a/2)*(a+1);
}
void solve(){
	long long t;
	cin>>t;
	long long l=0,r=3*(int(1e9)/2),mid;
	while(r-l>1){
		mid=(l+r)/2;
		if(tn(mid) < t)
			l = mid;
		else
			r = mid;
	}

	if(tn(l)==t || tn(r)==t){
		cout << (tn(l)==t ? l : r) << "\n";
	}
	else{
		cout << "-1\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// CodeChef Template
	int t;       
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}