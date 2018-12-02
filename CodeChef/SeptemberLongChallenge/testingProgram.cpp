#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n = 1000;
	std::cin >> n;
	std::vector < int > oddArray{}, evenArray{};
	int temp = 0;
	for(int index = 0; index < n; index++){
		std::cin >> temp;
		if(temp%2){
			oddArray.push_back(temp);
		}
		else{
			evenArray.push_back(temp);
		}
	}
	int xorAns = 0;
	int ans = 0;
	for(int x = 0; x < evenArray.size(); x++){
		for(int y = x + 1; y < evenArray.size(); y++){
			xorAns = (evenArray[x]^evenArray[y]);
			if(xorAns%2 == 0 && xorAns > 2){
				ans++;
			}
		}
	}

	for(int x = 0; x < oddArray.size(); x++){
		for(int y = x + 1; y < oddArray.size(); y++){
			xorAns = (oddArray[x]^oddArray[y]);
			if(xorAns%2 == 0 && xorAns > 2){
				ans++;
			}
		}
	}

	std::cout << ans << "\n";
}

int main(){
	int testcases = 0;
	std::cin >> testcases;
	while(testcases--){
		solve();
	}
	return 0;
}