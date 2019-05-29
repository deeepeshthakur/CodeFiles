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
	int t;
	std::cin>>t;
	while(t--){
		int n;
		std::cin>>n;
		std::vector<std::vector<bool>> grid(n,std::vector<bool>(n,false));
		std::vector<long long> sortedCoor{};
		rep(i,0,n){
			rep(j,0,n){
				int x;
				std::cin >> x;
				if (x==1){
					grid[i][j] =true;
					sortedCoor.push_back(i*n + j);
				}
			}
		}
		std::cout<<sortedCoor.size()<<std::endl;

		int counter = 0;
		unordered_set<int> prs;
		for(int i = 0;i < sortedCoor.size();i++){
			int j = i+1;
			while(j < sortedCoor.size() && ((sortedCoor[j]/n) == (sortedCoor[i]/n))){
				counter++;
				int tmp = prs.size();
				prs.insert((sortedCoor[i]%n)*n + (sortedCoor[j]%n));
				if (prs.size() == tmp){
					std::cout << sortedCoor[i]/n + 1 << "   " << sortedCoor[i]%n + 1 << " -- " << sortedCoor[j]%n + 1 << std::endl;
				}
				j++;
			}
		}
		std::cout<< counter << "  " << prs.size() << std::endl;
	}
	return 0;
}