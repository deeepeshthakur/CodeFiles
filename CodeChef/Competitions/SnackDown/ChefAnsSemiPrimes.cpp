#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	std::vector < int > primeNumbers{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163 ,167, 173, 179, 181, 191, 193, 197, 199};
	std::vector < int > semiprimes{};

	for(int x = 0; x < primeNumbers.size(); x++){
		for( int y = x + 1; y < primeNumbers.size(); y++){
			if(primeNumbers[x]*primeNumbers[y] < 200){
				semiprimes.push_back( primeNumbers[x]*primeNumbers[y]);
			}
		}
	}

	std::vector < bool > testC( 201, false);
	for(auto x : semiprimes){
		for(auto y : semiprimes){
			if(x + y <= 200){
				testC[x + y] = true;
			}
		}
	}

	int t = 0;
	std::cin >> t;
	while(t--){
		int xx;
		std::cin >> xx;
		if(testC[xx]){
			std::cout << "YES\n";
		}
		else{
			std::cout << "NO\n";
		}
	}
	return 0;
}