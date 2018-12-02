#include <bits/stdc++.h>

using namespace std;

void solveFor(){
	int n, q;
	std::cin >> n >> q;
	std::vector < int > inputA( n, 0), inputB( n, 0), modifiedB( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> inputA[index];
	}

	for(int index = 0; index < n; index++){
		std::cin >> inputB[index];
		modifiedB[index] = inputB[index];
	}

	std::sort( modifiedB.begin(), modifiedB.end());
	std::vector < int > diffInputs{};
	int currElement = -1;
	for(int index = 0; index < n; index++){
		if(currElement != modifiedB[index]){
			currElement = modifiedB[index];
			diffInputs.push_back(currElement);
		}
	}

	std::vector < int > similarityCounter( n, 0);
	std::vector < std::vector < int > > elementCounterB(diffInputs.size());
	int pos = 0;
	for(int index = 0; index < n; index++){
		if(index > 0){
			similarityCounter[index] += similarityCounter[index - 1];
		}
		pos = std::lower_bound( diffInputs.begin(), diffInputs.end(), inputB[index]) - diffInputs.begin();

		if(inputA[index] == inputB[index]){
			// similarityIndex[ pos].push_back(index);
			similarityCounter[index]++;
		}

		elementCounterB[pos].push_back( index);
	}

	int ans = similarityCounter[n - 1];
	while( q--){
		int l, r, c;
		std::cin >> l >> r >> c;
		l = (l^ans) - 1;
		r = (r^ans) - 1;
		c = (c^ans);
		// std::cout << "    " << l << " " << r << " " << c << "      ";

		ans = similarityCounter[n - 1] - similarityCounter[r];
		if(l > 0){
			ans += similarityCounter[l - 1];
		}

		// std::cout << ans << "    ";

		if(std::binary_search( diffInputs.begin(), diffInputs.end(), c)){
			int index = std::lower_bound( diffInputs.begin(), diffInputs.end(), c) - diffInputs.begin();
			int left = std::lower_bound( elementCounterB[index].begin(), elementCounterB[index].end(), l) - elementCounterB[index].begin();
			int right = std::upper_bound( elementCounterB[index].begin(), elementCounterB[index].end(), r) - elementCounterB[index].begin();
			right--;
			ans += std::max( 0, right - left + 1);
		}

		std::cout << ans << "\n";
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