#include <bits/stdc++.h>

using namespace std;
std::vector < long long > power10( 15, 1ll);
void rec(long long n, std::vector < long long >& lNumbs, int dig){
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

	long long s, l;
	std::cin >> s >> l;
	std::vector < long long > lNumbs{};
	rec( 0ll, lNumbs, 0);
	for(auto x : lNumbs){
		std::cout << x << " ";
	}
	std::cout << "\n";
	return 0;
}