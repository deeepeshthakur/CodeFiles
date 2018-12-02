#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
bool rec(long long& ndash, int& k){
	if(k == 0){
		printf("%.8f\n", 1.0/(1.0*ndash));
		return false;
	}

	if(ndash == 1){
		printf("%.8f\n", 1.0);
		return false;
	}

	if(ndash == 2){
		printf("%.8f\n", 0.5);
		return false;
	}

	if(ndash == 3){
		if(k == 0){
			printf("%.8f\n", 1.0/3.0);
			return false;
		}

		if(k == 1){
			printf("%.8f\n", 0.5);
			return false;
		}

		printf("%.8f\n", 1.0);
		return false;
	}

	if(ndash == 4){
		if(k == 0){
			printf("%.8f\n", 0.25);
			return false;
		}

		if(k == 1){
			printf("%.8f\n", 0.50);
			return false;
		}
		printf("%.8f\n", 1.0);
		return false;
	}

	if(ndash%4){
		ndash = ndash/2ll + 1ll;
		k--;
		return true;
	}

	ndash = ndash/2ll;
	k--;
	return true;

}

void f(){
	long long n;
	int k;
	std::cin >> n >> k;
	long long ndash = n;
	while(rec(ndash, k, n)){
		printf("%.8f  ", 1.0/(ndash*1.0));
		std::cout << ndash << " " << k << std::endl;
	}
}

int main(){
	int t;
	std::cin >> t;
	while(t--){
		f();
	}
	return 0;
}