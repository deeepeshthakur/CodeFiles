#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n;
	std::cin >> n;
	std::vector < long long > inputArray( n, 0);
	for(long long index = 0; index < n; index++){
		std::cin >> inputArray[index];
	}

	long long x, f;
	std::cin >> x >> f;
	long long totalFees = 0;
	for(long long index = 0; index < n; index++){
		if(inputArray[index] > x){
			if((inputArray[index] - x)%(x + f) == 0){
				totalFees += ((inputArray[index] - x)/(x + f))*f;
			}
			else{
				totalFees += (((inputArray[index] - x)/(x + f))*f + f);
			}
		}
	}

	std::cout << totalFees << "\n";
	return 0;
}