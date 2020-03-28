#include <bits/stdc++.h>

using namespace std;

long long calcLen( long long n, long long l, long long k){
	if(n == 0){
		return 0;
	}
	long long len = 0;
	long long sumn = 0;
	long long currAdd = 0;
	long long ndash = 1;
	while( sumn + currAdd <= k && ndash <= n){
		sumn += currAdd;
		currAdd = pow( l, (long long)((ndash + 1)/2));
		ndash++;
	}
	
	if(ndash < n){
		len += n - ndash;
		return len + calcLen( ndash, l, k);
	}

	k %= sumn;
	if(k == 0){
		return n;
	}
	if(k == 1){
		return 1;
	}
	if(k == 2){
		return 2;
	}

	return 2 + calcLen( n - 2, l, k);
}

void solveFor(){
	long long l, k, n;
	std::cin >> l >> n >> k;

	if(k == 1){
		std::cout << 1 << "\n";
	}
	if(k == 2){
		std::cout << 2 << "\n";
	}

	if(l == 1){
		if(k > n){
			std::cout << 0 << "\n";
		}
		else{
			std::cout << k << "\n";
		}
	}

	if(l > 2){
		std::cout << calcLen( n, l, k) << "\n";
	}
}

int main(){
	int test;
	std::cin >> test;
	for(int index = 0; index <test; index++){
		std::cout << "Case #" << index + 1 << ": ";
		solveFor();
	}
	return 0;
}