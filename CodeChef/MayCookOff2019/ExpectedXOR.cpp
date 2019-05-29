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

double f1(std::vector<int>& bts, std::vector<double>& p){
	double alp1,alp2,t1,t2;
	int n = bts.size();
	for(int i=0;i<n;i++){
		if(i>0){
			if(bts[i] == 1){
				t1 = alp1*(1-p[i]) + alp2*p[i];
				t2 = alp2*(1-p[i]) + alp1*p[i];
				alp1 = t1;
				alp2 = t2;
			}
		}
		else{
			if(bts[i]==0){
				alp1 = 1;
				alp2 = 0;
			}
			else{
				alp1 = 1-p[i];
				alp2 = p[i];
			}
		}
	}

	return alp2;
}

void solve(){
	int n;
	std::cin>>n;
	std::vector<int> b(n,0);
	std::vector<double> p(n,0.0);
	rep(i,0,n){
		std::cin >> b[i];
	}

	rep(i,0,n){
		std::cin >> p[i];
	}

	std::vector<int> bts(n,0);
	double exp=0;
	unsigned long long mxx = 2e18,powr=1;
	while(mxx/2){
		for(int i=0;i<n;i++){
			bts[i] = b[i]%2;
			b[i]   = b[i]/2;
		}

		exp += f1(bts,p)*powr;
		powr = powr*2;
		mxx = mxx/2;
	}

	std::cout<<std::fixed<<std::setprecision(15)<<exp<<std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin >> t;
	while(t--){
		solve();
	}
	return 0;
}