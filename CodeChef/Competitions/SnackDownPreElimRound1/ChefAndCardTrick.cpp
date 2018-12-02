#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	std::cin >> n;
	std::vector < int > inpA( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> inpA[index];
	}
	int countIn = 0;
	for(int index = 1; index < n; index++){
		if(inpA[index - 1] > inpA[index]){
			countIn++;
		}
	}

	if(countIn == 0){
		std::cout << "YES\n";
	}
	else{
		if(countIn == 1 && inpA[n - 1] <= inpA[0]){
			std::cout << "YES\n";
		}
		else{
			std::cout << "NO\n";
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int test;
	std::cin >> test;
	while( test--){
		solve();
	}
	return 0;
}