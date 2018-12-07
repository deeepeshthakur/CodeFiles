#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	std::vector < long long > abArray( 4096, 0), cdArray( 4096, 0);
	int xorAns = 0;
	for(int x = 1; x <= a; x++){
		for(int y = 1; y <= b; y++){
			xorAns = x^y;
			abArray[xorAns]++;
		}
	}

	for(int x = 1; x <= c; x++){
		for(int y = 1; y <= d; y++){
			xorAns = x^y;
			cdArray[xorAns]++;
		}
	}

	long long zeroXor = 0;
	for(int index = 0; index < 4096; index++){
		zeroXor += abArray[index]*cdArray[index];
	}

	long long ans = a;
	ans *= (long long)b;
	ans *= (long long)c;
	ans *= (long long)d;

	ans -= zeroXor;
	std::cout << ans << "\n";
	return 0;
}