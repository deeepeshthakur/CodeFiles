#include <bits/stdc++.h>

using namespace std;

struct pointT{
	long long x, y;
};

struct distances{
	long long dist, bikeindex, bikerindex;
};

bool sortByDistance( distances a, distances b){
	if( a.dist < b.dist){
		return true;
	}
	return false;
}

int main(){
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector < pointT > bikerArray( n), bikeArray( m);
	std::vector < bool > checkBikeArray( m, true), checkBikerArray( n, true);

	for(int index = 0; index < n; index++){
		std::cin >> bikerArray[index].x >> bikerArray[index].y;
	}

	for(int index = 0; index < m; index++){
		std::cin >> bikeArray[index].x >> bikeArray[index].y;
 	}

 	std::vector < distances > distanceArray( n*m);
 	int index = 0;
 	for(int nn = 0; nn < n; nn++){
 		for(int mm = 0; mm < m; mm++){
 			distanceArray[index].dist = (bikerArray[nn].x - bikeArray[mm].x)*(bikerArray[nn].x - bikeArray[mm].x) + (bikerArray[nn].y - bikeArray[mm].y)*(bikerArray[nn].y - bikeArray[mm].y);
 			distanceArray[index].bikeindex = mm;
 			distanceArray[index].bikerindex = nn;
 			index++;
 		}
 	}

 	std::sort( distanceArray.begin(), distanceArray.end(), sortByDistance);
 	for(index = 0; index < distanceArray.size(); index++){
 		std::cout << distanceArray[index].bikeindex << " " << distanceArray[index].bikerindex << " " << distanceArray[index].dist << "\n";
 	}
 	long long minTime = 0;
 	int kk = 0;
 	index = 0;
 	while( kk < k){
 		if(checkBikerArray[distanceArray[index].bikerindex] && checkBikeArray[distanceArray[index].bikeindex]){
 			checkBikeArray[distanceArray[index].bikeindex] = false;
 			checkBikerArray[distanceArray[index].bikerindex] = false;
 			// std::cout << distanceArray[index].bikeindex << " " << distanceArray[index].bikerindex << " " << distanceArray[index].dist << "\n";
 			// minTime += distanceArray[index].dist;
 			std::cout << index << " -- ";
 			std::cout << distanceArray[index].bikeindex << "    " << bikeArray[distanceArray[index].bikeindex].x << " " << bikeArray[distanceArray[index].bikeindex].y << "    ";
 			std::cout << distanceArray[index].bikerindex << "    " << bikerArray[distanceArray[index].bikerindex].x << " " << bikerArray[distanceArray[index].bikerindex].y << "   ";
 			std::cout << distanceArray[index].dist << "\n";
 			if(minTime < distanceArray[index].dist){
 				minTime = distanceArray[index].dist;
 			}
 			kk++;
 		}
 		index++;
 	}
 	std::cout << minTime << "\n";
 	return 0;
}