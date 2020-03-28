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

bool solve(){
	int n,m;
	std::cin >> n;
	if(n == 0)
		return false;

	std::vector<int> arr(n,0);
	for(int i = 0; i < n; i++){
		std::cin >> arr[i];
	}

	std::cin >> m;
	std::vector<int> brr(m,0);
	for(int i = 0; i < m; i++){
		std::cin >> brr[i];
	}

	std::vector<int> inter;
	int x = 0, y = 0;
	while(x < n && y < m){
		if(arr[x] < brr[y]){
			x++;
		}
		else
			if(arr[x] > brr[y])
				y++;
			else{
				inter.push_back(arr[x]);
				x++;
				y++;
			}
	}

	long long summ = 0, suma = 0, sumb = 0;
	x = 0;
	y = 0;
	for(int i = 0; i < inter.size(); i++){
		summ += inter[i];
		suma = 0; sumb = 0;
		while(arr[x] != inter[i]){
			suma += arr[x];
			x++;
		}
		x++;

		while(brr[y] != inter[i]){
			sumb += brr[y];
			y++;
		}
		y++;
		summ += std::max(suma,sumb);
	}

	if(x < n || y < m){
		suma = 0;
		while(x < n){
			suma += arr[x];
			x++;
		}

		sumb = 0;
		while(y < m){
			sumb += brr[y];
			y++;
		}

		summ += std::max(suma,sumb);
	}

	std::cout << summ << "\n";

	return true;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	bool flag = true;
	while(flag){
		flag = solve();
	}
	// 	solve();
	return 0;
}