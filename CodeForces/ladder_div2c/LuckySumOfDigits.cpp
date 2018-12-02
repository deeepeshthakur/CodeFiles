#include <bits/stdc++.h>

using namespace std;

int main(){

	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	int size4 = n/4 + 2, size7 = n/7 + 2;
	std::vector < int > multi4( size4, 1), multi7( size7, 1);
	for(int index = 0; index < size4; index++){
		multi4[index] = 4*index;
	}

	for(int index = 0; index < size7; index++){
		multi7[index] = 7*index;
	}

	int count7 = 0, count4 = 0;
	for(int index = multi7.size() - 1; index >= 0; index--){
		if(std::binary_search( multi4.begin(), multi4.end(), n - (index*7))){
			count7 = index;
			count4 = (n - (index*7))/4;
			index = -1;
		}
	}

	if( count4 != 0 || count7 != 0){
		for(int index = 0; index < count4; index++){
			std::cout << "4";
		}

		for(int index = 0; index < count7; index++){
			std::cout << "7";
		}
		std::cout << "\n";
	}
	else{
		std::cout << "-1\n";
	}
	return 0;
}