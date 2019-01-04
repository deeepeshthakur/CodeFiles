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
const long long MOD=7+1e9;


std::vector<bool> pr(50,true);

void f100(){
	pr[0]=false;
	pr[1]=false;
	rep(i,2,50){
		if(pr[i]){
			int k=i;
			while(i*k<50){
				pr[i*k]=false;
				k++;
			}
		}
	}
}

bool f102(int a,int d){
	std::vector<int> nm{};
	while(a){
		nm.pb(a%10);
		a/=10;
	}
	int sm;
	bool f=true;
	rep(i,0,nm.size()-d+1){
		sm=0;
		if(nm.size()>=d){
			rep(j,0,d){
				sm+=nm[i+j];
			}
			f=(f&&pr[sm]);
		}
	}
	return f;
}

bool f103(int a){
	int t[4]={(a/1000)%10,(a/100)%10,(a/10)%10,a%10};
	if(pr[t[0]+t[1]+t[2]+t[3]]&&pr[t[0]+t[1]+t[2]]&&pr[t[1]+t[2]+t[3]])
		return true;
	return false;
}

inline bool f104(int a){
	int t[5]={(a/10000)%10,(a/1000)%10,(a/100)%10,(a/10)%10,a%10};
	return pr[t[0]+t[1]+t[2]+t[3]+t[4]];
}


int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	f100();
	std::vector<long long> ans(4*1e5+1,0);
	ans[1]=9;
	ans[2]=90;
	ans[3]=303;
	ans[4]=280;

	std::vector<int> ns{};
	rep(i,1,10000){
		if(f103(i)){
			ns.pb(i);
		}
	}

	std::vector<std::vector<int>> ind(ns.size());
	std::vector<long long> dp1(ns.size(),0),dp2(ns.size(),1);

	rep(i,0,ns.size()){
		rep(j,0,ns.size()){
			if(ns[i]%1000==ns[j]/10)
			if(f104(ns[i]*10+(ns[j]%10))){
				ind[i].pb(j);
			}
		}
	}

	rep(i,5,ans.size()){
		rep(j,0,ns.size()){
			rep(k,0,ind[j].size()){
				dp1[j]+=dp2[ind[j][k]];
			}
			dp1[j]%=MOD;
			if(ns[j]/1000>0){
				ans[i]+=dp1[j];
			}
		}
		ans[i]%=MOD;
		rep(j,0,ns.size()){
			dp2[j]=dp1[j];
			dp1[j]=0;
		}
	}

	int q;
	std::cin>>q;
	while(q--){
		int qq;
		std::cin>>qq;
		std::cout<<ans[qq]<<"\n";
	}
	return 0;
}