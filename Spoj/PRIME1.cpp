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

void f2(long long m,std::vector<bool>& p){
  if(m==0){
    p[0]=false;
    p[1]=false;
  }
  if(m==1){
    p[0]=false;
  }

  rep(i,2,std::sqrt(m+p.size())+1){
    long long j;
    if(m%i==0){
      j=m/i;
    }
    else{
      j=m/i+1;
    }
    while(i*j<=m+p.size()-1){
      if(i*j>=m&&i*j<=m+p.size()-1&&j!=1){
        p[i*j-m]=false;
      }
      j++;
    }
  }
}

void f0(){
   long long m,n;
   std::cin>>m>>n;
   std::vector<bool> p(n-m+1,true);
   f2(m,p);
   rep(i,0,p.size()){
     if(p[i]){
       std::cout<<m+i<<"\n";
     }
   }
   std::cout<<std::endl;
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
