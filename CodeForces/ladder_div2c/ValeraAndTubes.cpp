#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector < std::pair < int, int > > orderArray( n*m, std::make_pair( 0, 0));
	bool flag = true;
	int counter = 0;
	for(int x = 0; x < n; x++){
		if(flag){
			for(int y = 0; y < m; y++){
				// std::cout << x << " " << y << std::endl;
				orderArray[counter].first = x + 1;
				orderArray[counter].second = y + 1;
				counter++;
			}

			flag = false;
		}
		else{
			for(int y = m - 1; y >= 0; y--){
				// std::cout << x << " " << y << std::endl;
				orderArray[counter].first = x + 1;
				orderArray[counter].second = y + 1;
				counter++;
			}

			flag = true;
		}
	}
	// std::cout << " hh " << std::endl;

	int currleft = orderArray.size();
	while(k--){
		if(k > 0){
			int x = orderArray.size() - currleft;
			std::cout << 2 << " ";
			std::cout << orderArray[x].first << " " << orderArray[x].second << " " << orderArray[x + 1].first << " " << orderArray[x + 1].second << "\n";
			currleft -= 2;
		}
		else{
			// int x = orderArray.size() - currleft;
			std::cout << currleft << " ";
			for(int x = orderArray.size() - currleft; x < orderArray.size(); x++){
				std::cout << orderArray[x].first << " " << orderArray[x].second << " ";
			}
			std::cout << "\n";
		}
	}

	return 0;
}