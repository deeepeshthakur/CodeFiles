#include <bits/stdc++.h>

using namespace std;

struct inputEvent{
	int start, end;
};

struct bstPoint{
	int id, pos, index;
};

struct bstStarts{
	int pos, index;
};

inline bool operator < ( const bstStarts& a, const bstStarts& b){
		return a.pos < b.pos;
	}

	// bool operator == (const bstStarts b){
	// 	if(pos == b.pos){
	// 		return true;
	// 	}

	// 	return false;
	// }

	// bool operator > (const bstStarts b){
	// 	if(pos > b.pos){
	// 		return true;
	// 	}

	// 	return false;
	// }

bool compByStarts( bstStarts a, bstStarts b){
	if( a.pos < b.pos){
		return true;
	}
	return false;
}

bool compByPos( bstPoint a, bstPoint b){
	if(a.pos < b.pos){
		return true;
	}
	return false;
}

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector < inputEvent > inputArray( n);
	std::vector < bool > checkArray( n, false);
	for(int index = 0; index < n; index++){
		std::cin >> inputArray[index].start >> inputArray[index].end;
	}

	std::vector < bstPoint > auxArray( 2*n);
	for(int index = 0; index < n; index++){
		auxArray[2*index].id = 0;
		auxArray[2*index].pos = inputArray[index].start;
		auxArray[2*index].index = index;
		auxArray[2*index + 1].id = 1;
		auxArray[2*index + 1].pos = inputArray[index].end;
		auxArray[2*index + 1].index = index;
	}

	int ans = 0, anss;
	std::sort( auxArray.begin(), auxArray.end(), compByPos);
	std::set< bstStarts > sortedStarts;
	for(int x = 0; x < auxArray.size(); x++){
		if( auxArray[x].id == 0){
			bstStarts temp;
			temp.pos = auxArray[x].pos;
			temp.index = auxArray[x].index;
			sortedStarts.insert( temp);
		}
		else{
			 bstStarts temp;
			 temp.pos = inputArray[auxArray[x].index].start;
			 temp.index = auxArray[x].index;
			 // auto it = sortedStarts.find( temp);
			 sortedStarts.erase(temp);
			 anss = std::distance( sortedStarts.begin(), sortedStarts.lower_bound( temp));
			 if(anss >= 1)
			 	checkArray[temp.index] = true;
		}
	}

	for(int index = 0; index < n; index++){
		if(checkArray[index]){
			ans++;
		}
	}
	std::cout << ans << "\n";
	return 0;
}