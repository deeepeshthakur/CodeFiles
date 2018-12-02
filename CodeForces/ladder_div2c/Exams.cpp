#include <bits/stdc++.h>

using namespace std;

struct examDate{
	int initialDate, secondDate;
};

bool compareByDate( examDate a, examDate b){
	if( a.initialDate < b.initialDate){
		return true;
	}

	if( a.initialDate == b.initialDate && a.secondDate < b.secondDate){
		return true;
	}

	return false;
}

int main(){
	int n;
	std::cin >> n;
	std::vector < examDate > datesArray( n);
	for(int index = 0; index < n; index++){
		std::cin >> datesArray[index].initialDate >> datesArray[index].secondDate;
	}

	std::sort( datesArray.begin(), datesArray.end(), compareByDate);
	int currDay = 1;
	for(int index = 0; index < n; index++){
		if(datesArray[index].secondDate > currDay){
			currDay = datesArray[index].secondDate;
		}

		if(datesArray[index].secondDate < currDay){
			currDay = datesArray[index].initialDate;
		}
	}
	std::cout << currDay << "\n";
	return 0;
}