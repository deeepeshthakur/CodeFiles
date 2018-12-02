#include <bits/stdc++.h>

using namespace std;

struct circle{
	double x, y, rad;
};

double minCalc( circle a, circle b){
	double ans, d;
	double dSquare = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
	
	d = std::sqrt( dSquare);

	if(std::abs( a.rad - b.rad) <= d){
		ans = std::max( 0.0, d - a.rad - b.rad);
	}
	else{
		ans = std::max(std::abs( a.rad - b.rad) - d, 0.0);
	}
	return ans;
}

double maxCalc( circle a, circle b){
	double ans, dSquare, d;
	dSquare = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
	d = std::sqrt( dSquare);
	ans = d + a.rad + b.rad;
	return ans;
}

int main(){
	std::ios::sync_with_stdio(false);

	int n, q;
	std::cin >> n >> q;
	std::vector < circle > inputC( n);
	for(int index = 0; index < n; index++){
		std::cin >> inputC[index].x >> inputC[index].y >> inputC[index].rad;
	}

	long long l = n*(n - 1);
	l /= 2;
	double maxRet, minRet;
	std::vector < double > minArray( l + 10, -1.0), maxArray( l + 10, -1.0);
	l = 0;
	for(int a = 0; a < n; a++){
		for(int b = a + 1; b < n; b++){
			minRet = minCalc( inputC[a], inputC[b]);
			maxRet = maxCalc( inputC[a], inputC[b]);
			minArray[l] = minRet;
			maxArray[l] = maxRet;
			l++;
			
		}
	}

	std::sort( minArray.begin(), minArray.end());
	std::sort( maxArray.begin(), maxArray.end());

	long long kdash;
	double k;
	while(q--){
		std::cin >> kdash;
		k = kdash;
		l = std::distance( std::lower_bound( maxArray.begin(), maxArray.end(), k), maxArray.end()) - std::distance( std::upper_bound( minArray.begin(), minArray.end(), k), minArray.end());
		std::cout << std::max( (long long)0, l) << "\n";
	}

	return 0;
}