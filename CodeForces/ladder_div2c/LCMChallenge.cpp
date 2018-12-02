#include <bits/stdc++.h>

using namespace std;
long long gcdf( long long a, long long b){
	if(b > a){
		std::swap( a, b);
	}

	if(b == 0){
		return a;
	}

	return gcdf( b, a%b);
}

long long lcmF( long long a, long long b, long long c){
	long long lcm = (a*b)/gcdf( a, b);
	return (lcm*c)/gcdf( lcm, c);
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector < int > checkA{};
	for(int index = 0; index < 4; index++){
		checkA.push_back( std::max( n - index, 1));
	}

	std::vector < std::vector < int > > aux{ { 0, 1, 2}, { 0, 1, 3}, { 0, 2, 3}, { 1, 2, 3}};

	long long ans = 1ll;
	for(int index = 0; index < 4; index++){
		ans = std::max( ans, lcmF( checkA[aux[index][0]], checkA[aux[index][1]], checkA[aux[index][2]]));
	}

	std::cout << ans << "\n";
	return 0;
}