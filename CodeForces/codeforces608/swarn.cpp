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
	long long sx,sy;
	cin>>n>>sx>>sy;
	// vector<long long> x(n,0ll),y(n,0ll);
	vector<int> x{1,1,0,-1,-1,-1,0,1},y{0,1,1,1,0,-1,-1,-1},ctr(8,0);
	for(int i=0;i<n;i++){
		long long a,b;
		cin>>a>>b;
		a-=sx;
		b-=sy;
		for(int j=0;j<8;j++){
			if(abs(x[j])+abs(y[j])+abs(a-x[j])+abs(b-y[j])<=abs(a)+abs(b)){
				ctr[j]++;
			}
		}
	}

	long long mx=0,ma=0,mb=0;
	for(int i=0;i<8;i++){
		if(mx<ctr[i]){
			mx=ctr[i];
			ma=x[i];
			mb=y[i];
		}
	}
	cout<<mx<<"\n"<<sx+ma<<" "<<sy+mb<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}