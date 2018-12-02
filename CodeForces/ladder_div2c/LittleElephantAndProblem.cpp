#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector < int > inpArr( n, 0), sortArr( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> inpArr[index];
		sortArr[index] = inpArr[index];
	}

	std::sort( sortArr.begin(), sortArr.end());
	bool flag = true;
	std::vector < int > swappedIndices{};
	for(int index = 0; index < n; index++){
		if(sortArr[index] != inpArr[index]){
			flag = false;
			swappedIndices.push_back( index);
		}

		if(swappedIndices.size() > 5){
			index = n;
		}
	}

	if(swappedIndices.size() > 2){
		std::cout << "NO\n";
	}
	else{
		std::cout << "YES\n";
	}

	return 0;
}