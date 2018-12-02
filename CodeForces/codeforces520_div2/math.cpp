#include <bits/stdc++.h>

using namespace std;
std::vector< long long > primeNumbers( 300000, 0);
void fillPrimeNumbers(){
	int sizeA = 1000000;
	bool checkArray[1000000];
	for(int index = 0; index < sizeA; index++){
		checkArray[index] = true;
	}
	int sr = std::sqrt( sizeA) + 0.5;
	for(long long index = 2; index <= sr + 5; index++){
		if(checkArray[index]){
			long long i = 0;
			while( index*index + index*i < sizeA){
				checkArray[index*index + index*i] = false;
				i++;
			}
		}
	}

	int i = 0;
	for(int index = 2; index < sizeA; index++){
		if(checkArray[index]){
			primeNumbers[i++] = index;
		}
	}

	primeNumbers.resize( i);
}

long long factorise( long long n){
	for(long long index = 0; index < primeNumbers.size(); index++){
		if(n % primeNumbers[index] == 0){
			return primeNumbers[index];
		}
	}
	return 1ll;
}

bool checkf(int ma, int mi){
	if(ma != mi){
		return false;
	}

	int l = 1;
	while(ma > l){
		l *= 2;
		if(l == ma){
			return true;
		}
	}
	return false;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	fillPrimeNumbers();	
	int test = 1;
	while( test--){
		long long n;
		std::cin >> n;
		if(n == 1){
			std::cout << "1 0\n";
			return 0;
		}
		std::vector < long long > factors{};
		if(std::binary_search( primeNumbers.begin(), primeNumbers.end(), n)){
			std::cout << n << " 0\n";
			return 0;
		}
		
		while(n > 1){
			long long f = factorise( n);
			if(f == 1){
				f = n;
			}
			n /= f;
			factors.push_back( f);
		}

		std::sort(factors.begin(), factors.end());
		int maxm = 0, minm = 1000000, val = 1;
		for(int i = 0; i < factors.size(); i++){
			val *= factors[i];
			int e = i;
			while(e + 1 < factors.size() && factors[e + 1] == factors[i]){
				e++;
			}
			if(maxm < e - i + 1){
				maxm = e - i + 1;
			}
			if(minm > e - i + 1){
				minm = e - i + 1;
			}
			i = e;
		}

		if(maxm == 1){
			std::cout<< val << " " << 0 << "\n";
		}
		else{
			int l = 1, ii = 0;
			while(maxm > l){
				l *= 2;
				ii++;
			}
			if(checkf(maxm, minm))
				std::cout << val << " " << ii << "\n";
			else{
				std::cout << val << " " << ii + 1<< "\n";
			}

		}
	}
	return 0;
}