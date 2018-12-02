#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int n, L, a;
	std::cin >> n >> L >> a;
	int currTime = 0;
	int st, end;

	int ans = 0;
	for(int index = 0; index < n; index++){
		std::cin >> st >> end;
		end += st;
		ans += (st - currTime)/a;
		currTime = end;
	}
	ans += (L - currTime)/a;
	std::cout << ans << "\n";
	return 0;
}