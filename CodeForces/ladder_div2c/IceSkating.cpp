#include <bits/stdc++.h>

using namespace std;

struct drift{
	int x, y;
};

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector < std::pair < int, drift > > allDrifts( n);
	std::queue < int > discoveryQueue{};
	std::vector < bool > toDiscover( n, true);
	for(int index = 0; index < n; index++){
		allDrifts[index].first = index;
		std::cin >> allDrifts[index].second.x;
		std::cin >> allDrifts[index].second.y;
	}

	for(int index = 0; index < n; index++){
		if(toDiscover[index]){
			toDiscover[index] = false;
			discoveryQueue.push( index);
			while(!discoveryQueue.empty()){
				for(int x = 0; x < n; x++){
					if(allDrifts[discoveryQueue.front()].second.x == allDrifts[x].second.x && toDiscover[x]){
						allDrifts[x].first = index;
						discoveryQueue.push(x);
						toDiscover[x] = false;
					}
				}

				for(int y = 0; y < n; y++){
					if(allDrifts[discoveryQueue.front()].second.y == allDrifts[y].second.y && toDiscover[y]){
						allDrifts[y].first = index;
						discoveryQueue.push(y);
						toDiscover[y] = false;
					}
				}
				discoveryQueue.pop();
			}
		}
	}

	std::set < int > temp{};
	for(int index = 0; index < n; index++){
		temp.insert( allDrifts[index].first);
	}

	int ans = temp.size();
	std::cout << ans - 1 << "\n";
	return 0;
}