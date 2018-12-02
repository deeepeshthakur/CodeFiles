#include <bits/stdc++.h>

using namespace std;

int moves;
std::vector < int > finalSeq{};
std::vector < std::vector < std::vector < int > > > dpTable( 3001, std::vector < std::vector < int > >( 20, std::vector < int >( 10, -1)));

int recFuncCall( int m, int diff, int curr){
	// std::cout << "Called " << m << " " << diff << " " << curr << "\n"; 
	if(m > 3000 || diff >= 20 || curr > 9){
		return 0;
	}

	if( diff < 0){
		return 0;
	}

	if(dpTable[m][diff][curr] != -1){
		return dpTable[m][diff][curr];
	}

	if(m +1 >= moves){
		dpTable[m][diff][curr] = 1;
		return 1;
	}

	int ans = 0;
	for(int index = 0; index < 10 && ans != 1; index++){
		if(index != curr){
			ans = (ans | recFuncCall( m + 1, index + 1 - diff, index));
			if(ans == 1){
				finalSeq.push_back( index + 1);
			}
		}
	}

	dpTable[m][diff][curr] = ans;
	return dpTable[m][diff][curr];
}

int main(){
	std::ios::sync_with_stdio(false);
	std::vector < bool > availableWeights( 10, false);
	std::string temp{};
	std::cin >> temp;
	for(int index = 0; index < 10; index++){
		if(temp[index] == '1'){
			availableWeights[index] = true;
		}
	}

	// int m;
	std::cin >> moves;

	int ans = 0;
	for(int index = 0; index < 3001; index++){
		for(int x = 0; x < 20; x++){
			for(int y = 0; y < 10; y++){
				if(x == 0 || availableWeights[y] == false){
					dpTable[index][x][y] = 0;
				}
			}
		}
	}
	for(int curr = 0; curr < 10 && ans != 1; curr++){
		ans = (ans | recFuncCall( 0, curr + 1, curr));
		if(ans == 1){
			finalSeq.push_back( curr + 1);
		}
	}
	
	if(ans == 1){
		std::cout << "YES\n";
		for(int index = finalSeq.size() - 1; index >= 0; index--){
			std::cout << finalSeq[index] << " ";
		}
		std::cout << "\n";
	}
	else{
		std::cout << "NO\n";
	}
	return 0;
}