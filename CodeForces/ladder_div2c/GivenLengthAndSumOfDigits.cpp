#include <bits/stdc++.h>

using namespace std;

bool calcLargest( int m, int s, std::vector < int >& largest){
	bool ans = true;
	int tempS = s;
	if(tempS > 9*m){
		return false;
	}

	if(tempS == 0 && m == 1){
		largest[0] = 0;
		return true;
	}

	if(tempS == 0){
		return false;
	}

	for( int index = 0; index < largest.size(); index++){
		largest[index] = 0;
	}

	for(int index = 1; index <= m && tempS > 0; index++){
		if(tempS >= 9){
			largest[index - 1] += 9;
			tempS -= 9;
		}
		else{
			if(tempS > 0){
				largest[index - 1] += tempS%10;
				tempS = 0;
			}
		}
	}	
	return ans;
}

bool calcSmallest( int m, int s, std::vector < int >& smallest){
	bool ans = true;
	int tempS = s;
	if( tempS > 9*m){
		return false;
	}

	if(tempS == 0 && m == 1){
		smallest[0] = 0;
		return true;
	}

	if(tempS == 0){
		return false;
	}

	for(int index = 0; index < smallest.size(); index++){
		smallest[index] = 0;
	}

	smallest[0] = 1;
	tempS -= 1;
	for(int index = m; index > 0 && tempS > 0; index--){
		if(tempS >= 9){
			smallest[index - 1] += 9;
			tempS -= 9;
		}
		else{
			if(tempS > 0){
				smallest[index - 1] += tempS;
				tempS = 0;
			}
		}
	}
	return ans;
}

int main(){
	int m, s;
	std::cin >> m >> s;
	std::vector < int > largest( m, 0), smallest( m, 0);
	bool flag = true;
	
	flag = calcSmallest( m, s, smallest);
	if(flag){
		for( auto x : smallest){
			std::cout << x;
		}
		std::cout << " ";
	}
	else{
		std::cout << "-1 ";
	}

	flag = calcLargest( m, s, largest);
	if(flag){
		for( auto x : largest){
			std::cout << x;
		}
		std::cout << "\n";
	}
	else{
		std::cout << "-1\n";
	}

	return 0;
}