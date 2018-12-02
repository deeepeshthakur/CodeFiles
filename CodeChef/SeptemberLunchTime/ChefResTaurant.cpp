#include <bits/stdc++.h>

using namespace std;

struct interV{
	int start;
	int end;
};

bool comp( interV a, interV b){
	if( a.start < b.start){
		return true;
	}
	return false;
}

void solveFor(){
	int n = 0;
	int m = 0;
	std::cin >> n >> m;
	std::vector < interV > inputIntervals( n);
	std::vector < int > intervalStarts( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> inputIntervals[index].start;
		intervalStarts[index] = inputIntervals[index].start;
		std::cin >> inputIntervals[index].end;
		inputIntervals[index].end--;
	}

	std::sort( inputIntervals.begin(), inputIntervals.end(), comp);
	std::sort( intervalStarts.begin(), intervalStarts.end());

	while(m--){
		int timeArrival = 0;
		std::cin >> timeArrival;
		if(timeArrival >= inputIntervals[n - 1].start){
			if(timeArrival > inputIntervals[n - 1].end)
				std::cout << "-1" << "\n";
			else{
				std::cout << 0 << "\n";
			}
		}
		else{
			if(timeArrival < inputIntervals[0].start){
				std::cout << inputIntervals[0].start - timeArrival << "\n";
			}
			else{
				int left, right;
				left = std::lower_bound( intervalStarts.begin(), intervalStarts.end(), timeArrival) - intervalStarts.begin();
				// std::cout << left << "shjfjs\n";
				if(intervalStarts[left] == timeArrival){
					std::cout << 0 << "\n";
				}
				else{
					left--;
					if(timeArrival >= inputIntervals[left].start && timeArrival <= inputIntervals[left].end){
						std::cout << 0 << "\n";
					}
					else{
						std::cout << inputIntervals[left + 1].start - timeArrival << "\n";
					}
				}
			}
		}
	}
}

int main(){
	int testCases = 0;
	std::cin >> testCases;
	while(testCases--){
		solveFor();
	}
	return 0;
}