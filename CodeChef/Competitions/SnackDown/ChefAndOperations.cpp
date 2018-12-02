#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while( t--){
		int n;
		std::cin >> n;
		std::vector < long long > aArray( n, 0ll), bArray( n, 0ll);
		for(int index = 0; index < n; index++){
			std::cin >> aArray[index];
		}

		for(int index = 0; index < n; index++){
			std::cin >> bArray[index];
		}

		bool flag = true;
		for(int index = 0; index + 2 < n && flag; index++){
			if(aArray[index] <= bArray[index]){
				long long oper = bArray[index] - aArray[index];
				aArray[index] += oper;
				aArray[index + 1] += (oper + oper);
				aArray[index + 2] += (oper + oper + oper);
			}
			else{
				flag = false;
			}
		}

		if(flag){
			if(!(aArray[n - 1] == bArray[n - 1] && aArray[n - 2] == bArray[n - 2])){
				flag = false;
			}
		}

		if(flag){
			std::cout << "TAK\n";
		}
		else{
			std::cout << "NIE\n";
		}
	}
	return 0;
}