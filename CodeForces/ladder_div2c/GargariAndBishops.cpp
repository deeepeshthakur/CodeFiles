#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector < std::vector < long long > > chessboard( n, std::vector < long long >( n, 0));
	for(int x = 0; x < n; x++){
		for(int y = 0; y < n; y++){
			std::cin >> chessboard[x][y];
		}
	}

	std::vector < long long > dArray( 2*n, 0), mDashArray( 2*n, 0);
	int k, mDash;
	for(int x = 0; x < n; x++){
		for(int y = 0; y < n; y++){
			k = x + y;
			mDash = x - y + n;
			dArray[k] += chessboard[x][y];
			mDashArray[mDash] += chessboard[x][y];
		}
	}

	long long sum1 = -1, sum2 = -1, temp = 0;
	int x1, y1, x2, y2;
	for(int x = 0; x < n; x++){
		for(int y = (x%2); y < n; y = y + 2){
			k = x + y;
			mDash = x - y + n;
			temp = dArray[k] + mDashArray[mDash] - chessboard[x][y];
			if(temp > sum1){
				sum1 = temp;
				x1 = x;
				y1 = y;
			}
		}

		for(int y = (x + 1)%2; y < n; y = y + 2){
			k = x + y;
			mDash = x - y + n;
			temp = dArray[k] + mDashArray[mDash] - chessboard[x][y];
			if(temp > sum2){
				sum2 = temp;
				x2 = x;
				y2 = y;
			}
		}
	}

	std::cout << sum1 + sum2 << "\n";
	std::cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 <<  " " << y2 + 1 << "\n";
	return 0;
}