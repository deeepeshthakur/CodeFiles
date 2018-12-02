#include <bits/stdc++.h>

using namespace std;

bool checkForFinalAns( std::vector < int >& numb, int x){
	if(x < numb.size() - 1){
		if(numb[x + 1] != 0){
			std::cout << "YES\n";
			for(int index = 0; index < numb.size(); index++){
				std::cout << numb[index];
				if(index == x){
					std::cout << "\n";
				}
			}
			std::cout << "\n";
			return true;
		}
	}
	return false;
}

int main(){
	std::string inputS{};
	long long a, b;
	std::cin >> inputS >> a >> b;
	int n = inputS.length();
	std::vector < int > numb( n, 0), pow10( n, 0);
	pow10[n - 1] = 1;

	for(int index = n - 2; index >= 0; index--){
		pow10[index] = (pow10[index + 1]*10)%b;
	}

	for(int index = 0; index < n; index++){
		numb[index] = inputS[index] - '0';
	}

	// std::vector < int > validIndex{};
	long long amodule = 0, bmodule = 0;
	for(int index = 0; index < n; index++){
		bmodule += (numb[index]*pow10[index])%b;
		bmodule %= b;
	}

	bool flag = false;
	for(int index = 0; index < n && !flag; index++){
		amodule = ((amodule*10)%a + numb[index])%a;
		bmodule = (bmodule - ((numb[index]*pow10[index])%b))%b;

		if(amodule == 0 && bmodule == 0){
			flag = checkForFinalAns( numb, index);
		}
	}

	if(!flag){
		std::cout << "NO\n";
	}
	return 0;
}