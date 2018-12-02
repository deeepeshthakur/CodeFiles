#include <bits/stdc++.h>

using namespace std;

bool check( int index, int n){
	bool ans = true;

	int currDig;
	while(index){
		currDig = index%10;
		index /= 10;
		if(!(currDig > 0 && currDig < n)){
			return false;
		}
	}
	return ans;
}

int shufflingFunc( std::vector < int >& perm , int n){
	std::vector < int > intialperm( n, 0);
	for(int index = 0; index < n; index++){
		intialperm[index] = index + 1;
	}

	for(int index = 0; index < n; index++){
		int temp = intialperm[index];
		intialperm[index] = intialperm[perm[index]];
		intialperm[perm[index]] = temp;
	}

	int ans = 0;
	int multiplier = 1;
	for(int index = n - 1; index >= 0; index--){
		ans += (multiplier*(intialperm[index]));
		multiplier *= 10;
	}

	return ans;
}

void solveFor( int n){
	std::vector < int > possiblePermutations{};
	int minM = 0, maxM = 0, multiplier = 1;
	for(int index = 0; index < n; index++){
		minM += (1*multiplier);
		maxM += (n*multiplier);
		multiplier *= 10;
	}

	for(int index = minM; index <= maxM; index++){
		if(check( index, n + 1)){
			possiblePermutations.push_back( index);
		}
	}

	// for(auto x : possiblePermutations){
	// 	std::cout << x << " ";
	// }
	// std::cout << std::endl;

	std::vector < int > perm( n, 0);
	for(int index = 0; index < possiblePermutations.size(); index++){
		int temp = possiblePermutations[index];
		for(int x = n - 1; x >= 0; x--){
			perm[x] = temp % 10;
			perm[x]--;
			temp /= 10;
		}

		possiblePermutations[index] = shufflingFunc( perm, n);
	}

	sort( possiblePermutations.begin(), possiblePermutations.end());
	
	// for(auto x : possiblePermutations){
	// 	std::cout << x << " ";
	// }
	// std::cout << std::endl;

	std::vector < int > elementArray(1, 0), freqArray(1, 0);
	elementArray[0] = possiblePermutations[0];
	freqArray[0] = 1;
	for(int index = 1; index < possiblePermutations.size(); index++){
		if(elementArray[elementArray.size() - 1] == possiblePermutations[index]){
			freqArray[freqArray.size() - 1]++;
		}
		else{
			elementArray.push_back(possiblePermutations[index]);
			freqArray.push_back(1);
		}
	}

	// for(int index = 0; index < elementArray.size(); index++){
	// 	std::cout << elementArray[index] << "   --   " << freqArray[index] << "\n";
	// }
	// std::cout << std::endl;

	int maxIndex = 0, maxfreq = freqArray[0], minIndex = 0, minfreq = freqArray[0];
	for(int index = 1; index < elementArray.size(); index++){
		if(freqArray[index] > maxfreq){
			maxfreq = freqArray[index];
			maxIndex = index;
		}

		if(freqArray[index] < minfreq){
			minfreq = freqArray[index];
			minIndex = index;
		}
	}

	for(int index = 0; index < elementArray.size(); index++){
		if(freqArray[index] == maxfreq){
			std::cout << elementArray[index] << "    " ;
		}
	}
	std::cout << " ---- " << maxfreq << "\n";

	for(int index = 0; index < elementArray.size(); index++){
		if(freqArray[index] == minfreq){
			std::cout << elementArray[index] << "    " ;
		}
	}
	std::cout << " ---- " << minfreq << "\n\n\n\n";

	// std::vector < int > anss( n, 0);
	// int tempAns = elementArray[maxIndex];
	// for(int index = n - 1; index >= 0; index--){
	// 	anss[index] = tempAns % 10;
	// 	tempAns /= 10;
	// }

	// for(int index = 0; index < n; index++){
	// 	std::cout << anss[index] << " ";
	// }
	// std::cout << "\n";

	// tempAns = elementArray[minIndex];
	// for(int index = n - 1; index >= 0; index--){
	// 	anss[index] = tempAns % 10;
	// 	tempAns /= 10;
	// }

	// for(int index = 0; index < n; index++){
	// 	std::cout << anss[index] << " ";
	// }
	// std::cout << "\n" << std::endl;;

}

int main(){
	int testCases = 0;
	std::cin >> testCases;
	while(testCases){
		solveFor(testCases);
		testCases--;
	}
	return 0;
}