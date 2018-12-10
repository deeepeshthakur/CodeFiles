#include <bits/stdc++.h>

using namespace std;

std::vector< bool > primeNumbers( 2000001, true);
void fillPrimeNumbers(){
	primeNumbers[0] = false;
	primeNumbers[1] = false;
	int sr = std::sqrt(primeNumbers.size()) + 0.5;
	for(long long index = 2; index <= sr + 5; index++){
		if(primeNumbers[index]){
			long long i = 0;
			while( index*index + index*i < primeNumbers.size()){
				primeNumbers[index*index + index*i] = false;
				i++;
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::vector < long long > f(2000001, 0);
	fillPrimeNumbers();
	for(int i = 1; i < f.size(); i++){
		if(primeNumbers[i]){
			f[i] = i;
		}
		f[i] += f[i - 1];
	}

	int t, n;
	std::cin >> t;
	while(t--){
		std::cin >> n;
		std::cout << f[n] << std::endl;
	}
	return 0;
}