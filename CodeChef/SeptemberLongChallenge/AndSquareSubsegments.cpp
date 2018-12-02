#include <bits/stdc++.h>

using namespace std;

void solveFor( int n, int q, std::vector < int >& inputArray){
	
	std::vector < int > squareArray( 33769, 0);
	for(int index = 0; index <= 32768; index++){
		squareArray[index] = (index*index);
	}
	
	int temp, zeroC = 0, oneC = 0;
	std::vector < int > startPoints{}, endPoints{};
	for(int index = 0; index < n; index++){
		temp = inputArray[index];
		for(int indexx = index; indexx < n; indexx++){
			temp = (temp&inputArray[indexx]);
			if(temp == 0 || temp == 1){
				indexx = n;
			}
			else{
				if(!std::binary_search( squareArray.begin(), squareArray.end(), temp)){
					startPoints.push_back( index);
					endPoints.push_back(indexx);
				}
			}
		}
	}

	std::vector < int > cumGoodSeqArray( n, 0);
	for(int index = 0; index < endPoints.size(); index++){
		cumGoodSeqArray[endPoints[index]]++;
	}

	for(int index = 1; index < n; index++){
		cumGoodSeqArray[index] += cumGoodSeqArray[index - 1];
	}

	std::vector < std::vector < int > > passingEndPoints( n);
	for(int index = 0; index < endPoints.size(); index++){
		for(int x = startPoints[index] + 1; x <= endPoints[index]; x++){
			passingEndPoints[x].push_back(endPoints[index]);
		}
	}

	for(int index = 0; index < n; index++){
		std::sort( passingEndPoints[index].begin(), passingEndPoints[index].end());
	}

	// for( auto x : cumGoodSeqArray){
	// 	std::cout << x << " ";
	// }
	// std::cout << "\n";

	int ig1 = 0, ig2 = 0, accTemp = 0, l, r, ans;
	while(q--){
		ig1 = 0;
		ig2 = 0;
		accTemp = 0;
		std::cin >> l >> r;
		l--;
		r--;
		if(l > 0){
			ig1 = cumGoodSeqArray[l - 1];
		}

		accTemp = cumGoodSeqArray[r];
		ig2 = std::upper_bound( passingEndPoints[l].begin(), passingEndPoints[l].end(), r) - passingEndPoints[l].begin();
		ans = ((r - l + 1)*(r - l + 2))/2;
		ans -= (accTemp - ig1 - ig2);
		std::cout << ans << "\n";
	}
}

void calltrapFunction( int n, int q, std::vector < int >& inputArray, int maxfreq, int freq){
	int temp = 0;
	while(q > 0){
		std::cin >> temp;
		std::cin >> temp;
		q--;
	}

	std::cout << " null\n";
}

int main(){
	int testCases = 0;
	std::cin >> testCases;

	int n, q;
	while(testCases--){
		std::cin >> n >> q;
		std::vector < int > inputArray( n, 0), characteristicArray( n, 0);
		for(int index = 0; index < n; index++){
			std::cin >> inputArray[index];
			characteristicArray[index] = inputArray[index];
		}

		std::sort( characteristicArray.begin(), characteristicArray.end());
		std::vector < int > counterNumberArray{}, counterFreqArray{};
		counterNumberArray.push_back( characteristicArray[0]);
		counterFreqArray.push_back(1);
		for(int index = 1; index < n; index++){
			if(counterNumberArray[counterNumberArray.size() - 1] == characteristicArray[index]){
				counterFreqArray[counterFreqArray.size() - 1]++;
			}else{
				counterNumberArray.push_back( characteristicArray[index]);
				counterFreqArray.push_back( 1);
			}
		}

		int maxfreq = 0, freq = 0, smallest, smallestfreq;
		smallest = counterNumberArray[0];
		smallestfreq = counterFreqArray[0];
		for(int index = 0; index < counterNumberArray.size(); index++){
			if(counterFreqArray[index] > freq){
				freq = counterFreqArray[index];
				maxfreq = counterNumberArray[index];
			}
		}

		if(freq > 50){
			calltrapFunction( n, q, inputArray, maxfreq, freq);
		}
		else{
			solveFor( n, q, inputArray);
		}
	}

	return 0;
}