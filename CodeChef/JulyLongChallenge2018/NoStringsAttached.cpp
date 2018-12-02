#include <bits/stdc++.h>

using namespace std;

int deltaFunction( int n, int k, int valueOfK, std::vector < std::vector < int > >& counterArray){
	int minM = 2*n;
	for(int alpha = 0; alpha < 26; alpha++){
		int X = 0, Y = 0;
		if(valueOfK >= alpha){
			X = valueOfK - alpha;
		}
		else{
			X = alpha - valueOfK;
		}

		if(alpha - 1 >= 0){
			Y = counterArray[k][alpha - 1];
		}

		Y += (n - 1 - k - counterArray[n - 1][alpha] + counterArray[k][alpha]);

		if(minM > (X + Y)){
			minM = X + Y;
		}
	}
	return minM;
}

void solve(){
	int n;
	std::string str{};
	std::cin >> str;
	std::vector < int > inpArray( str.length(), 0);
	n = inpArray.size();
	for(int index = 0; index < inpArray.size(); index++){
		inpArray[index] = str[index] - 'a';
	}
	std::vector< std::vector < int > > counterArray( inpArray.size(), std::vector < int >(26, 0));// afterIndex( inpArray.size(), std::vector < int >(26, 0));

	for(int index = 0; index < inpArray.size(); index++){
		int currElement = inpArray[index];
		for(int x = currElement; x < 26; x++){
			counterArray[index][x]++;
		}
		if(index > 0){
			for(int x = 0; x < 26; x++){
				counterArray[index][x] += counterArray[index-1][x];
			}
		}
	}

	std::vector < int >	pieArray(n,0), deltaArray( n, 0);
	long sDash = 0;
	for(int index = 0; index < n; index++){
		if(inpArray[index] - 1 >= 0){
			pieArray[index] += counterArray[index][inpArray[index] - 1];
		}

		pieArray[index] += (n - index - 1 + counterArray[index][inpArray[index]] - counterArray[n - 1][inpArray[index]]);
		sDash += (long)(pieArray[index]);
	}

	sDash /= 2;

	for(int index = 0; index < n; index++){
		deltaArray[index] = deltaFunction( n, index, inpArray[index], counterArray);
	}

	long ans = sDash;
	// std::cout << ans << " ";
	for(int index = 0; index < n; index++){
		// std::cout << (sDash - pieArray[index] + deltaArray[index]) << " ";
		if(ans > (sDash - (long)(pieArray[index]) + (long)(deltaArray[index]))){
			ans = sDash - (long)(pieArray[index]) + (long)(deltaArray[index]);
		}
	}

	std::cout << ans << std::endl;

} 

int main(){
	int testcases = 0;
	std::cin >> testcases;
	while(testcases--){
		solve();
	}
	return 0;
}