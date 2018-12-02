#include <bits/stdc++.h>

using namespace std;
int getDigSum( long long n){
	int sum = 0;
	while(n){
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int main(){
	std::ios::sync_with_stdio(false);
	long long n, dd;
	std::cin >> n >> dd;
	// n %= 1000000000;
	dd = 1000;
	int l = 0;
	
	int ii = 0;
	int lm = 0;
	// for(n = 1; n < 201; n++)
	// {
	std::vector < int > minc( 201, 1000000);
	std::vector < bool > checkA( 201, true);
	n = 128932;
	// n = 25;
	for(n = 1; n < 60; n++)
		{lm = 0;
			int dm;
			for(int d = 1; d < dd; d++)
			{
				// std::vector < bool > checkA( 201, true);
				for(int x = 0; x < 201; x++){
					checkA[x] = true;
				}
				l = 0;
				int index = 0;
				while(l < 20 && index < 10000){
					// std::cout << ii++ << " " << l << " " << n << "\n";
					int x = getDigSum(n + d*(index++));
					if(checkA[x]){
						if(minc[x] > index){
							minc[x] = index;
						}
						checkA[x] = false;
						l++;
					}
				}
			// if(l > lm){
			// 	ii = index;
			// 	lm = l;
			// 	dm = d;
			// }
		// 	if(d == 794)
		// 		{std::cout << ii << " " << l << " " << d << std::endl;
		// 	for(int x = 0; x < 201; x++){
		// 		if(checkA[x]){
		// 			std::cout << x << " ";
		// 		}
		// 	}
		// 	std::cout << std::endl;
		// }
			}
		}
// std::cout << ii << " " << lm << " " << dm << std::endl;	
		for(int x = 0; x < 201; x++){
			if(checkA[x]){
				std::cout << x  << " " << minc[x] << "\n";
			}
		}
		std::cout << std::endl;
	// }
		return 0;
	}