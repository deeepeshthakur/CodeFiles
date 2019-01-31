#include<bits/stdc++.h>
#define iint int
#define pll std::pair<iint,iint>
#define rep(i,a,b) for(iint i=(iint)a;i<(iint)b;i++)
#define per(i,a,b) for(iint i=(iint)a;i>(iint)b;i--)
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
const double MOD=1e9+7;

void f100(){
	int n;
	std::cin>>n;
	std::vector<std::vector<int>> a(n,std::vector<int>(n,0)),b(n,std::vector<int>(n,0));
	rep(i,0,n){
		rep(j,0,n){
			std::cin>>a[i][j];
		}
	}

	rep(i,0,n){
		rep(j,0,n){
			std::cin>>b[i][j];
		}
	}

	bool f=true;
	rep(i,0,n){
		if(a[i][i]!=b[i][i]){
			f=false;
		}
	}
	if(f){
		rep(i,0,n){
			if(f){
				bool f1=true,f2=true;
				rep(j,0,i){
					if(!(a[j][i]==b[j][i]&&a[i][j]==b[i][j])){
						f1=false;
					}
				}
				rep(j,0,i){
					if(!(a[j][i]==b[i][j]&&a[i][j]==b[j][i])){
						f2=false;
					}
				}
				if(!(f1||f2)){
					f=false;
				}

				if(!f1){
					rep(j,0,n){
						int tmp=a[j][i];
						a[j][i]=a[i][j];
						a[i][j]=tmp;
					}
				}
			}
		}
	}

	if(f){
		std::cout<<"Yes\n";
	}
	else{
		std::cout<<"No\n";
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