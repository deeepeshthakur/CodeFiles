#include <bits/stdc++.h>

using namespace std;
long long apSum( long long a, long long n, long long d){
	long long l = a + (n - 1)*d;
	return (n*(a + l))/2;
}

int main(){
	std::ios::sync_with_stdio(false);
	int test = 0;
	std::cin >> test;
	while( test--){
		long long n = 0;
		std::cin >> n;
		long long n3 = (n - 1)/3, n5 = (n - 1)/5, n15 = (n - 1)/15;
		n3 = apSum( 3ll, n3, 3ll);
		n5 = apSum( 5ll, n5, 5ll);
		n15 = apSum( 15ll, n15, 15ll);
		std::cout << n3 + n5 - n15 << "\n";
	}
	return 0;
}