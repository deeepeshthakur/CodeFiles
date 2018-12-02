#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int n, l, r, Ql, Qr;
	std::cin >> n >> l >> r >> Ql >> Qr;
	std::vector < int > weights( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> weights[index];
		weights[index] += (index > 0 ? weights[index - 1] : 0);
	}

	int ans = weights[n - 1]*r + std::max( 0, (n - 1)*Qr);
	for(int x = 0; x <= n; x++){
		int temp = 0;
		int lW = (x > 0 ? weights[x - 1] : 0), rW = weights[n - 1] - lW;
		if( x >= n - x){
			temp = std::max( 0, (x - n + x - 1)*Ql);
		}
		else{
			temp = std::max( 0, (n - x - x - 1)*Qr);
		}

		temp += (lW*l + rW*r);
		ans = std::min( ans, temp);
	}
	std::cout << ans << "\n";
	return 0;
}