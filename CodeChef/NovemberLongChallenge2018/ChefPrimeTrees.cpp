#include <bits/stdc++.h>

using namespace std;
std::vector< int > primeNumbers( 3000000, 0);
void fillPrimeNumbers(){
	int sizeA = 20000001;
	vector < bool > checkArray( sizeA, true);
	for(int index = 0; index < sizeA; index++){
		checkArray[index] = true;
	}
	int sr = std::sqrt( sizeA) + 0.5;
	for(int index = 2; index <= sr + 5; index++){
		if(checkArray[index]){
			int i = 0;
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

	primeNumbers.resize(i);
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	fillPrimeNumbers();
	int n;
	std::cin >> n;
	std::vector < int > inpArray(n, 0);
	int sumM = 0;
	for(int i = 0; i < n; i++){
		std::cin >> inpArray[i];
		sumM += inpArray[i];
	}
	

	// std::cout << "\n\n" << maxScore << " " << inpArray[mIndex] << "\n";
	return 0;
}