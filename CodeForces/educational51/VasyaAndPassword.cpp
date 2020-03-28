#include <bits/stdc++.h>

using namespace std;

void solveFor(){
	std::string str{};
	std::cin >> str;
	int indexLower = -1, indexUpper = -1, indexDigit = -1;
	for(int index = 0; index < str.length(); index++){
		if(indexDigit == -1 && str[index] >= '0' && str[index] <= '9'){
			indexDigit = index;
		}

		if(indexUpper == -1 && str[index] >= 'A' && str[index] <= 'Z'){
			indexUpper = index;
		}

		if(indexLower == -1 && str[index] >= 'a' && str[index] <= 'z'){
			indexLower = index;
		}
	}

	if(indexLower != -1 && indexUpper != -1 && indexDigit != -1){
		std::cout << str << "\n";
	}
	else{
		if(indexLower == -1){
			if(indexUpper > -1 && indexDigit > -1){
				if(indexUpper != 0 && indexDigit != 0){
					str[0] = 'a';
				}
				else{
					if(indexUpper != 1 && indexDigit != 1){
						str[1] = 'a';
					}
					else{
						str[2] = 'a';
					}
				}
			}

			if(indexUpper == -1 && indexDigit > -1){
				str[1] = 'a';
				str[2] = 'A';
			}

			if(indexUpper > -1 && indexDigit == -1){
				str[1] = 'a';
				str[2] = '1';
			}
		}
		else{
			if(indexUpper == -1){
				if(indexLower > -1 && indexDigit > -1){
					bool flag = true;
					for(int index = 0; index < 3; index++)
						if(index != indexLower && index != indexDigit && flag){
							str[index] = 'A';
							flag = false;
						}
					}

					if(indexDigit == -1 && indexLower > -1){
						str[1] = '1';
						str[2] = 'A';
					}
				}
				else{
					bool flag = true;
					for(int index = 0; index < 3; index++){
						if(index != indexLower && index != indexUpper && flag){
							str[index] = '1';
							flag = false;
						}
					}
				}
			}
			std::cout << str << "\n";
		}
	}

	int main(){
		int testCases = 0;
		std::cin >> testCases;
		while(testCases--){
			solveFor();
		}
		return 0;
	}