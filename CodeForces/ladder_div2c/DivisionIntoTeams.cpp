#include <bits/stdc++.h>

using namespace std;

struct player{
	int skill, number;
};

bool compBySkill( player a, player b){
	return a.skill < b.skill;
}

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector < player > inputArray( n);
	for(int index = 0; index < n; index++){
		std::cin >> inputArray[index].skill;
		inputArray[index].number = index + 1;
	}

	int maxSkill;
	std::sort( inputArray.begin(), inputArray.end(), compBySkill);
	maxSkill = inputArray[n - 1].skill;
	std::vector < player > teamA{}, teamB{};
	int sumA = 0, sumB = 0;
	for(int index = n - 1; index >= 0; index--){
		
		teamA.push_back( inputArray[index]);
		sumA += inputArray[index].skill;
		index--;

		if(index >= 0)
		{
			teamB.push_back( inputArray[index]);
			sumB += inputArray[index].skill;
		}
		
	}

	if(std::abs(sumA - sumB) <= maxSkill){
		std::cout << teamA.size() << "\n";
		for( auto x : teamA){
			std::cout << x.number << " ";
		}
		std::cout << "\n" << teamB.size() << "\n";
		for(auto x : teamB){
			std::cout << x.number << " ";
		}
		std::cout << "\n";
		return 0;
	}

	for(int index = 0; index < n/2; index++){
		if(!(abs( sumA - sumB) <= maxSkill)){
			sumA += (teamB[teamB.size() - 1 - index].skill - teamA[teamA.size() - 1 - index].skill);
			sumB += (teamA[teamA.size() - 1 - index].skill - teamB[teamB.size() - 1 - index].skill);
			auto temp = teamB[teamB.size() - 1 - index];
			teamB[teamB.size() - 1 - index] = teamA[teamA.size() - 1 - index];
			teamA[teamA.size() - 1 - index] = temp;
		}
		else{
			index = n;
		}
	}

	std::cout << teamA.size() << "\n";
	for( auto x: teamA){
		std::cout << x.number << " ";
	}
	std::cout << teamB.size() << "\n";
	for(auto x : teamB){
		std::cout << x.number << " ";
	}
	std::cout << "\n";
	return 0;
}