#include <bits/stdc++.h>

using namespace std;
int checkLimitDay( int n, int k){
	if(k == 1){
		return 10000;
	}
	int minDays = 0;
	while(n > 1){
		minDays++;
		int temp = n/k;
		if(n%k > 0){
			temp++;
		}
		n = temp;
	}

	return minDays;
}

void distribute( std::vector < int >& currElements, int k, int d, std::vector < std::vector < int > >& arrangement){
	if(currElements.size() > 1 && d < arrangement.size()){
		if(currElements.size() <= k){
			for(int index = 0; index < currElements.size(); index++){
				std::vector < int > nextRec{};
				arrangement[d][currElements[index]] = index + 1;
				nextRec.push_back( currElements[index]);
				// distribute( nextRec, k, d + 1, arrangement);
			}
		}else{
			for(int bus = 1; bus <= k; bus++){
				int covered = bus - 1;
				std::vector < int > nextRec{};
				while(covered < currElements.size()){
					arrangement[d][currElements[covered]] = bus;
					nextRec.push_back( currElements[covered]);
					covered += k;
				}
				distribute( nextRec, k, d + 1, arrangement);
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	int n, k, d;
	std::cin >> n >> k >> d;
	std::vector < std::vector < int > > arrangement( d, std::vector < int >( n, 1));
	int limitDay = checkLimitDay( n, k);
	if(limitDay > d || k == 1){
		if(k == 1 && n == 1){
			for(int dd = 0; dd < d; dd++){
				std::cout << 1 << "\n";
			}
		}
		else{
			std::cout << -1 << "\n";\
		}
		
		return 0;
	}

	std::vector < int > currElements( n, 0);
	for(int index = 0; index < n; index++){
		currElements[index] = index;
	}

	distribute( currElements, k, 0, arrangement);
	for(int dd = 0; dd < d; dd++){
		for(int nn = 0; nn < n; nn++){
			std::cout << arrangement[dd][nn] << " ";
		}
		std::cout << "\n";
	}
	return 0;
}