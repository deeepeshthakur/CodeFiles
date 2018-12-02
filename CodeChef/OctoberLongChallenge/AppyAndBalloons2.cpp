#include <bits/stdc++.h>

using namespace std;
unsigned long long maxC = 1000000000000000000;
unsigned long long lowerLimit = 0, upperLimit = maxC;
std::vector < long long > X;

bool searchF( std::vector < long long >& A, std::vector < long long >& B, long long M, unsigned long long y){
	long long sumX = 0;
	for(int index = 0; index < A.size(); index++){
		sumX += ((A[index]*B[index] - std::min((unsigned long long)A[index]*B[index], y))/B[index]) + ((A[index]*B[index] - std::min((unsigned long long)A[index]*B[index], y))%B[index] > 0 ? 1 : 0);
	}

	bool flag;
	if(sumX <= M){
		flag = true;
	}
	else{
		flag = false;
	}
	return flag;
}

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	long long M;
	std::cin >> M;
	std::vector < long long > A( n, 0), B( n, 0);
	X.resize( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> A[index];
	}

	for(int index = 0; index < n; index++){
		std::cin >> B[index];
	}

	unsigned long long y;
	bool flag;
	while(upperLimit - lowerLimit > (long long)1){
		y = (lowerLimit + upperLimit)/2;
		flag = searchF( A, B, M, y);
		if(flag){
			upperLimit = y;
		}
		else{
			lowerLimit = y;
		}
	}

	if(searchF( A, B, M, lowerLimit)){
		std::cout << lowerLimit << "\n";
	}
	else{
		std::cout << upperLimit << "\n";
	}
	return 0;
}