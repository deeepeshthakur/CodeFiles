#include <bits/stdc++.h>

using namespace std;

long long maxOf( long long a, long long b){
	if( a < b){
		return b;
	}
	return a;
}

int main(){
	int n = 0;
	std::cin >> n;
	std::vector < long long > countArray( 100001, 0);
	long long temp;

	for(int index = 0; index < n; index++){
		std::cin >> temp;
		countArray[temp] += temp;
	}
	n = 100001;

	std::vector< long long > dpArray( 100001, 0);
	dpArray[0] = countArray[0];
	if(countArray[1] == 0){
		dpArray[1] = dpArray[0];
	}else{
		if(countArray[0] > countArray[1]){
			dpArray[1] = countArray[0];
		}
		else{
			dpArray[1] = countArray[1];
		}
	}

	for(int index = 2; index < n; index++){
		dpArray[index] = maxOf( dpArray[index - 1], dpArray[index - 2] + countArray[index]);
	}
	long long ans;
	ans = dpArray[100000];
	std::cout << ans << "\n";

	return 0;
}