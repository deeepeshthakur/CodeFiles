#include <bits/stdc++.h>

using namespace std;

long long MOD = 1000000007;

long long powrF( long long a, long long b){
	if(a == 0ll){
		return 0;
	}

	if(b == 0){
		return 1ll;
	}

	if(b == 1){
		return a;
	}

	long long x = powrF( a, b/2);
	if(b%2 == 1){
		return (((x*x)%MOD)*a)%MOD;
	}

	return (x*x)%MOD;
}

long long getNCR( int n, int r, std::vector < long long >& factorialArray){
	long long numr = factorialArray[n];
	long long denr = (factorialArray[r]*factorialArray[n - r])%MOD;
	long long denrI = powrF( denr, MOD - 2ll);
	return (numr*denrI)%MOD;
}

bool checkSumF( int a, int b, long long sum){
	int currDig = 0;
	while(sum){
		currDig = sum%10;
		sum /= 10;
		if(currDig != a && currDig != b){
			return false;
		}
	}
	return true;
}

int main(){
	int a, b, n;
	std::cin >> a >> b >> n;
	long long div = 1000000007;
	std::vector < long long > factorialArray( n + 1, 1);
	for(int index = 1; index < factorialArray.size(); index++){
		factorialArray[index] = (factorialArray[index - 1]*index)%div;
	}

	std::vector < long long > ansArray( n + 1, 0);
	int currSum = 0;
	for(int index = 0; index < ansArray.size(); index++){
		currSum = (index*a) + ((n - index)*b);
		if(checkSumF( a, b, currSum)){
			ansArray[index] = getNCR( n, index, factorialArray);
		} 
	}

	long long finalAns = 0;
	for(int index = 0; index < ansArray.size(); index++){
		finalAns += ansArray[index];
		finalAns %= MOD;
	}

	std::cout << finalAns << "\n";
	return 0;
}