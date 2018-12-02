#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	std::cin >> n;
	if(n <= 1){
		std::cout << 0 << "\n";
		return 0;
	}
	std::vector < std::vector < int > > reducedStrings( 27);
	std::string temp{};
	for(int index = 0; index < n; index++){
		std::vector < bool > reducingArray( 26, false);
		std::cin >> temp;
		for(int x = 0; x < temp.length(); x++){
			reducingArray[temp[x] - 'a'] = (!reducingArray[temp[x] - 'a']);
		}
		int size = 0, multiplier = 1, number = 0;
		for(int index = 0; index < 26; index++){
			if(reducingArray[index]){
				size++;
				number += (multiplier);
			}
			multiplier *= 2;
		}

		reducedStrings[size].push_back(number);
	}

	std::vector < std::vector < int > > diffStrings( 27);
	std::vector < std::vector < long long > > counterArray( 27);
	for(int index = 0; index < 27; index++){
		std::sort( reducedStrings[index].begin(), reducedStrings[index].end());
		if(reducedStrings[index].size() > 0){
			int currElement = reducedStrings[index][0], count = 0;
			diffStrings[index].push_back(reducedStrings[index][0]);
			counterArray[index].push_back(0);
			for(int x = 0; x < reducedStrings[index].size(); x++){
				if(diffStrings[index][count] == reducedStrings[index][x]){
					counterArray[index][count]++;
				}
				else{
					diffStrings[index].push_back( reducedStrings[index][x]);
					counterArray[index].push_back( 1);
					count++;
				}
			}
		}
	}

	// for(int index = 0; index < 27; index++){
	// 	if(diffStrings[index].size() > 0){
	// 		std::cout << index << " ";
	// 		for(int x = 0; x < diffStrings[index].size(); x++){
	// 			std::cout << diffStrings[index][x] << " " << counterArray[index][x] << "     ";
	// 		}
	// 		std::cout << "\n";
	// 	}
	// }

	long long one = 1, two = 2;
	long long totalPairs = 0;
	for(int index = 0; index < 27; index++){
		if(index < 26){
			int right = index + 1;
			for(int xx = 0; xx < diffStrings[index].size(); xx++){
				for(int y = 0; y < diffStrings[right].size(); y++){
					int x = diffStrings[index][xx] ^ diffStrings[right][y];
					if(x == 1 || x == 2 || x == 4 || x == 8 || x == 16 || x == 32 ||
						x == 64 || x == 128 || x == 256 || x == 512 || x == 1024 ||
						x == 2048 || x == 4096 || x == 8192 || x == 16384 ||
						x == 32768 || x == 65536 || x == 131072 || x == 262144 ||
						x == 524288 || x == 1048576 || x == 2097152 ||
						x == 4194304 || x == 8388608 || x == 16777216 ||
						x == 33554432 || x == 67108864)
					{
						// std::cout << diffStrings[index][xx] << " " << diffStrings[right][y] << " -- " << (counterArray[index][xx]) << " " << (counterArray[index][y]) << "\n";
						totalPairs += (counterArray[index][xx] * counterArray[right][y]);
					}
				}
			}
		}

		if(diffStrings[index].size() > 0)
		{
			for(int x = 0; x < diffStrings[index].size(); x++){
				// std::cout << diffStrings[index][x] << " " << ((counterArray[index][x] - one)*counterArray[index][x])/two <<"\n";
				totalPairs += ((counterArray[index][x] - one)*counterArray[index][x])/two;
			}
		}
	}

	std::cout << totalPairs << "\n";
	return 0;
}

