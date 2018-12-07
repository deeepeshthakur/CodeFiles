#include <bits/stdc++.h>

using namespace std;


int main(){
	int h, w;
	std::cin >> h >> w;
	std::vector < std::vector < int > > table( h, std::vector < int > (w, 0));
	for(int x = 0; x < h; x++){
		for(int y = 0; y < w; y++){
			std::cin >> table[x][y];
		}
	}

	std::vector < int > ans( 6, 0);
	for(int x = 0; x < h; x++){
		ans[0] += table[x][0];
		for(int y = 0; y < w - 1; y++){
			if(table[x][y] < table[x][y + 1]){
				ans[0] += (table[x][y + 1] - table[x][y]);
			}
		}

		ans[1] += table[x][w - 1];
		for(int y = w - 1; y > 0; y--){
			if(table[x][y - 1] > table[x][y]){
				ans[1] += (table[x][y - 1] - table[x][y]);
			}
		}
	}

	for(int y = 0; y < w; y++){
		ans[2] += table[0][y];
		for(int x = 0; x < h -1; x++){
			if(table[x + 1][y] > table[x][y]){
				ans[2] += (table[x + 1][y] - table[x][y]);
			}
		}

		ans[3] += table[h - 1][y];
		for(int x = h - 1; x > 0; x--){
			if(table[x - 1][y] > table[x][y]){
				ans[3] += (table[x - 1][y] - table[x][y]);
			}
		}
	}

	ans[4] = h*w;
	ans[5] = h*w;

	int ansFinal = 0;

	for(int x : ans){
		ansFinal += x;
		// std::cout << x << "  ";
	}
	// std::cout << std::endl;

	std::cout << ansFinal << std::endl;
	return 0;
}