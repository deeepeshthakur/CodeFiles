#include <bits/stdc++.h>

using namespace std;
bool checkFun( long long k, int i, int n, std::vector < long long >& cumSum){
	long long a = cumSum[n] - ( n > 0 ? cumSum[n - 1] : 0ll), 
	          sZero = cumSum[n], 
	          sI = i > 0 ? cumSum[i - 1] : 0ll;

	if((n - i + 1)*a - (sZero - sI) <= k){
		return true;
	}
	return false;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	long long n, k;
	std::cin >> n >> k;
	std::vector < long long > inpArray( n, 0ll), cumSum( n, 0ll);
	for(int index = 0; index < n; index++){
		std::cin >> inpArray[index];
	}

	std::sort( inpArray.begin(), inpArray.end());
	for(int index = 0; index < n; index++){
		cumSum[index] = inpArray[index] + ( index > 0 ? cumSum[index - 1] : 0ll);
	}

	int x = 0, y = 0;
	for(int index = 0; index < n; index++){
		int ydash;
		int low = 0, high = index;
		while(high - low > 1){
			if(checkFun( k, (low + high)/2, index, cumSum)){
				high = (low + high)/2;
			}
			else{
				low = (low + high)/2;
				low++;
			}
		}

		if(checkFun( k, low, index, cumSum)){
			ydash = index - low + 1;
		}
		else{
			ydash = index - high + 1;
		}

		if(ydash > y){
			y = ydash;
			x = inpArray[index];
		}
	}

	std::cout << y << " " << x << "\n";
	return 0;
}