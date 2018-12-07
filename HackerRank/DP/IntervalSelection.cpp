#include <bits/stdc++.h>

using namespace std;

struct pointInterval{
	int start, end;
};

bool compareByEnd( pointInterval a, pointInterval b){
	if(a.end < b.end || (a.end == b.end && a.start <= b.start)){
		return true;
	}
	return false;
}

void solve(){
	int n;
	std::cin >> n;
	std::vector < pointInterval > intervals( n);
	for(int index = 0; index < n; index++){
		std::cin >> intervals[index].start >> intervals[index].end;
	}

	std::sort( intervals.begin(), intervals.end(), compareByEnd);
	

}

int main(){
	int testCases = 0;
	std::cin >> testCases;
	while(testCases--){
		solve();
	}
	return 0;
}