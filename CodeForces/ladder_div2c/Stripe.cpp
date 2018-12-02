#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector < long long > cumSum( n, 0);
	// long long inp;
	for(int index = 0; index < n; index++){
		std::cin >> cumSum[index];
		if(index > 0){
			cumSum[index] += cumSum[index - 1];
		}
	}
	long long total = cumSum[cumSum.size() - 1];
	int ans = 0;
	for(int index = 0; index < n; index++){
		if(cumSum[index] == (total - cumSum[index]) && index < n - 1){
			ans++;
		}
	}
	std::cout << ans << "\n";
	return 0;
}