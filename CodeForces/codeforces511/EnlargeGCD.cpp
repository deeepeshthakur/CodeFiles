#include <bits/stdc++.h>

using namespace std;
int GCDFunction( int a, int b){
	if(a > b){
		int temp = a;
		a = b;
		b = temp;
	}

	if(b == 0){
		return a;
	}
	
	return GCDFunction( b, a%b);
}

int main(){
	int n;
	std::vector < int > inputArray( n, 0);
	for(int index = 0; index < x; index++){
		std::cin >> inputArray[index];
	}

	int gcd;
	std::sort( inputArray.begin(), inputArray.end());
	gcd = inputArray[0];
	for(int index = 0; index < n; index++){
		gcd = GCDFunction( inputArray[index], gcd);
	}

	for(int index = 0; index < n; index++){
		inputArray[index] /= gcd;
	}

	std::vector < bool > checkArray( n , true);
	return 0;
}