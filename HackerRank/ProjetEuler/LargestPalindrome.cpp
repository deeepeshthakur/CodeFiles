#include <bits/stdc++.h>

using namespace std;

int makePalindrome( int n){
	int pal[6];
	pal[0] = n/100;
	n %= 100;
	pal[1] = n/10;
	pal[2] = n%10;
	pal[5] = pal[0];
	pal[4] = pal[1];
	pal[3] = pal[2];
	int multi = 1, ans = 0;
	for(int i = 5; i > -1; i--){
		ans += (pal[i]*multi);
		multi *= 10;
	}
	return ans;
}

bool checkValidity( int n){
	int i = 100;
	while( (i < 1000) && (i - 1 <= n/i)){
		if( (n%i == 0) && ((n/i) > 99) && ((n/i) < 1000)){
			return true;
		}
		i++;
	}
	return false;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::vector < int > palindromes{}; 
	for(int index = 101; index <= 999; index++){
		int p = makePalindrome( index);
		if(checkValidity( p)){
			palindromes.push_back( p);
		}
	}
	
	std::sort( palindromes.begin(), palindromes.end());
	int test = 0;
	std::cin >> test;
	while( test--){
		int n;
		std::cin >> n;
		int index = std::lower_bound( palindromes.begin(), palindromes.end(), n) - palindromes.begin() - 1;
		std::cout << palindromes[index] << "\n";
	}

	return 0;
}