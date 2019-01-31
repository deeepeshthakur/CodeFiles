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
const long long MOD=1e9+7;

std::vector<std::vector<long long>> fc((int)6e3,std::vector<long long>((int)6e3,0ll));

long long f104(int n,int k){
	if(n<k) return 0ll;
	if(n==k||k==0) return 1ll;
	return (fc[n-1][k-1]+fc[n-1][k])%(MOD-1);
}
void f103(){
	rep(i,0,fc.size()){
		rep(j,0,fc[i].size()){
			fc[i][j]=f104(i,j);
		}
	}
}

long long f101(long long a,long long b){
	if(a==0){
		return 0ll;
	}
	if(b==0){
		return 1ll;
	}
	if(b==1){
		return a%MOD;
	}

	long long x=f101(a,b/2);
	x*=x;
	x%=MOD;
	if(b%2){
		x*=a;
		x%=MOD;
	}
	return x%MOD;
}

long long f102(int n,int k){
	if(n<0||k<0) return 0ll;
	return fc[n][k];
}

void f100(){
	int n,k;
	std::cin>>n>>k;
	std::vector<long long> a(n,0);
	rep(i,0,n){
		std::cin>>a[i];
	}
	std::sort(full(a));
	long long ans=1;
	rep(i,0,n){
		ans*=f101(a[i],(f102(n-1,k-1)-f102(n-1-i,k-1)-f102(i,k-1)+3*(MOD-1))%(MOD-1));
		ans%=MOD;
	}
	std::cout<<ans%MOD<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	f103();
	int t;
	std::cin>>t;
	while(t--){
		f100();
	}
	return 0;
}