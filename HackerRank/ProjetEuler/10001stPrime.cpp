#include <bits/stdc++.h>

using namespace std;
std::vector< long long > primeNumbers( 100000, 0);
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


int main(){
	std::ios::sync_with_stdio(false);
	fillPrimeNumbers();	
	int test;
	std::cin >> test;
	while( test--){
		long long n;
		std::cin >> n;
		std::cout << primeNumbers[n - 1] << "\n";
	}
	return 0;
}