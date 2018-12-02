#include <bits/stdc++.h>

using namespace std;
bool binaryS( long long yd, std::vector < int >& rounds, int n){
	int y = yd;
	if(y >= std::max( rounds[rounds.size() - 1], rounds[0] + rounds[1])){
		return true;
	}
	
	if(y < rounds[rounds.size() - 1]){
		return false;
	}
	std::vector < int > carry( n, 0);
	carry[0] = rounds[0];
	for(int index = 1; index < n; index++){
		if(index){
			carry[index] = std::max( 0, rounds[index] + carry[index - 1] - y);
		}
	}
	if(carry[n - 1] > 0){
		return false;
	}

	bool flag = true;
	for(int index = 1; index < n; index++){
		if(y - carry[index] < rounds[index] - carry[index]){
			flag = false;
		}
	}
	return flag;	
}

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector < int > rounds( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> rounds[index];
	}
	std::sort( rounds.begin(), rounds.end());
	long long lowLimit = 0, highLimit = 2*1000000000;
	while(highLimit - lowLimit > 1){
		// std::cout << lowLimit << " " << highLimit << "\n";
		if(binaryS( (lowLimit + highLimit)/2, rounds, n)){
			highLimit = (lowLimit + highLimit)/2;
		}
		else{
			lowLimit = (lowLimit + highLimit)/2;
		}
	}
	long long minM = std::min( lowLimit, highLimit);
	long long maxM = std::max( lowLimit, highLimit);
	// std::cout << minM << " " << maxM << "\n";
	if( binaryS( minM, rounds, n)){
		std::cout << minM << "\n";
	}
	else{
		std::cout << maxM << "\n";
	}
	return 0;
}