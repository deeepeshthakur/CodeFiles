#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::string s{};
	std::cin >> s;
	std::vector < std::vector < int > > counter( n, std::vector < int >( 26, 0));
	for(int index = 0; index < n; index++){
		counter[index][s[index] - 'a']++;
		if(index){
			for(int x = 0; x < 26; x++){
				counter[index][x] += counter[index - 1][x];
			}
		}
	}

	int letterC = 0;
	for(int x = 0; x < n; x++){
		for(int y = x; y < n; y++){
			letterC = 0;
			for(int index = 0; index < 26; index++){
				letterC = std::max(letterC, counter[y][index] - ( x > 0 ? counter[x - 1][index] : 0));
			}
			
			if(letterC <= (y - x + 1)/2){
				std::cout << "YES\n";
				for(int ii = x; ii <= y; ii++){
					std::cout << s[ii];
				}
				std::cout << "\n";
				return 0;
			}
		}
	}

	std::cout << "NO\n";
	return 0;
}