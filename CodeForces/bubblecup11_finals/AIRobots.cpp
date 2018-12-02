#include <bits/stdc++.h>

using namespace std;

struct robot{
	int pos;
	int radius;
	int IQ;

	robot(){
		pos = 0;
		radius = 0;
		IQ = 0;
	}
};

bool compByIQ( robot a, robot b){
	if( a.IQ < b.IQ){
		return true;
	}
	return false;
}

int main(){
	int n, k;
	std::cin >> n >> k;
	std::vector < robot > allRobots( n);
	for(int index = 0; index < n; index++){
		std::cin >> allRobots[index].pos >> allRobots[index].radius >> allRobots[index].IQ;
	}

	long long ans = 0;
	std::sort( allRobots.begin(), allRobots.end(), compByIQ);
	// for( int index = 0; index < n; index++){
	// 	std::cout << index << "   " << allRobots[index].pos << "   " << allRobots[index].radius << "   " << allRobots[index].IQ << "\n";
	// }

	for(int index = 0; index < n; index++){
		robot temp;
		temp.IQ = allRobots[index].IQ + k;
		int limitIndex = std::upper_bound( allRobots.begin(), allRobots.end(), temp ,compByIQ) - allRobots.begin();
		// std::cout << index << " " << limitIndex << "      --";
		for(int x = index + 1; x < limitIndex; x++){
			if(allRobots[index].IQ - allRobots[x].IQ <= k && std::abs( allRobots[index].pos - allRobots[x].pos) <= std::min( allRobots[index].radius, allRobots[x].radius)){
				ans++;
				// std::cout << x << " ";
			}
		}
		// std::cout << "\n";
	}
	std::cout << ans << "\n";
}