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

void f101(int a,int b){
	int gc=__gcd(a,b);
	std::cout<<a/gc<<" "<<b/gc<<"\n";
}

void f100(){
	int n,t,x,y,z;
	std::cin>>n>>t>>x>>y>>z;
	if(t==1){
		if(x<y){
			if(z<y){
				f101(y-1,2*n+1);
				return;
			}
			else{
				f101(2*n-y,2*n+1);
				return;
			}
		}
		else{
			if(z<y){
				f101(2*n+1-y+1,2*n+1);
				return;
			}
			else{
				f101(y+1,2*n+1);
				return;
			}
		}
	}
	if(t==2){
		if(x==z){
			std::cout<<0<<" "<<2*n+1<<"\n";
			return;
		}

		f101(2*n+1-2*y,2*n+1);
		return;
	}
	if(t==3){
		if(x<y){
			if(z<y){
				f101(y-1,2*n+1);
				return;
			}
			else{
				f101(2*n+1-y+1,2*n+1);
				return;
			}
		}
		else{
			if(z<y){
				f101(2*n-y,2*n+1);
				return;
			}
			else{
				f101(y+1,2*n+1);
				return;
			}
		}
	}
	if(t==4){
		if(x==z){
			std::cout<<0<<" "<<2*n+1<<"\n";
			return;
		}

		f101(2*n+1-2*y,2*n+1);
		return;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin>>t;
	while(t--){
		f100();
	}
	return 0;
}