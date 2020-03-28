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
	int n;
	std::cin >> n;
	std::vector<std::string> str(n);

	for(int i=0;i<n;i++)
		std::cin >> str[i];

	int ones=0,zeroes=0;
	std::vector<int> sizes(n,0);

	for(int i=0;i<n;i++){
		sizes[i] = str[i].size();
		for(int j=0;j<sizes[i];j++){
			if(str[i][j] == '0'){
				zeroes++;
			}
			else{
				ones++;
			}
		}
	}

	std::sort(full(sizes));
	int ans=0;

	// {
	// 	int tmp = std::min(ones,zeroes),tmp2 = std::max(ones,zeroes);
	// 	ones = 2*tmp;
	// 	zeroes = tmp+tmp2 - ones;
	// }

	// for(int i=0;i<n;i++){
	// 	if(ones >= (sizes[i]/2)*2){
	// 		ones -= ((sizes[i]/2)*2);
	// 		ans++;
	// 	}
	// }
	// int odds=0,evens=0;
	// for(int i=0;i<n;i++){
	// 	if(sizes[i]%2==1)
	// 		odds++;
	// 	else
	// 		evens++;
	// }

	// if((ones%2 + zeroes%2)%2 == 0){
	// 	if(odds%2 == 0 && odds > 0)
	// 		ans = n;
	// 	else
	// 		ans = n-1;
	// }
	// else{
	// 	if(odds%2 == 0 && odds > 0)
	// 		ans = n-1;
	// 	else
	// 		ans = n;
	// }

	// int ans = 0;
	for(int i=0;i<n;i++){
		ans += (sizes[i]/2);
	}

	if(ans <= ((ones/2) + (zeroes/2)))
		ans = n;
	else
		ans = n - 1;

	std::cout << ans << "\n";
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