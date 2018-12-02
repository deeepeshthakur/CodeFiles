#include <bits/stdc++.h>

using namespace std;
struct Problem
{
	int index, difficulty;

};

bool sortProb( Problem a, Problem b){
	if(a.difficulty < b.difficulty){
		return true;
	}
	if(a.difficulty == b.difficulty && a.index < b.index){
		return true;
	}
	return false;
}

std::vector < std::pair < int, int> > subtaskArray{};
std::vector < int > sortedContestants{};
int calcDifficulty( int s){
	int ans = 0;
	for(int index = 0; index < s; index++){
		std::cin >> subtaskArray[index].first;
	}

	for(int index = 0; index < s; index++){
		std::cin >> subtaskArray[index].second;
	}

	std::vector < int > temp(101, -1);
	for(int index = 0; index < s; index++){
		temp[subtaskArray[index].first] = index;
	}
	int curr = 0;
	for(int index = 0; index < 101; index++){
		if(temp[index] != -1){
			sortedContestants[curr++] = subtaskArray[temp[index]].second;
		}
	}

	for(int index = 0; index < s - 1; index++){
		if(sortedContestants[index] > sortedContestants[index + 1]){
			ans++;
		}
	}
	return ans;
}

int main(){

	int problems = 0, subtasks = 0;
	std::cin >> problems >> subtasks;
	subtaskArray.resize( subtasks);
	sortedContestants.resize( subtasks);
	std::vector < Problem > ProblemArray( problems);
	for(int index = 0; index < problems; index++){
		ProblemArray[index].index = index + 1;
		ProblemArray[index].difficulty = calcDifficulty( subtasks);
	}

	std::sort( ProblemArray.begin(), ProblemArray.end(), sortProb);
	for(int index = 0 ; index < ProblemArray.size(); index++){
		std::cout << ProblemArray[index].index << "\n";
	}
	return 0;
}