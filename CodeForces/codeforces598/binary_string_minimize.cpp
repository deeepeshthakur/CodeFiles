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

void solve(){
	int n,k;
	std::cin >> n >> k;
	std::string str;
	std::cin >> str;

	int ones = 0;
	for(int i=0;i<n;i++){
		if(str[i] == '1'){
			ones++;
		}
	}

	if(ones == n || ones == 0){
		std::cout << str << "\n";
		return;
	}

	int i=0,j=0,ctr=0;
	while(ctr < k){
		while(i < n && str[i] != '0')
			i++;

		while(j < n && str[j] != '1')
			j++;

		if(str[j] != '1' || str[i] != 0)
			break;
		else{
			if(j < i){
				if(k > ctr + i - j)
					std::swap(str[i],str[j]);
			}
		}
	}

	
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

	// 	solve();
	return 0;
}