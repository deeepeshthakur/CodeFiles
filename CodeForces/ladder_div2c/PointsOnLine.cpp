#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	long long d;
	std::cin >> n;
	std::cin >> d;
	std::vector < long long > points( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> points[index];
	}

	// std::sort( points.begin(), points.end());
	long long ans = 0;
	for(int index = 0; index < n; index++){
		long long a, b;
		a = index;
		b = std::upper_bound( points.begin(), points.end(), points[index] + d) - points.begin() - 1;
		ans += std::max( 0ll, ((b - a)*(b - a - 1))/2);
		// std::cout << ans << "\n";
	}
	std::cout << ans << "\n";
	return 0;
}