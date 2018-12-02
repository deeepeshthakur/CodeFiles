#include <bits/stdc++.h>

using namespace std;

void solveForLength( int len){
	std::string numer{}, denom{};
	int lenOfStr = 0;
	lenOfStr = len/2;
	std::cout << "1" << " " << "1";
	for(int index = 0; index < lenOfStr; index++){
		std::cout << "0";
	}
	std::cout << endl;
}

int main(){
	int queries = 0;
	std::cin >> queries;
	while(queries--){
		int len;
		std::cin >> len;
		solveForLength( len);
	}
	return 0;
}