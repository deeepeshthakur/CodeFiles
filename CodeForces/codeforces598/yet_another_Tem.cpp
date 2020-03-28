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

bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[1] < v2[1]; 
} 


void solve(){
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> arr(n,std::vector<int>(3,0));
	for(int i=0;i<n;i++){
		std::cin >> arr[i][0];
		arr[i][1] = i;
	}

	std::sort(full(arr));
	int minm = int(1e9);
	int rem=0;

	long long ctr = 0;
	for(int i=0;i<n;i++){
		if(n - i >= 6){
			ctr += (arr[i+2][0] - arr[i][0]);
			i = i + 2;
		}
		else{
			ctr += (arr[n-1][0] - arr[i][0]);
			i = n;
		}
	}

	if(ctr < minm){
		minm = ctr;
		rem = 0;
	}

	ctr = 0;
	for(int i=0;i<n;i++){
		if(n - i >= 6){
			if(i == 0){
				ctr += (arr[std::min(i+3,n-1)][0] - arr[i][0]);
				i=i+3;
			}
			else{
				ctr += (arr[i+2][0] - arr[i][0]);
				i = i + 2;
			}
		}
		else{
			ctr += (arr[n-1][0] - arr[i][0]);
			i = n;
		}
	}

	if(ctr < minm){
		minm = ctr;
		rem = 1;
	}

	ctr = 0;
	for(int i=0;i<n;i++){
		if(n - 1 >= 6){
			if(i == 0){
				ctr += (arr[std::min(i+4,n-1)][0] - arr[i][0]);
				i=i+4;
			}
			else{
				ctr += (arr[i+2][0] - arr[i][0]);
				i = i + 2;
			}
		}
		else{
			ctr += (arr[n-1][0] - arr[i][0]);
			i = n;
		}
	}

	if(ctr < minm){
		minm = ctr;
		rem = 2;
	}

	int team_ctr = 0;
	for(int i=0;i<n;i++){
		if(n - i >= 6){
			if(i == 0){
				for(int j=0;j<=std::min(n-1,i+2+rem);j++){
					arr[j][2] = team_ctr;
				}
				i = i + 2 + rem;
			}
			else{
				arr[i][2] = team_ctr;
				arr[i+1][2] = team_ctr;
				arr[i+2][2] = team_ctr;
				i = i + 2;
			}
		}
		else{
			for(int j=i;j<n;j++){
				arr[j][2] = team_ctr;
			}
			i = n;
		}
		team_ctr++;
	}

	std::sort(arr.begin(),arr.end(),sortcol);

	std::cout << minm << " " << team_ctr << "\n";
	for(int i=0;i<n;i++){
		std::cout << arr[i][2] + 1<< (i<n-1 ? " " : "\n");
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// int t;
	// std::cin >> t;
	// while(t--){
	// 	solve();
	// }

	solve();
	return 0;
}