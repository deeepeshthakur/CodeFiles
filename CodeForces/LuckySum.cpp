#include <bits/stdc++.h>

using namespace std;
std::vector < long long > power10( 15, 1ll);
void rec(long long n, std::vector < long long >& lNumbs, int dig){
	if(dig > 10){
		return;
	}
	lNumbs.push_back( n + 4ll*power10[dig]);
	lNumbs.push_back( n + 7ll*power10[dig]);
	rec(n + 4ll*power10[dig], lNumbs, dig + 1);
	rec(n + 7ll*power10[dig], lNumbs, dig + 1);
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	for(int i = 1; i < 15; i++){
		power10[i] = power10[i - 1]*10ll;
	}

	// for(auto x : power10){
	// 	std::cout << x << " ";
	// }
	// std::cout << "\n";

	long long s, l;
	std::cin >> s >> l;
	std::vector < long long > lNumbs{};
	rec( 0ll, lNumbs, 0);
	std::sort(lNumbs.begin(), lNumbs.end());
	// for(auto x : lNumbs){
	// 	std::cout << x << " ";
	// }
	// std::cout << "\n";
	long long ans = 0, curr = s;
	int i = std::lower_bound(lNumbs.begin(), lNumbs.end(), s) - lNumbs.begin();
	while(lNumbs[i] < l){
		ans += (lNumbs[i] - curr + 1)*lNumbs[i];
		curr = lNumbs[i] + 1;
		i++;
	}
	ans += (l - curr + 1)*lNumbs[i];
	std::cout << ans << "\n";
	return 0;
}