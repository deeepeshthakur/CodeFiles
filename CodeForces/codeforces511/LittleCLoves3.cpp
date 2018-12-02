#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	std::cin >> n;
	if(n%3 == 0){
		int m = n/3;
		if(m%3 == 0){
			std::cout << m - 1 << " " << m - 1 << " " << m + 2 << "\n";
		}

		if(m%3 == 1){
			std::cout << m << " " << m << " " << m << "\n";
		}

		if(m%3 == 2){
			std::cout << m << " " << m << " " << m << "\n";
		}
	}

	if(n%3 == 1){
		int m = (n - 1)/3;
		if(m%3 == 0){
			std::cout << m - 1 << " " << m - 2 << " " << m + 4 << "\n";
		}

		if(m%3 == 1){
			std::cout << m << " " << m << " " << m + 1 << "\n";
		}

		if(m%3 == 2){
			std::cout << m - 1 << " " << m << " " << m + 2 << "\n";
		}
	}

	if(n%3 == 2)
	{
		int m = (n - 2)/3;
		if(m%3 == 0){
			std::cout << m - 1 << " " << m + 1 << " " << m + 2 << "\n";
		}

		if(m%3 == 1){
			std::cout << m << " " << m + 1 << " " << m + 1 << "\n";
		}

		if(m%3 == 2){
			std::cout << m - 1 << " " << m << " " << m + 3 << "\n";
		}
	}

return 0;
}