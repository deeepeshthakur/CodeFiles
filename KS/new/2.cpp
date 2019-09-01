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

void solve(int tc){
	long long l, r;
	std::cin >> l >> r;
	std::vector<std::vector<int>> ctr(int(r-l+1),std::vector<int>(2,0));
	for(long long i = 1; i <= 31650ll; i++){
		long long j = l/i;
		for(;j*i <= r; j++){
			if(j*i >= l && j*i <= r && j >= i){
				int ind = int(j*i - l);
				if(j%2)
					ctr[ind][0]++;
				else
					ctr[ind][1]++;

				if(i != j){
					if(i%2)
						ctr[ind][0]++;
					else
						ctr[ind][1]++;					
				}
			}
		}
	}

	int cntr = 0;
	for(int i = 0; i < ctr.size(); i++){
		if(abs(ctr[i][1] -ctr[i][0]) <= 2){
			cntr++;
		}
	}

	std::cout << "Case #" << tc << ": " << cntr << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin >> t;
	for(int i = 1; i <= t; i++){
		solve(i);
	}
	return 0;
}