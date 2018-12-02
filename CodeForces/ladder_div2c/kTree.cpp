#include <bits/stdc++.h>

using namespace std;

long long functionCall( int n, int k){
	long long div = 1000000007;
	if(n < k){
		k = n;
	}

	if(k == 0){
		return 0;
	}

	if(k == 1){
		return 1;
	}

	std::vector < long long > dpArray( n + 1, 0);
	dpArray[1] = 1;
	for(int index = 2; index <= k; index++){
		for(int x = 1; x < index; x++){
			dpArray[index] += dpArray[x];
			dpArray[index] %= div;
		}
		dpArray[index]++;
	}

	for(int index = k + 1; index <= n; index++){
		for(int x = 1; x <= k; x++){
			dpArray[index] += dpArray[index - x];
			dpArray[index] %= div;
		}
	}

	return (dpArray[n]%div);
}


int main(){
	int n, k, d;
	std::cin >> n >> k >> d;
	long long ans1 = 0, ans2 = 0, div = 1000000007;
	ans1 = functionCall( n, k);
	ans2 = functionCall( n, d - 1);
	ans1 -= ans2;
	ans1 = (ans1 + div)%div;
	std::cout << ans1 << "\n";
	return 0;
}