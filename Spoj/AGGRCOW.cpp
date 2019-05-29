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

bool tf(std::vector<int>& x,int d,int c){

	bool a1=false,a2=false;
	int j=0,i=x[0],cnt=1;
	while(j<x.size()&&!a1){
		if(x[j]-i>=d){
			cnt++;
			i=x[j];
		}
		if(cnt>=c){
			a1=true;
		}
		j++;
	}
	j=x.size()-1,i=x[j],cnt=1;
	while(j>-1&&!a2&&!a1){
		if(i-x[j]>=d){
			cnt++;
			i=x[j];
		}
		if(cnt>=c){
			a2=true;
		}
		j--;
	}
	// std::cout<<"call for "<<d<<" is "<<(a1||a2)<<std::endl;
	return (a1||a2);
}

void f0(){
	int n,c;
	std::cin>>n>>c;
	std::vector<int> x(n,0);
	rep(i,0,n){
		std::cin>>x[i];
	}
	// std::vector<int> d(n-1,0);
	// std::sort(full(x));
	// rep(i,0,n-1){
	// 	d[i]=x[i+1]-x[i];
	// }
	// std::sort(full(d));
	// rep(i,0,n){
	// 	std::cout<<x[i]<<" ";
	// }
	// std::cout<<std::endl;
	// rep(i,0,n-1){
	// 	std::cout<<d[i]<<" ";
	// }
	std::cout<<std::endl;

	int l=0,h=1e9;
	while(h-l>1){
		if(tf(x,(h+l)/2,c)){
			l=(h+l)/2;
		}
		else{
			h=(h+l)/2;
		}
	}
	if(tf(x,h,c)){
		std::cout<<h<<std::endl;
		return;
	}
	
	std::cout<<l<<std::endl;
	return;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin>>t;
	while(t--){
		f0();
	}
	return 0;
}