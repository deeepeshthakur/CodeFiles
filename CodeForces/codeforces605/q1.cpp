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

long long f1(long long a,long long b, long long c){
	return abs(a-b)+abs(b-c)+abs(a-c);
}

void solve(){
	long long a,b,c;
	cin>>a>>b>>c;
	long long mn = f1(a,b,c);
	for(int i=-1;i<2;i++){
		for(int j=-1;j<2;j++)
			for(int k=-1;k<2;k++){
				mn = min(mn,f1(a+i,b+j,c+k));
			}
	}
	cout << mn << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;       
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}