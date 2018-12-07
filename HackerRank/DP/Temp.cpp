#include <bits/stdc++.h>

using namespace std;
std::vector < int > primes{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};
std::vector < bool > checkPrimeArray( 50, false);

struct primeSum{
	int id;
	std::vector < int > possibleDigits{};
	std::vector < int > possibleNumberIndex{};
	long currentCount = 0, nextCount = 0;
};

bool checkFunction(int len, long number){
	bool flag = true;
	std::vector < int > digits(len);
	long div = 1;
	for(int dig = 0; dig < digits.size(); dig++){
		digits[dig] = (number/div)%10;
		div *= 10;
	}

	for(int l = 0; l < digits.size() - 2 && flag; l++){
		if(!checkPrimeArray[digits[l] + digits[l + 1] + digits[l + 2]]){
			flag = false;
		}
	}

	for(int l = 0; l < digits.size() - 3 && flag; l++){
		if(!checkPrimeArray[digits[l] + digits[l + 1] + digits[l + 2] + digits[l + 3]]){
			flag = false;
		}
	}

	for(int l = 0; l < digits.size() - 4 && flag; l++){
		if(!checkPrimeArray[digits[l] + digits[l + 1] + digits[l + 2] + digits[l + 3] + digits[l + 4]]){
			flag = false;
				// std::cout << index << "\n";
		}
	}

	return flag;
}

int main(){
	for(auto x : primes){
		checkPrimeArray[x] = true;
	}

	std::vector < long long > answers( 400001, 0);
	answers[0] = 0;
	answers[1] = 10;
	answers[2] = 90;

	for(int index = 100; index < 1000; index++){
		if(checkFunction( 3, index)){
			answers[3]++;
		}
	}

	for(int index = 1000; index < 100000; index++){
		if(checkFunction( 4, index)){
			answers[4]++;
		}
	}

	// std::vector < int > validNumbers{};
	for(int index = 10000; index < 100000; index++){
		if(checkFunction( 5, index)){
			answers[5]++;
		}
	}

	std::vector < int > validNumbers{200, 201, 203, 205, 209, 300, 302, 304, 308, 320, 322, 326, 328, 380, 382, 382, 386, 388, 500, 502,
									 506, 508, 560, 562, 566, 568, 1101, 1200, 2003, 2005, 2012, 2014, 2030, 2032, 2038, 2050, 2056, 2092, 2098, 2102, 2104, 
									 2120, 2122, 2128, 2140, 2146, 2182, 2188, 2300, 2302, 
									 2308, 2320, 2326, 2362, 2368, 2380, 2386, 2500, 2506, 2542, 2548, 2560, 
									 2566, 2902, 2908, 2920, 2926, 2962, 2980, 3002, 3020, 3200, 5002, 5020, 
									 5200, 9200, 10200, 20030, 20032, 20038, 20050, 
									 20056, 20120, 20122, 20128, 20140, 20146, 20300, 20302, 20308, 20320, 20326, 20380, 20386, 20500, 
									 20506, 20560, 20566, 20920, 20926, 20980, 21020, 21200, 23002, 23020, 23200, 29020, 29200, 30020, 30200, 
									 41020, 41200, 45200, 50020, 50200, 63200, 65002, 65020, 65200, 69200, 81200, 83002, 83020, 83200, 89020, 
									 89200, 90200};

	std::cout << validNumbers.size() << "\n";
	std::vector < primeSum > dpArray( validNumbers.size());
	for(int index = 0; index < dpArray.size(); index++){
		dpArray[index].id = validNumbers[index];
		dpArray[index].currentCount = 1;
		dpArray[index].nextCount = 0;
		for(int digit = 0; digit < 10; digit++){
			int numb = digit*100000 + dpArray[index].id;
			if(checkFunction( 6, numb)){
				if(digit)
					dpArray[index].possibleDigits.push_back(digit);
				if(std::binary_search( validNumbers.begin(), validNumbers.end(), numb/10)){
					dpArray[index].possibleNumberIndex.push_back( std::lower_bound( validNumbers.begin(), validNumbers.end(), numb/10) - validNumbers.begin());
				}				
			}
		}
	}

	int currIndex = 6, maxLimit = 20;
	while(currIndex < maxLimit){
		for(int index = 0; index < dpArray.size(); index++){
			answers[currIndex] += (((long)dpArray[index].possibleDigits.size())*dpArray[index].currentCount);
			answers[currIndex] %= 1000000007;

			for(int xx = 0; xx < dpArray[index].possibleNumberIndex.size(); xx++){
				dpArray[dpArray[index].possibleNumberIndex[xx]].nextCount += dpArray[index].currentCount;
			}
		}

		for(int index = 0; index < dpArray.size(); index++){
			std::cout << dpArray[index].id << "            " << dpArray[index].possibleDigits.size() << "  " << dpArray[index].possibleNumberIndex.size() << "\n";
			dpArray[index].currentCount = dpArray[index].nextCount;
			dpArray[index].nextCount = 0;
		}

		std::cout << currIndex << "  " << answers[currIndex] << std::endl;
		currIndex++;
	}



	// std::cout << answers[5] << "\n\n\n\n";

	// std::vector < int > distinct5{}, distinct6{};
	// for(int index = 0; index < validNumbers.size(); index++){
	// 	std::cout << validNumbers[index] << " -- ";
	// 	for(int digit = 0; digit < 10; digit++){
	// 		if(checkFunction( 6, digit*100000 + validNumbers[index])){
	// 			std::cout << digit*100000 + validNumbers[index] << " ";
	// 			if(!std::binary_search( distinct5.begin(), distinct5.end(), validNumbers[index])){
	// 				distinct5.push_back(validNumbers[index]);
	// 			}

	// 			if(!std::binary_search( distinct6.begin(), distinct6.end(), digit*100000 + validNumbers[index])){
	// 				distinct6.push_back(digit*100000 + validNumbers[index]);
	// 			}
	// 		}
	// 	}
	// 	std::cout << "\n";
	// }

	// for(int index = 0; index < distinct6.size(); index++){
	// 	if(!std::binary_search( distinct5.begin(), distinct5.end(), distinct6[index]/10)){
	// 		distinct5.push_back(validNumbers[index]);
	// 		std::sort(distinct5.begin(), distinct5.end());
	// 	}
	// }
	// std::cout << "\n\n\n" << validNumbers.size() << "   " << distinct5.size() << "   " << distinct6.size() << "\n\n\n";

	// std::vector < int > toBeDisposed{};
	// for(int index = 0; index < distinct5.size(); index++){
	// 	std::cout << distinct5[index] << " -- ";
	// 	bool flag = true;
	// 	for(int digit = 0; digit < 10; digit++){
	// 		if(checkFunction( 6, digit*100000 + distinct5[index])){
	// 			flag = false;
	// 			std::cout << digit*100000 + distinct5[index] << " ";
	// 		}
	// 	}
	// 	std::cout << "\n";
	// 	if(flag){
	// 		toBeDisposed.push_back(index);
	// 	}
	// }

	// std::vector < int > limitValid{};
	// int xx = 0;
	// for(int index = 0; index < distinct5.size(); index++){
	// 	if(index == toBeDisposed[xx]){
	// 		xx++;
	// 	}
	// 	else{
	// 		limitValid.push_back(distinct5[index]);
	// 	}
	// }

	// std::cout << limitValid.size() << "\n\n\n";
	// for(auto x : limitValid){
	// 	std::cout << x << ", ";
	// }
	// std::cout << "\n";

	return 0;
}