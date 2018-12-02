#include <bits/stdc++.h>

using namespace std;
std::vector< long long > primeNumbers( 300000, 0);
void fillPrimeNumbers(){
	int sizeA = 3200000;
	bool checkArray[3200000];
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

int main(){
	std::ios::sync_with_stdio(false);
	fillPrimeNumbers();	
	
	long long n;
	std::cin >> n;
	if(n == 1){
		std::cout << 1 << "\n" << 0 << "\n";
		return 0;
	}
	std::vector < long long > factors{};
	while(n > 1){
		long long f = factorise( n);
		if(f == 1){
			f = n;
		}
		n /= f;
		factors.push_back( f);
	}

	if(factors.size() == 2){
		std::cout << 2 << "\n";
	}
	else{
		std::cout << 1 << "\n";
		if(factors.size() == 1){
			std::cout << 0 << "\n";
		}
		else{
			std::cout << factors[0]*factors[1] << "\n";
		}
	}
	
	return 0;
}