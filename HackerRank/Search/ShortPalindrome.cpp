#include <bits/stdc++.h>

using namespace std;

int solveFor( std::vector < int > str){
	long long div = 1000000007;
	std::vector < long long > singleCount( 26, 0), doubleCount( 676, 0), tripleCount( 26, 0);
	long long ans = 0;
	for(int index = 0; index < str.size(); index++){
		ans += (tripleCount[str[index]]);
		ans %= div;
		for(int xx = 0; xx < 26; xx++){
			tripleCount[xx] += (doubleCount[xx*26 + str[index]]);
			tripleCount[xx] %= div;
		}

		for(int xx = 0; xx < 26; xx++){
			doubleCount[xx*26 + str[index]] += (singleCount[xx]);
			doubleCount[xx*26 + str[index]] %= div;
		}

		singleCount[str[index]]++;
		singleCount[str[index]] %= div;
	}

	int retVal = ans%div;
	return retVal;
}

int main(){
	std::string str{};
	std::cin >> str;
	std::vector < int > StrVec( str.length(), 0);
	for(int index = 0; index < str.length(); index++){
		StrVec[index] = str[index] - 'a';
	}

	int ans = solveFor(StrVec);
	std::cout << ans << "\n";
	return 0;
}