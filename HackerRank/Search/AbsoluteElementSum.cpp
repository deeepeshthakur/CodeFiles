#include <bits/stdc++.h>

using namespace std;

long long zero = 0;
long long mod(long long a){
	if( a < zero){
		a = -a;
	}
	return a;
}


int main(){
	int n;
	std::cin >> n;
	std::vector < long long > freqTable( 4001, 0);
	for(int index = 0; index < n; index++){
		int temp;
		std::cin >> temp;
		freqTable[temp + 2000]++;
	}

	std::vector < long long > cumFreq( 40001, 0);
	cumFreq[0] = freqTable[0];
	for(int index = 1; index < 4001; index++){
		cumFreq[index] = cumFreq[index - 1] + freqTable[index];
	}

	std::vector< long long > sumTable( 4001, 0);
	sumTable[0] = mod((-2000)*freqTable[0]);
	for(int index = 1; index < 4001; index++){
		sumTable[index] = (sumTable[index - 1]) + mod((long long)(index - 2000)*freqTable[index]);
	}

	long long negativeSum = sumTable[1999], positiveSum = sumTable[4000] - sumTable[1999];
	for(int index = 2000; index < 4001; index++){
		sumTable[index] -= negativeSum;
	}

	std::vector< long long > ansTable( 4001, 0);
	for(int index = -2000; index < 0; index++){
		long long mdNum = mod(index);
		ansTable[index + 2000] = (cumFreq[mdNum + 2000] + cumFreq[mdNum + 2000] - cumFreq[4000])*mdNum + negativeSum + positiveSum - (sumTable[mdNum + 2000] + sumTable[mdNum + 2000]);
	}

	ansTable[2000] = positiveSum + negativeSum;
	for(int index = 1; index <= 2000; index++){
		long long mdNum = mod(index);
		ansTable[index + 2000] = (cumFreq[4000] - cumFreq[2000 - mdNum] -cumFreq[2000 - mdNum])*mdNum + sumTable[2000 - mdNum] + sumTable[2000 - mdNum] + positiveSum - negativeSum;
	}

	long long extAns = 0;
	int q;
	long long qEq = 0, qtemp;
	std::cin >> q;
	for(int index = 0; index < q; index++){
		std::cin >> qtemp;
		qEq += qtemp;
		if(mod(qEq) <= (long long)2000){
			std::cout << ansTable[qEq + 2000] << "\n";
		}else{
			if(qEq < (long long)(-2000)){
				extAns = cumFreq[4000]*mod(qEq) + negativeSum - positiveSum;
				std::cout << extAns << "\n";
			}
			if(qEq > (long long)(2000)){
				extAns = cumFreq[4000]*mod(qEq) - negativeSum + positiveSum;
				std::cout << extAns << "\n";
			}
		}
	}
	return 0;
}
