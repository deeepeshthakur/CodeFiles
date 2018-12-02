#include <bits/stdc++.h>
using namespace std;

int main(){
	int n = 0;
	std::cin >> n;
	std::vector < long long > numberArray( n, 0);
	std::vector < long long > sumUntilIndex( n, 0);
	long long totalSum = 0;
	for(int index = 0; index < n; index++){
		std::cin >> numberArray[index];
		totalSum += numberArray[index];
		sumUntilIndex[index] = totalSum;
	}
	
	if(totalSum%3){
		std::cout << "0\n";
	}
	else{
		std::vector < int > aIndex{}, bIndex{};
		for(int index = 0; index < n; index++){
			if(sumUntilIndex[index] == totalSum/3){
				aIndex.push_back( index);
			}

			if(sumUntilIndex[index] == 2*(totalSum/3) && index < n - 1){
				bIndex.push_back( index);
			}
		}

		long long ans = 0;
		int aCounter = 0, bCounter = 0;
		// std::cout << "lastWhile\n";
		while(aCounter < aIndex.size() && bCounter < bIndex.size()){
			if(aIndex[aCounter] >= bIndex[bCounter]){
				while(aIndex[aCounter] >= bIndex[bCounter] && bCounter < bIndex.size()){
					bCounter++;
				}
			}

			if(bCounter < bIndex.size() && aIndex[aCounter] < bIndex[bCounter]){
				ans += (long long)(bIndex.size() - bCounter);
			}
			aCounter++;
		}
		std::cout << ans << "\n";
	}
	return 0;
}