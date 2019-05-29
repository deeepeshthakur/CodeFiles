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
	long long k1,k2,k3,z=0,mx=1e9;
	std::cout<<"Q"<<" "<<z<<" "<<z<<std::endl;
	std::cin>>k1;
	std::cout<<"Q"<<" "<<z<<" "<<mx<<std::endl;
	std::cin>>k2;
	std::cout<<"Q"<<" "<<mx<<" "<<z<<std::endl;
	std::cin>>k3;
	long long xmid =(k1-k3+mx)/2,ymid=(k1-k2+mx)/2;
	long long xl,yl,xr,yr;
	std::cout<<"Q"<<" "<<z<<" "<<ymid<<std::endl;
	std::cin>>xl;
	std::cout<<"Q"<<" "<<mx<<" "<<ymid<<std::endl;
	std::cin>>xr;
	xr=mx-xr;
	std::cout<<"Q"<<" "<<xmid<<" "<<z<<std::endl;
	std::cin>>yl;
	std::cout<<"Q"<<" "<<xmid<<" "<<mx<<std::endl;
	std::cin>>yr;
	yr=mx-yr;
	std::cout<<"A"<<" "<<xl<<" "<<yl<<" "<<xr<<" "<<yr<<std::endl;
	int tmp;
	std::cin>>tmp;
	return;		
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