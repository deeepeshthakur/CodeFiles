#include <bits/stdc++.h>

using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::vector < int > counterArray( 10000001, 0);
	int n, m, inp;
	std::cin >> n;
	for(int index = 0; index < n; index++){
		std::cin >> inp;
		counterArray[inp]++;
	}

	std::cin >> m;
	std::vector< std::pair < int , int > > queries( m, { 0, 0});
	for(int index = 0; index < m; index++){
		std::cin >> queries[index].first >> queries[index].second;
	}

	std::vector < bool > checkArray( 10000001, true);
	std::vector < int > primeNumbers( 1000000, 0);

	int limitS = std::sqrt((long long)checkArray.size()) + 0.5;
	for(long long index = 2; index - 1 < limitS; index++){
		if(checkArray[index]){
			// checkArray[index] = false;
			long long i = 0;
			while( index*index + index*i < checkArray.size()){
				checkArray[index*index + index*i] = false;
				i++;
			}
		}
	}

	int l = 0;
	for(int index = 2; index < checkArray.size(); index++){
		if(checkArray[index]){
			primeNumbers[l++] = index;
		}
	}
	primeNumbers.resize( l);
	std::sort( primeNumbers.begin(), primeNumbers.end());

	std::vector < int > lArray( l, 0);
	for(int index = 0; index < primeNumbers.size(); index++){
		int i = 1;
		// std::cout << primeNumbers[index] << std::endl;
		while(primeNumbers[index]*i < counterArray.size()){
			lArray[index] += counterArray[primeNumbers[index]*i];
			i++;
		}
	}

	for(int index = 1; index < lArray.size(); index++){
		lArray[index] += lArray[index - 1];
	}

	int large = primeNumbers[primeNumbers.size() - 1];
	for(int index = 0; index < m; index++){
		int l = queries[index].first, r = queries[index].second;
		if(l > large){
			std::cout << 0 << "\n";
		}
		else{
			int lIndex = std::lower_bound( primeNumbers.begin(), primeNumbers.end(), l) - primeNumbers.begin();
			lIndex--;
			int rIndex = std::upper_bound( primeNumbers.begin(), primeNumbers.end(), r) - primeNumbers.begin();
			rIndex--;
			int ans = lArray[rIndex];
			if(lIndex >= 0){
				ans -= lArray[lIndex];
			}
			std::cout << ans << "\n";
		}
	}
	return 0;
}
