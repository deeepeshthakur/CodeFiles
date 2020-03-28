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

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,t;
	std::cin >> n >> t;
	std::string str;
	std::cin >> str;
	while(t--){
		std::vector<int> ind;
		for(int i = 0; i + 1 < n; i++){
			if(str[i] == 'B' && str[i+1] == 'G'){
				ind.push_back(i);
			}

			for(int i = 0; i < ind.size(); i++){
				str[i] = 'G';
				str[i+1] = 'B';
			}
		}
	}

	std::cout << str << std::endl;
	return 0;
}
