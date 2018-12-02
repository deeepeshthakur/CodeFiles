#include <bits/stdc++.h>

using namespace std;

long long binToDec( int a){
	long long b = a, multi = 1;
	long long ans = 0;
	while(b){
		ans += (b%2)*multi;
		b /= 2;
		multi *= 10;
	}
	return ans;
}

int main(){

	int n;
	std::vector < long long > numbsBin{};
	int limit = 1 << 9;
	limit++;
	for(int index = 1; index < limit; index++){
		numbsBin.push_back( binToDec( index));
	}
	std::cin >> n;
	int ans = std::upper_bound( numbsBin.begin(), numbsBin.end(), n) - numbsBin.begin();
	// std::cout << numbsBin[ans] << "\n";
	ans = std::min( ans, ( int )numbsBin.size());
	std::cout << ans << "\n";
	return 0;
}
