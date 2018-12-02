#include <bits/stdc++.h>

using namespace std;

bool bsFun( long long y, std::vector < long long >& ingredients, std::vector < long long >& available, std::vector < long long >&price, long long r){
	long long pNeed = std::max((y*ingredients[0] - available[0])*price[0], 0ll) + std::max((y*ingredients[1] - available[1])*price[1], 0ll) + std::max((y*ingredients[2] - available[2])*price[2], 0ll);
	if(pNeed <= r){
		return true;
	}
	return false;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::string hamB;
	std::cin >> hamB;
	std::vector < long long > ingredients( 3, 0),available( 3, 0), price( 3, 0);
	for(int index = 0; index < hamB.length(); index++){
		if(hamB[index] == 'B'){
			ingredients[0]++;
		}
		if(hamB[index] == 'S'){
			ingredients[1]++;
		}
		if(hamB[index] == 'C'){
			ingredients[2]++;
		}
	}
	std::cin >> available[0] >> available[1] >> available[2];
	std::cin >> price[0] >> price[1] >> price[2];
	long long r;
	std::cin >> r;
	long long low = 0, high = 100000000000000ll;
	while(high - low > 1){
		if(bsFun((high + low)/2, ingredients, available, price, r)){
			low = (high + low)/2;
		}
		else{
			high = (low + high)/2;
		}
	}
	if(bsFun( high, ingredients, available, price, r)){
		std::cout << high << "\n";
	}
	else{
		std::cout << low << "\n";
	}
	return 0;
}