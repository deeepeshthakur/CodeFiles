#include <bits/stdc++.h>

using namespace std;
std::vector < std::vector < long long > > perm( 16*16, std::vector < long long >( 4, 0));	 
void preCalc(){
	long long i = 0;
	for(long long a = 0; a < 4; a++){
		for(long long b = 0; b < 4; b++){
			for(long long c = 0; c < 4; c++){
				for(long long d = 0; d < 4; d++){
					perm[ i++] = std::vector < long long >{ a, b, c, d};
				}
			}
		}
	}
}

void callF( long long a, long long b, long long x, long long y, std::vector < std::vector < long long > >& points){
	x = x - a;
	y = y - b;
	if(x == 0 && y == 0){
		for(long long index = 0; index < 3; index++){
			points[index][0] = a;
			points[index][1] = b;
		}
		return;
	}

	points[0][0] = x;
	points[0][1] = y;
	points[1][0] = -y;
	points[1][1] = x;
	points[2][0] = -x;
	points[2][1] = -y;
	points[3][0] = y;
	points[3][1] = -x;

	for(long long index = 0; index < 4; index++){
		points[index][0] += a;
		points[index][1] += b;
	}
}

long long dist( long long x1, long long y1, long long x2, long long y2){
	return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}

bool auxf( std::vector < long long > dists){
	for(long long x = 0; x < 6; x++){
		for(long long y = x + 1; y < 6; y++){
			long long i = 0;
			std::vector < long long > temp( 4, 0);
			for(long long index = 0; index < 6; index++){
				if(index != x && index != y){
					temp[i++] = dists[index];
				}
			}

			if(dists[x] == dists[y] && temp[0] == temp[1] && temp[0] == temp[2] && temp[0] == temp[3] && temp[0] > 0 && dists[x] > 0){
				// for( auto p : dists){
				// 	std::cout << p << " ";
				// }
				// std::cout << "\n";
				return true;
			}
		}
	}
	return false;
}

bool isSQ(std::vector < long long >& p1, std::vector < long long >& p2, std::vector < long long >& p3, std::vector < long long >& p4){
	long long s1 = dist( p1[0], p1[1], p2[0], p2[1]), s2 = dist( p2[0], p2[1], p3[0], p3[1]), s3 = dist( p3[0], p3[1], p4[0], p4[1]), s4 = dist( p4[0], p4[1], p1[0], p1[1]);
	long long d1 = dist( p1[0], p1[1], p3[0], p3[1]), d2 = dist( p4[0], p4[1], p2[0], p2[1]);
	std::vector < long long > dd{ s1, s2, s3, s4, d1, d2};
	if(auxf( dd)){
		// std::cout << p1[0] << " " << p1[1] << " " << p2[0] << " " << p2[1] << " " << p3[0] << " " << p3[1] << " " << p4[0] << " " << p4[1] << "\n";
		return true;
	}
	return false;
}

long long finalAnsF( std::vector < std::vector < long long > >& p1, std::vector < std::vector < long long > >& p2, std::vector < std::vector < long long > >& p3, std::vector < std::vector < long long > >& p4){
	long long ans = 50;
	for(long long i = 0; i < 16*16; i++){
		if(isSQ( p1[perm[i][0]], p2[perm[i][1]], p3[perm[i][2]], p4[perm[i][3]])){
			if( ans > (perm[i][0] + perm[i][1] + perm[i][2] + perm[i][3])){
				ans = (perm[i][0] + perm[i][1] + perm[i][2] + perm[i][3]);
			}
		}
	}
	return ans;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	preCalc();
	long long n;
	std::cin >> n;
	std::vector < long long > ans( n, 20);
	std::vector < std::vector < long long > > p1( 4, std::vector < long long >( 2, 0)), p2( 4, std::vector < long long >( 2, 0)), p3( 4, std::vector < long long >( 2, 0)), p4( 4, std::vector < long long >( 2, 0)) ;
	for(long long i = 0; i < n; i++){
		long long a, b, x, y;
		std::cin >> x >> y >> a >> b;
		callF( a, b, x, y, p1);
		// for( auto z : p1){
		// 	std::cout << z[0] << " " << z[1] << "   ";
		// }
		// std::cout << "\n";
		std::cin >> x >> y >> a >> b;
		callF( a, b, x, y, p2);
		std::cin >> x >> y >> a >> b;
		callF( a, b, x, y, p3);
		std::cin >> x >> y >> a >> b;
		callF( a, b, x, y, p4);

		ans[i] = finalAnsF( p1, p2, p3, p4);
		// std::cout << "\n";
		if(ans[i] > 30){
			ans[i] = -1;
		}
	}

	for( auto x : ans){
		std::cout << x << "\n";
	}
	return 0;
}