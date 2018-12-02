#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	std::cin >> n;
	std::vector < int > boxes( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> boxes[index];
	}

	std::sort( boxes.begin(), boxes.end());
	std::priority_queue < int , std::vector < int >, std::greater < int > > pq{};
	pq.push( 1);
	for(int index = 1; index < n; index++){
		int curr = pq.top();
		if( curr > boxes[index]){
			pq.push( 1);
		}
		else{
			pq.pop();
			curr++;
			pq.push( curr);
		}
	}

	int ans = pq.size();
	std::cout << ans << "\n";
	return 0;	
}