#include <bits/stdc++.h>

using namespace std;

void solveFor(){
	int n;
	std::vector < int > multipliers{ 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
	for(int index = 1; index < 26; index++){
		multipliers[index] *= 73;
	}

	std::cin >> n;
	std::string aInput{}, bInput{};
	std::cin >> aInput >> bInput;
	std::vector < std::pair < int, int> > bRollingHash{}, startLen{};
	int currIndex = 0;
	for(int index = 0; index < n; index++){
		int currRollingHash = 0;
		for(int x = index; x < n; x++){
			currRollingHash += multipliers[bInput[x] - 'A'];
			bRollingHash.push_back( std::make_pair( currRollingHash, currIndex));
			startLen.push_back( std::make_pair( index, x));
			currIndex++;
		}
	}

	std::sort( bRollingHash.begin(), bRollingHash.end());
	std::vector < int > diffRollingHashes{};
	std::vector < std::vector < int > > indexVectors{};
	int currElement = -1;
	for(int index = 0; index < bRollingHash.size(); index++){
		if(currElement != bRollingHash[index].first){
			currElement = bRollingHash[index].first;
			diffRollingHashes.push_back( currElement);
		}
	}

	indexVectors.resize( diffRollingHashes.size());
	currIndex = 0;
	for(int index = 0; index < bRollingHash.size(); index++){
		if(diffRollingHashes[currIndex] == bRollingHash[index].first){
			indexVectors[currIndex].push_back(bRollingHash[index].second);
		}
		else{
			currIndex++;
			indexVectors[currIndex].push_back(bRollingHash[index].second);
		}
	}


	int ans = 0;
	for(int index = 0; index < n; index++){
		int currRollingHash = 0;
		for(int x = index; x < n; x++){
			currRollingHash += multipliers[aInput[x] - 'A'];
			if(std::binary_search( diffRollingHashes.begin(), diffRollingHashes.end(), currRollingHash)){
				int ii = std::lower_bound( diffRollingHashes.begin(), diffRollingHashes.end(), currRollingHash) - diffRollingHashes.begin();
				bool flag = false;
				for(int y = 0; y < indexVectors[ii].size() && !flag; y++){
					int bindex = indexVectors[ii][y];
					if((x - index + 1) == (startLen[bindex].second - startLen[bindex].first + 1)){
						std::vector < int > atemp(26, 0), btemp( 26, 0);
						int xxx = 0;
						for(int xx = index; xx <= x; xx++){
							atemp[aInput[xx] - 'A']++;
						}
						for(int xx = startLen[bindex].first; xx <= startLen[bindex].second; xx++){
							btemp[bInput[xx] - 'A']++;
						}
						for(int xx = 0; xx < 26; xx++){
							if(atemp[xx] == btemp[xx]){
								xxx++;
							}
						}

						if(xxx == 26){
							flag = true;
							ans++;
						}
					}
				}
			}
		}
	}
	std::cout << ans << "\n";
}

int main(){
	int test = 0;
	std::cin >> test;
	for(int index = 1; index <= test; index++){
		std::cout << "Case #" << index << ": ";
		solveFor();
	}
	return 0;
}