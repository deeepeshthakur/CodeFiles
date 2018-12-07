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

	int ans = 0;
	for(int index = 10000; index < 100000; index++){
		if(checkFunction( 5, index)){
			for(int ii = 0; ii < 10000; ii++){
				if(checkFunction( 9, index*10000 + ii)){
					ans++;
				}
			}
		}
	}

	std::cout << ans << "\n";

	return 0;
}