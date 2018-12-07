#include <bits/stdc++.h>

using namespace std;

void f(){
	long long n;
	std::cin >> n;
	long long sumN = (n*(n + 1))/2, sumSq = (n*(n + 1)*(2*n + 1))/6;
	std::cout << std::abs(sumN*sumN - sumSq) << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	int test = 0;
	std::cin >> test;
	while( test--){
		f();
	}
	return 0;
}