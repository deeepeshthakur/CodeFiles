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

void f101(std::vector<std::vector<int>>& tb){
	tb[0][0]=1;
	tb[0][1]=1;
	tb[1][0]=3;
	for(int i=2;i<50;i+=2){
		if(i<50){
			tb[i][0]=tb[i-2][0]-1;
			if(tb[i][0]==0){
				tb[i][0]=4;
			}

			tb[0][i]=tb[0][i-2]-1;
			if(tb[0][i]==0){
				tb[0][i]=4;
			}
		}
	}
	for(int i=3;i<50;i+=2){
		if(i<50){
			tb[i][0]=tb[i-2][0]-1;
			if(tb[i][0]==0){
				tb[i][0]=4;
			}

			tb[0][i]=tb[0][i-2]-1;
			if(tb[0][i]==0){
				tb[0][i]=4;
			}
		}
	}
	rep(i,0,50){
		for(int j=1;i+j<50;j++){
			tb[i+j][j]=tb[i+j-1][j-1]+1;
			if(tb[i+j][j]==5){
				tb[i+j][j]=1;
			}
		}
	}
	rep(i,0,50){
		for(int j=1;i+j<50;j++){
			tb[j][i+j]=tb[j-1][i+j-1]+1;
			if(tb[j][i+j]==5){
				tb[j][i+j]=1;
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::vector<int> tb150(50,0);
	std::vector<std::vector<int>> tb250(50,{0,0}),tb(50,std::vector<int>(50,0));
	f101(tb);
	for(int i=0;2*i+1<50;i++){
		tb150[2*i]=i%2+1;
		tb150[2*i+1]=i%2+1;
	}
	for(int i=0;i<50;i++){
		if(i){
			tb250[i][0]=tb250[i-1][0]+1;
			if(tb250[i][0]==4){
				tb250[i][0]=1;
			}
			tb250[i][1]=tb250[i][0];
		}
		else{
			tb250[i][1]=1;
			tb250[i][0]=1;
		}
	}
	int q;
	std::cin>>q;
	while(q--){
		int n,m;
		std::cin>>n>>m;
		if(n*m==2||(n==2&&m==2)){
			if(n==1&&m==2){
				std::cout<<1<<"\n"<<"1 1\n";
			}
			if(n==2&&m==1){
				std::cout<<1<<"\n"<<"1\n1\n";
			}
			if(n==2&&m==2){
				std::cout<<2<<"\n"<<"1 2\n1 2\n";
			}
		}
		else{
			if(std::min(n,m)>2){
				std::cout<<4<<"\n";
				rep(i,0,n){
					rep(j,0,m){
						std::cout<<tb[i][j]<<" ";
					}
					std::cout<<"\n";
				}
			}
			else{
				if(std::min(n,m)==2){
					if(n==2){
						std::cout<<3<<"\n";
						rep(j,0,n){
							rep(i,0,m){
								std::cout<<tb250[i][j]<<" ";
							}
							std::cout<<"\n";
						}
					}
					else{
						std::cout<<3<<"\n";
						rep(i,0,n){
							rep(j,0,m){
								std::cout<<tb250[i][j]<<" ";
							}
							std::cout<<"\n";
						}
					}
				}
				else{
					if(std::max(n,m)==1){
						std::cout<<1<<"\n"<<1<<"\n";
					}
					else{
						if(n==1){
							std::cout<<2<<"\n";
							rep(i,0,m){
								std::cout<<tb150[i]<<" ";
							}
							std::cout<<"\n";
						}
						else{
							std::cout<<2<<"\n";
							rep(i,0,n){
								std::cout<<tb150[i]<<"\n";
							}
						}
					}
				}
			}
		}
	}
	return 0;
}