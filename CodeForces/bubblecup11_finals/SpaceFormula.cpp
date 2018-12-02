#include <bits/stdc++.h>

using namespace std;

bool comp( int a, int b){
	if( a > b){
		return true;
	}
	return false;
}

int main(){
	int n, d;
	std::cin >> n >> d;
	std::vector < int > currentPointsArray( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> currentPointsArray[index];
	}

	std::vector < int > nextRacePoints( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> nextRacePoints[index];
	}

	int finalPoints = currentPointsArray[d - 1] + nextRacePoints[0] - nextRacePoints[n - 1];
	int positionIndex = std::lower_bound( currentPointsArray.begin(), currentPointsArray.end(), finalPoints, comp) - currentPointsArray.begin();
	for(int index = 0; index < positionIndex; index++){
		currentPointsArray[index] += nextRacePoints[index + 1];
	}

	for(int index = positionIndex; index < d - 1; index++){
		currentPointsArray[index] += nextRacePoints[n - 1 - index + positionIndex];
	}

	currentPointsArray[d - 1] += nextRacePoints[0];
	int position = 1;
	for(int index = 0; index < d; index++){
		if(currentPointsArray[index] > currentPointsArray[d - 1]){
			position++;
		}
	}

	std::cout << position << "\n";
	return 0;
}