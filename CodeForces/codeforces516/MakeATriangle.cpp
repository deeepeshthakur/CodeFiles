#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int a, b, c;
	std::cin >> a >> b >> c;
	int sum = a + b + c;
	int minM = std::min( a, std::min( b, c));
	int maxM = std::max( a, std::max( b, c));
	a = minM;
	c = maxM;
	b = sum - a - c;
	int t = 0;
	if( c >= a + b){
		t = c - a - b + 1;
	}
	std::cout << t << "\n";
	return 0;
}