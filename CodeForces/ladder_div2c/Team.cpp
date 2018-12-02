#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	std::cin >> n >> m;
	if((m > 2*n + 2) || (n > m + 1)){
		std::cout << "-1\n";
	}
	else{
		if(m == 2*n + 2){
			std::cout << "11";
			for(int index = 0; index < n; index++){
				std::cout << "011";
			}
			std::cout << "\n";
		}

		if(m == 2*n + 1){
			std::cout << "1";
			for(int index = 0; index < n; index++){
				std::cout << "011";
			}
			std::cout << "\n";
		}

		if(m == 2*n){
			// std::cout << "11";
			for(int index = 0; index < n; index++){
				std::cout << "011";
			}
			std::cout << "\n";
		}

		if(n == m){
			for(int index = 0; index < m; index++){
				std::cout << "10";
			}
			std::cout << "\n";
		}

		if(n == m + 1){
			std::cout << "0";
			for(int index = 0; index < m; index++){
				std::cout << "10";
			}
			std::cout << "\n";
		}

		if( m < 2*n && m > n){
			int c = m - n;
			for(int index = 0; index < c; index++){
				std::cout << "011";
			}
			for(int index = 0; index < n - c; index++){
				std::cout << "01";
			}
			std::cout << "\n";
		}
	}
	return 0;
}