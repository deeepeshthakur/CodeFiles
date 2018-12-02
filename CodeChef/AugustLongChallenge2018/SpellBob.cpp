#include <bits/stdc++.h>

using namespace std;

std::vector < std::vector < int > > aux{ { 0, 1, 2}, { 0, 2, 1}, { 1, 0, 2}, { 1, 2, 0}, { 2, 0, 1}, { 2, 1, 0}};

bool solve(){
	// bool ans = false;
	std::string a{}, b{};
	std::cin >> a >> b;
	for(int index = 0; index < 6; index++){
		if((a[aux[index][0]] == 'b' || b[aux[index][0]] == 'b') && (a[aux[index][1]] == 'o' || b[aux[index][1]] == 'o') && (a[aux[index][2]] == 'b' || b[aux[index][2]] == 'b')){
			return true;
		}
	}
	return false;
}

int main(){
	int testCases;
	std::cin >> testCases;
	while(testCases--){
		bool ans = solve();
		if(ans){
			std::cout << "yes\n";
		}
		else{
			std::cout << "no\n";
		}
	}
	return 0;
}