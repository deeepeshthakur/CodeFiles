#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector < int > v( n, 0);
	for(int index = 1; index < n; index++){
		v[index] = (index^v[index - 1]);
	}

	long long ans = 0;
	for(int index = 0; index < n; index++){
		long long t;
		std::cin >> t;
		ans = (ans^t);
	}

	int m , k;
	for(int index = 1; index <= n; index++){
		m = n/index;
		k = n%index;
		if(m%2 == 0){
			ans = (ans^(v[k]));
		}
		else{
			ans = (ans^(v[k]^v[index - 1]));
		}
	}

	std::cout << ans << "\n";
	return 0;
}