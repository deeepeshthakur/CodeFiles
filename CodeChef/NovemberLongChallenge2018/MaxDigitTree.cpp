#include <bits/stdc++.h>

using namespace std;

int nextNF(int n){
	int d = 0;
	while(n){
		if(d < n%10){
			d = n%10;
		}
		n /= 10;
	}
	return d;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n = 1, i = 0;
	while(n < 10000){
		i++;
		std::cout << n << " ";
		n += nextNF(n);
	}
	std::cout << "\n" << i << "\n";
	return 0;
}