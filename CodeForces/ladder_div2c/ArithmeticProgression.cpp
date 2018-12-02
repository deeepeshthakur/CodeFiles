#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector < int > inputs( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> inputs[index];
	}
	std::sort( inputs.begin(), inputs.end());

	if(n == 1){
		std::cout << "-1\n";
		return 0;
	}

	if(n == 2){
		if(inputs[0] == inputs[1]){
			std::cout << 1 << "\n" << inputs[0] << "\n";
			return 0;
		}

		if((inputs[0] + inputs[1])%2 == 0){
			std::cout << "3\n";
		}
		else{
			std::cout << "2\n";
		}

		int d = inputs[1] - inputs[0];
		std::cout << inputs[0] - d << " ";
		if((inputs[0] + inputs[1])%2 == 0){
			std::cout << (inputs[0] + inputs[1])/2 << " ";
		}
		std::cout << inputs[1] + d << "\n";
		return 0;
	}

	int d = inputs[1] - inputs[0], dDash = 0;
	bool flag = true;
	for(int index = 1; index < n && flag; index++){
		if( inputs[index] - inputs[index - 1] != d){
			flag = false;
			dDash = inputs[index] - inputs[index  - 1];
		}
	}

	if(flag){
		if(d == 0){
			std::cout << "1\n" << inputs[0] << "\n";
			return 0;
		}
		std::cout << "2\n";
		std::cout << inputs[0] - d << " " << inputs[n - 1] + d << "\n";
	}
	else{
		if(dDash < d){
			std::swap( d, dDash);
		}

		if(d*2 == dDash){
			int dDashCount = 0;
			bool flag0 = true;
			for(int index = 1; index < n && flag0; index++){
				if((inputs[index] - inputs[index - 1] != d) && (inputs[index] - inputs[index - 1] != dDash)){
					flag0 = false;
				}
				if(dDash == inputs[index] - inputs[index - 1]){
					dDashCount++;
				}
			}

			if(flag0 && dDashCount == 1){
				std::cout << "1\n";
				for(int index = 1; index < n; index++){
					if(inputs[index] - inputs[index - 1] != d){
						std::cout << inputs[index - 1] + d << "\n";
						index = n;
					}
				}
			}
			else{
				std::cout << "0\n";
			}

		}
		else{
			std::cout <<"0\n";
		}
	}	
	return 0;
}