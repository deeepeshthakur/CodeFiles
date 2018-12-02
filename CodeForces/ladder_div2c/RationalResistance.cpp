#include <bits/stdc++.h>

using namespace std;

long long rec( long long a, long long b){
	if( a%b == 0){
		return a;
	}
	long long ans = a/b + rec( b, a%b);
	return ans;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	long long a, b;
	std::cin >> a >> b;
	long long ans = rec( a, b);
	std::cout << ans << "\n";
	return 0;
}