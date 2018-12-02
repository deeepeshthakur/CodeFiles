#include <bits/stdc++.h>

using namespace std;

unsigned long long auxFunction1( unsigned long long a, unsigned long long b, unsigned long long d){
	unsigned long long multi = a, temp = b, ten = 10, ans = 0;
	while(temp){
		ans += (((temp%ten)*multi)%d);
		ans %= d;
		temp /= ten;
		multi *= ten;
		multi %= d;
	}

	return ans;
}

unsigned long long getFor( unsigned long long a, unsigned long long n, unsigned long long d){
	std::vector < unsigned long long > powersOfTwo(45, 0);
	powersOfTwo[0] = a%d;
	for(int index = 1; index < powersOfTwo.size(); index++){
		powersOfTwo[index] = auxFunction1(powersOfTwo[index - 1], powersOfTwo[index - 1], d);
	}
	std::vector < int > binaryOfN{};
	unsigned long long temp = n, two = 2;
	while(temp){
		binaryOfN.push_back( temp%2);
		temp /= 2;
	}
	unsigned long long ans = 1;
	for(int index = 0; index < binaryOfN.size(); index++){
		if(binaryOfN[index] == 1){
			ans = auxFunction1( ans, powersOfTwo[index], d);
		}
	}
	return ans;
}

unsigned long long getMod( unsigned long long a, unsigned long long b, unsigned long long n, unsigned long long d){
	if(b == 0){
		return 0;
	}
	unsigned long long ans = 0;
	ans = (getFor( a%d, n, d)%d + getFor( b%d, n ,d)%d);
	ans %= d;
	return ans;
}

unsigned long long gcdCalc( unsigned long long a, unsigned long long b){
	if( a < b){
		unsigned long long temp = a;
		a = b;
		b = temp;
	}

	if(b == 0){
		return a;
	}

	return gcdCalc( b, a%b);
}

int main(){
	unsigned long long div = 1000000007;
	int testCases = 0;
	std::cin >> testCases;
	while(testCases--){
		unsigned long long A, B, N, ans;
		std::cin >> A >> B >> N;
		if(A - B)
			ans = gcdCalc( A - B, getMod( A, B, N, A - B));
		else{
			ans = getMod( A, B, N, div);
		}
		std::cout << ans%div << "\n"; 
	}
	return 0;
}