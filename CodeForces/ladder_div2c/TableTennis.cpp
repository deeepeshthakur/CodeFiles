#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	long long n, k;
	std::cin >> n >> k;
	long long maxS = 0;
	std::vector < int > strengths( n, 0);
	for(long long index = 0; index < n; index++){
		std::cin >> strengths[index];
		if(maxS < strengths[index]){
			maxS = strengths[index];
		}
	}

	std::queue < int > nextPlayer{};
	long long currP = strengths[0], wins = 0;
	for(long long index = 1; index < n; index++){
		nextPlayer.push( strengths[index]);
	}

	bool flag = true;
	while(k > wins && flag){
		if( currP == maxS){
			flag = false;
		}

		if( currP < maxS){
			long long opp = nextPlayer.front();
			nextPlayer.pop();
			if( currP > opp){
				wins++;
				nextPlayer.push( opp);
			}
			else{
				nextPlayer.push( currP);
				currP = opp;
				wins = 1;
			}
		}
	}

	std::cout << currP << "\n";
	return 0;
}