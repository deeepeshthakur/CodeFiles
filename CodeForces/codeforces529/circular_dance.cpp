#include<bits/stdc++.h>
#define ll int
#define pll std::pair<ll,ll>
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define per(i,a,b) for(ll i=(ll)a;i>(ll)b;i--)
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

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n;
	std::cin>>n;
	if(n==3){
		std::cout<<"1 2 3\n";
		return 0;
	}

	std::vector<std::vector<int>> a(n,{0,0});
	std::vector<int> b(n,-1);
	rep(i,0,n){
		std::cin>>a[i][0]>>a[i][1];
		a[i][0]--;
		a[i][1]--;
	}

	rep(i,0,n){
		int c=a[i][0],d=a[i][1];
		if(a[c][0]==d||a[c][1]==d){
			b[i]=c;
		}
		else{
			b[i]=d;
		}
	}

	std::cout<<"1 ";
	int cnt=0;
	while(b[cnt]){
		std::cout<<b[cnt]+1<<" ";
		cnt=b[cnt];
	}
	std::cout<<"\n";
	return 0;
}