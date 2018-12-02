#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, n;
	std::cin >> a >> b >> n;
	std::vector < int > checkArray{};
	checkArray.push_back( a);
	checkArray.push_back( b);
	int fIndex = 0, tIndex = 1;
	int multi = 10;
	for(int index = 2; index < 8; index++){
		for(int x = fIndex; x <= tIndex; x++){
			if(a*multi + checkArray[x] < 9000001)
				checkArray.push_back( a*multi + checkArray[x]);
			if(b*multi + checkArray[x] < 9000001)
				checkArray.push_back( b*multi + checkArray[x]);
		}
		multi *= 10;
		fIndex = tIndex + 1;
		tIndex = checkArray.size() - 1;
	}
	long long div = 1000000007;
	std::vector < long long > factorialArray( n + 1, 1);
	for(int index = 1; index < factorialArray.size(); index++){
		factorialArray[index] = (factorialArray[index - 1]*index)%div;
	}

	std::vector < long long > ansArray( n + 1, 0);
	int currSum = 0;
	for(int index = 0; index < ansArray.size(); index++){
		currSum = (index*a) + ((n - index)*b);
		if(std::binary_search( checkArray.begin(), checkArray.end(), currSum)){
			
		} 
	}

	return 0;
}
