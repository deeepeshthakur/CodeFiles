#include <bits/stdc++.h>

using namespace std;

int main(){
	std::string inputStr{};
	std::cin >> inputStr;
	if(inputStr.length() < 3){
		std::cout << inputStr << "\n";
		return 0;
	}
	std::string ans{};
	std::vector < int > checkStr( 3, 0);
	checkStr[1] = inputStr[0];
	checkStr[2] = inputStr[1];
	ans += inputStr[0];
	ans += inputStr[1];
	int curr = 0;
	for(int index = 2; index < inputStr.length(); index++){
		curr = inputStr[index];
		if(!((checkStr[1] == checkStr[2] && checkStr[2] == curr) || (checkStr[0] == checkStr[1] && checkStr[2] == curr))){
			checkStr[0] = checkStr[1];
			checkStr[1] = checkStr[2];
			checkStr[2] = curr;
			ans += curr;
		}
	}
	std::cout << ans << "\n";
	return 0;
}