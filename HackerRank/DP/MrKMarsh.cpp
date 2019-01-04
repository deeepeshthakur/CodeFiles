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
int mx=0,cnttt=0;
std::vector<int> mh{};
std::vector<int> dpl{},dpr{};
std::vector<bool> dph{};
std::vector<std::vector<bool>> grid{};

inline bool f150(int a,int b,int m){
	return (std::upper_bound(full(mh),m*500+a-1)==std::upper_bound(full(mh),m*500+b));
}

void f102(int a,int b,std::queue<int> qq){
	int s,e,md;
	while(!qq.empty()){
		cnttt++;
		s=qq.front();qq.pop();
		e=qq.front();qq.pop();
		if(mx>=2*(b-a+e-s+1)){
			return;
		}

		if(mx<2*(b-a+e-s)){
			if(e-s<=2){
					if(e-s==1){
						mx=(dph[e]&&dph[s]&&2*(b-a+1)>mx)?2*(b-a+1):mx;
					}
					else{
						if(e-s==2){
							mx=(dph[s]&&dph[e]&&grid[a][s+1]&&grid[b][s+1]&&2*(b-a+2))?2*(b-a+2):mx;
							mx=(dph[e]&&dph[s+1]&&2*(b-a+1)>mx)?2*(b-a+1):mx;
							mx=(dph[e-1]&&dph[s]&&2*(b-a+1)>mx)?2*(b-a+1):mx;
						}
					}
			}
			else{
				md=(s+e)/2;
				if(grid[a][md]&&grid[b][md]&&dpl[md]>=0&&dpr[md]>=0&&(dpl[md]+dpr[md])>0){
					if(dpl[md]*dpr[md]>0||dph[md]){
						mx=std::max(mx,2*(b-a+dpl[md]+dpr[md]));
					}	
				}
				if(s<md-1&&mx<2*(b-a+md-1-s))
					{qq.push(s);qq.push(md-1);}
				if(md+1<e&&mx<2*(b-a+e-md-1))
					{qq.push(md+1);qq.push(e);}
			}
		}
    }
}

void f101(int a,int b,int n,int m){
	if(mx>=2*(b-a+m-1)){
		return;
	}
	rep(i,0,m){
		dpl[i]=-1;
		dpr[i]=-1;
		dph[i]=false;
	}

	rep(i,0,m){
		if(f150(a,b,i)){
			dph[i]=true;
		}
		else{
			dph[i]=false;
		}
	}

	if(dph[0]){
		dpl[0]=0;
	}
	rep(i,1,m){
		if(dpl[i-1]<0){
			if(dph[i]){
				dpl[i]=0;
			}
			else{
				dpl[i]=-1;
			}
		}
		else{
			if(grid[a][i-1]&&grid[a][i]&&grid[b][i-1]&&grid[b][i]){
				dpl[i]=dpl[i-1]+1;
			}
			else{
				if(dph[i]){
					dpl[i]=0;
				}
			}
		}
	}

	if(dph[m-1]){
		dpr[m-1]=0;
	}
	per(i,m-2,-1){
		if(dpr[i+1]<0){
			if(dph[i]){
				dpr[i]=0;
			}
			else{
				dpr[i]=-1;
			}
		}
		else{
			if(grid[a][i]&&grid[a][i+1]&&grid[b][i]&&grid[b][i+1]){
				dpr[i]=dpr[i+1]+1;
			}
			else{
				if(dph[i]){
					dpr[i]=0;
				}
				else{
					dpr[i]=-1;
				}
			}
		}
	}
	// std::cout<<a<<" "<<b<<" "<<mx<<" "<<cnttt<<std::endl;
	std::queue<int> qq{};
	qq.push(0);qq.push(m-1);
	f102(a,b,qq);
}

void f100(int n,int m){
	std::string s;
	rep(i,0,n){
		std::cin>>s;
		rep(j,0,m){
			if(s[j]=='x'){
				grid[i][j]=false;
				mh.pb(i+500*j);
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	grid.resize(n,std::vector<bool>(m,true));
	dpl.resize(m);
	dpr.resize(m);
	dph.resize(m);

	f100(n,m);
	std::sort(full(mh));

	per(i,n-1,0){
		rep(j,i,n){
			f101(j-i,j,n,m);
		}
	}

	if(mx){
		std::cout<<mx;
	}
	else{
		std::cout<<"impossible";
	}
	std::cout<<std::endl<<cnttt<<std::endl;;
	return 0;
}