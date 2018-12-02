#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	long long n, m, k;
	clock_t start, end;
	std::cin >> n >> m >> k;
	if(n < m){
		std::swap( n, m);
	}

	long long low = 1, high = n*m, mid, g, s;
	while(high - low > 0){
		mid = (low + high)/2;
		s = 0ll;
		g = 0ll;
		for(long long index = 1; index <= m; index++){
			if(mid%index == 0){
				s += std::min( n, mid/index - 1ll);
			}
			else{
				s += std::min( n, mid/index);
			}

			g += std::max( 0ll, n - (mid/index));
		}
		if(g + s == n*m){
			if(s < k){
				low = mid + 1;
			}
			else{
				high = mid;
			}
			continue;
		}
		else{
			if(k > s && k <= (n*m - g)){
				low = mid;
				high = mid;
			}
			else{
				if(k <= s){
					high = mid - 1;
				}
				if(k > n*m - g){
					low = mid + 1;
				}
			}
		}
	}

	std::cout << low << "\n";
	return 0;
}