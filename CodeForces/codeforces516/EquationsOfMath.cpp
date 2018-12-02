#include <bits/stdc++.h>

using namespace std;
void solve(){
	int ones = 0;
	int a = 0;
	std::cin >> a;
	while( a > 0){
		ones += (a%2);
		a /= 2;
	}

	long long ans = 1, two = 2;
	for(int index = 0; index < ones; index++){
		ans *= two;
	}

	std::cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	int test;
	std::cin >> test;
	while(test--){
		solve();
	}
	return 0;
}