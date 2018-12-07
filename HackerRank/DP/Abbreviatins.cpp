#include <bits/stdc++.h>

using namespace std;

bool dp(int i, int j, std::vector < std::vector < bool > >& dpTable, std::string& aStr, std::string& bStr){
	if(i && j){
		if(aStr[i - 1] >= 'a' && aStr[i - 1] <= 'z'){
			if(dpTable[i - 1][j])
				return true;
		}

		if((aStr[i - 1] - 'a' == bStr[j - 1] - 'A' || aStr[i - 1] - 'A' == bStr[j - 1] - 'A') && dpTable[i - 1][j - 1])
			return true;

		return false;
	}
	else{
		if(i == 0 && j == 0){
			return true;
		}

		if(i == 0 && j > 0){
			return false;
		}

		if(j == 0 && i > 0){
			if(aStr[i - 1] <= 'z' && aStr[i - 1] >= 'a' && dpTable[i - 1][0]){
				return true;
			}
			return false;
		}
	}
	return false;
}

void f(){
	std::string aStr{}, bStr{};
	std::cin >> aStr >> bStr;
	std::vector < std::vector < bool > > dpTable( aStr.length() + 1, std::vector < bool >(bStr.length() + 1, false));
	for(int x = 0; x < dpTable.size(); x++){
		for(int y = 0; y < dpTable[0].size(); y++){
			dpTable[x][y] = dp( x, y, dpTable, aStr, bStr);
		}
	}

	// for(int x = 0; x < dpTable.size(); x++){
	// 	for(int y = 0; y < dpTable[0].size(); y++){
	// 		if(dpTable[x][y]){
	// 			std::cout << "1 ";
	// 		}
	// 		else{
	// 			std::cout << "0 ";
	// 		}
	// 	}
	// 	std::cout << "\n";
	// }

	if(dpTable[dpTable.size() - 1][dpTable[0].size() - 1]){
		std::cout << "YES\n";
	}
	else{
		std::cout << "NO\n";
	}
}


int main() {
    int q;
    std::cin >> q;
    while(q--){
    	f();
    }
    return 0;
}
