#include <bits/stdc++.h>

using namespace std;


int main(){
	int n;
	std::cin >> n;
	// std::vector < int > inputArray( n, 0);
	int x, y, max = 0;
	for(int index = 0; index < n; index++){
		std::cin >> x >> y;
		// inputArray[index] = x + y;
		if(max < x + y){
			max = x + y;
		}
	}
	std::cout << max << "\n";
}