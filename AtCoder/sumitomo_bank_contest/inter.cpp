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
	long long t1,t2,a1,a2,b1,b2;
	cin>>t1>>t2>>a1>>a2>>b1>>b2;
	if(a1 < b1){
		swap(a1,b1);
		swap(a2,b2);
	}

	long long x = (a1 - b1)*t1*60ll,y=(a2-b2)*t2*60ll;
	// cout << x << " " << y << "\n";
	if(y + x > 0ll){
		cout << "0\n";
		return;
	}

	if(y+x == 0){
		cout << "infinity\n";
		return;
	}

	y = abs(y+x);
	cout << 2ll*(x/y) + (x%y ==0 ? 0 : 1)<< "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	solve();
	
	return 0;
}