#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, pos;
	int ans = 0;
	std::cin >> n >> pos;
	std::string str{};
	std::cin >> str;
	std::vector < bool > checkArray( n, false);
	pos--;
	int minIndex = n, maxIndex = 0;
	for(int index = 0; index < n/2; index++){
		if(str[index] != str[n - 1 - index]){
			ans += std::min( 26 - std::abs( str[index] - str[n - 1 - index]), abs( str[index] - str[n - 1 - index]));
			checkArray[index] = true;
			checkArray[n - 1 - index] = true;
			if(index < minIndex){
				minIndex = index;
			}

			if(index > maxIndex){
				maxIndex = index;
			}
		}
	}
	// std::cout << ans << " " << minIndex << " " << maxIndex << "\n";

	if(n%2 && ans > 0){
		if(pos == n/2){
			ans += (pos - minIndex);
		}
		else{
			if(pos > n/2){
				pos = (n - pos - 1);
			}

			int left = std::max((pos - minIndex), 0);
			int right  = std::max((maxIndex - pos), 0);
			ans += std::min( 2*left + right, 2*right + left);
		}
	}
	if(n%2 == 0 && ans > 0){
		if(pos >= n/2){
			pos = (n - 1 - pos);
		}
		int left = std::max((pos - minIndex), 0);
		int right  = std::max((maxIndex - pos), 0);
		// std::cout << pos << " " << left << " " << right << "\n";
		ans += std::min( 2*left + right, 2*right + left);

	}

	std::cout << ans << "\n";
	return 0;
}