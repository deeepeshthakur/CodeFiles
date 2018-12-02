#include <bits/stdc++.h>

using namespace std;

bool checkValidity( int s0, int s1, int e0, int e1){
	if(s0 <= s1 && e0 <= e1 && (s0 <= e0 && e0 <= s1) && (e0 <= s1 && s1 <= e1)){
		return true;
	}
	return false;
}

struct ladder{
	int sZero, sOne, eZero, eOne;
	ladder( int s0, int s1, int e0, int e1){
		sZero = s0;
		sOne = s1;
		eZero = e0;
		eOne = e1;
	}
};

bool compBySs( ladder a, ladder b){
	return a.sZero < b.sZero;
}

// bool compByS( const int& l, ladder a){
// 	return l < a.sZero;
// }

// bool compByS( ladder a, const int& l){
// 	return a.sZero < l;
// }

int main(){
	std::ios::sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	std::vector < int > inpArray( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> inpArray[index];
	}

	int s0, s1, e0, e1;
	std::vector < ladder > AllLadders{};		
	for(int index = 0; index < n; index++){
		s0 = index;
		s1 = index;
		while(s1 < n - 1 && inpArray[s1] <= inpArray[s1 + 1]){
			s1++;
		}
		e0 = s1;
		while(e0 > 0 && inpArray[e0 - 1] >= inpArray[e0]){
			e0--;
		}
		e1 = e0;
		while(e1 < n - 1 && inpArray[e1] >= inpArray[e1 + 1]){
			e1++;
		}
		if(checkValidity( s0, s1, e0, e1)){
			AllLadders.push_back({ s0, s1, e0, e1});
			index = s1;
		}
	}

	// std::sort( AllLadders.begin(), AllLadders.end(), compBySs);
	// for(auto x : AllLadders){
	// 	std::cout << x.sZero << " " << x.eOne << " \n";
	// }
	// std::cout << "done\n";
	while(m--){
		int l, r;
		std::cin >> l >> r;
		l--;
		r--;
		if(l == r){
			std::cout << "Yes\n";
			continue;
		}
		int index = std::upper_bound( AllLadders.begin(), AllLadders.end(), ladder{ l, 0, 0, 0}, compBySs) - AllLadders.begin();
		index--;
		if(index >= 0){
			ladder curr( AllLadders[index].sZero, AllLadders[index].sOne, AllLadders[index].eZero, AllLadders[index].eOne);
			if(curr.sZero <= l && l <= r && r <= curr.eOne){
				std::cout << "Yes\n";
			}
			else{
				std::cout << "No\n";
			}
		}
		else{
			std::cout << "No\n";
		}
	}
	return 0;
}