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

struct node{
	int s,e,rs,re;
	std::vector<int> srts;
};

std::vector<node> st(260000);

void f100(){
	int n,m;
	std::cin>>n>>m;
	std::vector<std::pair<int,int>> a(m,{0,0});
	rep(i,0,m){
		std::cin>>a[i].F>>a.[i].S;
		a[i].F--;
		a[i].S--;
		if(a[i].F>a[i].S){ std::swap(a[i].F,a[i].S)};
	}
	std::sort(full(a),[](std::pair<int,int>& aa,std::pair<int,int>& bb)->bool{return (aa.S<bb.S||(aa.S==bb.S&&aa.F<=bb.F))});
	{
		std::vector<std::pair<int,int>> atemp(m,{0,0});
		int i=0,j=0;
		rep(i,0,m){
			if(!(i&&(a[i-1].F==a[i].F&&b[i-1].S&&b[i].S))){
				atemp[j]=a[i];
				j++;
			}
		}
		a.resize(j);
		rep(i,0,j){
			a[i]=atemp[i];
		}
	}

	std::vector<bool> b(n,false);
	rep(i,0,m){
		b[a[i].S]=true;
	}

	




	int q;
	std::cin>>q;
	while(q--){
		int k;
		std::cin>>k;
		std::vector<std::pair<int,int>> sug(k,{0,0});
		rep(i,0,k){
			std::cin>>sug[i].F>>sug[i].S;
		}
		std::sort(full(sug),[](std::pair<int,int>& a,std::pair<int,int>& b)-> bool{return a.F<b.F;});

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