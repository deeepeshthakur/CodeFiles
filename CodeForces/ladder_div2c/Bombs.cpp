#include <bits/stdc++.h>

using namespace std;

bool compBySum( std::pair< int, int >& a, std::pair< int, int >& b){
	if(std::abs(a.first) + std::abs(a.second) > std::abs( b.first) + std::abs( b.second)){
		return false;
	}
	return true;
}

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector < std::pair < int, int > > pointsArray( n);
	for(int index = 0; index < n; index++){
		std::cin >> pointsArray[index].first >> pointsArray[index].second;
	}


	std::sort( pointsArray.begin(), pointsArray.end(), compBySum);
	int count = 0;
	for(int index = 0; index < n; index++){
		if(pointsArray[index].first != 0){
			count += 2;
		}

		if(pointsArray[index].second != 0){
			count += 2;
		}
		count += 2;
	}

	// std::vector < std::string > ansArray(1000001);
	// int count = 0;
	std::cout << count << std::endl;

	for(int index = 0; index < pointsArray.size(); index++){
		if(pointsArray[index].first > 0){
			std::cout << "1 " << std::abs(pointsArray[index].first) << " R\n";
		}

		if(pointsArray[index].first < 0){
			std::cout << "1 " << std::abs(pointsArray[index].first) << " L\n";
		}

		if(pointsArray[index].second > 0){
			std::cout << "1 " << std::abs(pointsArray[index].second) << " U\n";
		}

		if(pointsArray[index].second < 0){
			std::cout << "1 " << std::abs(pointsArray[index].second) << " D\n";
		}

		std::cout << "2\n";

		if(pointsArray[index].first > 0){
			std::cout << "1 " << std::abs(pointsArray[index].first) << " L\n";
		}

		if(pointsArray[index].first < 0){
			std::cout << "1 " << std::abs(pointsArray[index].first) << " R\n";
		}

		if(pointsArray[index].second > 0){
			std::cout << "1 " << std::abs(pointsArray[index].second) << " D\n";
		}

		if(pointsArray[index].second < 0){
			std::cout << "1 " << std::abs(pointsArray[index].second) << " U\n";
		}

		// ansArray[count++] = std::string("3\n");
		std::cout << "3\n";
		
	}
	return 0;
}