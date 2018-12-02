#include <bits/stdc++.h>

using namespace std;
std::string inputString{};

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::cin >> inputString;
	std::vector < int > countingArray( 26, 0);
	for(int index = 0; index < n; index++){
		countingArray[inputString[index] - 'a']++;
	}

	for(int index = 0; index < 26; index++){
		for(int x = 0; x < countingArray[index]; x++){
			std::cout << (char)('a' + index);
		}
	}
	std::cout << "\n";
	return 0;
}	