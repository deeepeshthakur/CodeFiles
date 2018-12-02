#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int n, k;
	std::cin >> n >> k;
	if(n > 1){
		if(k < n/2){
			std::cout << -1 << "\n";
		}
		else{
			int x = k - (n/2) + 1;
			std::vector < int > ansArray( n, 0);
			ansArray[0] = x;
			ansArray[1] = 2*x;
			if(n%2 == 0){
				int l = 1;
				for(int index = 2; index < n; index++){
					while((l == x || l == 2*x || l + 1 == x || l + 1 == 2*x)){
						l += 2;
					}

					ansArray[index] = l;
					ansArray[index + 1] = l + 1;
					index++;
					l += 2;
				}
			}
			else{
				int l = 1;
				for(int index = 2; index < n - 1; index++){
					while((l == x || l == 2*x || l + 1 == x || l + 1 == 2*x)){
						l += 2;
					}

					ansArray[index] = l;
					ansArray[index + 1] = l + 1;
					index++;
					l += 2;
				}

				l += 2;
				while((l == x || l == 2*x || l + 1 == x || l + 1 == 2*x)){
					l += 2;
				}
				ansArray[n - 1] = l;
			}
			for(int index = 0; index < n; index++){
				std::cout << ansArray[index] << " ";
			}
			std::cout << "\n";
		}
	}
	else{
		if(k > 0){
			std::cout << -1 << "\n";
		}
		else{
			std::cout << 1 << "\n";
		}
	}
	return 0;
}