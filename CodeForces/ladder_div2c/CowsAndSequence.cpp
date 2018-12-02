#include <bits/stdc++.h>

using namespace std;
double average( long long s, int n){
	double ans = (1.0 * s)/(1.0 * n);
	return ans;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, currLen = 1, lastT = 0;
	std::cin >> n;
	std::vector < std::vector < long long > > oper( n, std::vector < long long >( 3, 0ll));
	std::vector < long long > currArray( n, 0);
	long long sumM = 0;
	for(int index = 0; index < n; index++){
		int op;
		// std::cin >> op;
		std::cin >> op;
		if(op == 1){
			oper[index][0] = op;
			// std::cin >> oper[index][1] >> oper[index][2];
			std::cin >> oper[index][1] >> oper[index][2];
			sumM += (oper[index][1]*oper[index][2]);
			if(currLen > oper[index][1])
				currArray[oper[index][1] - 1] -= oper[index][2];
			else{
				lastT += oper[index][2];
			}
		}
		if(op == 2){
			oper[index][0] = op;
			// std::cin >> oper[index][1];
			std::cin >>oper[index][1];
			sumM += oper[index][1];
			currArray[currLen - 1] = oper[index][1] - lastT;
			lastT = oper[index][1];
			currLen++;
		}
		if(op == 3){
			oper[index][0] = op;
			sumM -= lastT;
			lastT -= currArray[currLen - 2];
			currLen--;			
			currArray[currLen - 1] = 0;
		}
		// for(auto x : currArray){
		// 	std::cout << x << " ";
		// }
		// std::cout << "\n";
		// std::cout << std::fixed << std::setprecision(7) << average( sumM, currLen) << std::endl;
		printf("%0.7f\n", average( sumM, currLen));
	}
	return 0;
}