#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	std::cin >> n;
	std::vector < int > inputArray( n, 0);
	std::vector < bool > outputArray( n, true);
	std::vector < std::vector < int > > counterArray( 101);
	for(int index = 0; index < n; index++){
		std::cin >> inputArray[index];
		counterArray[inputArray[index]].push_back( index);
	}

	std::vector < int > countOneArray{}, countTwoArray{};
	for(int index = 0; index < 101; index++){
		if(counterArray[index].size() == 1){
			countOneArray.push_back(counterArray[index][0]);
		}

		if(counterArray[index].size() > 2){
			countTwoArray.push_back( counterArray[index][0]);
		}
	}

	if(countOneArray.size() > 0){
		if(countOneArray.size()%2 == 0){
			for(int index = 1; index < countOneArray.size(); index += 2){
				outputArray[countOneArray[index]] = false;
			}

			std::cout << "YES\n";
			for(int index = 0; index < outputArray.size(); index++){
				if(outputArray[index]){
					std::cout << "A";
				}
				else{
					std::cout << "B";
				}
			}
			std::cout << "\n";
		}
		else{
			if(countTwoArray.size() > 0){
				for(int index = 1; index < countOneArray.size(); index += 2){
					outputArray[countOneArray[index]] = false;
				}

				outputArray[countTwoArray[0]] = false;

				std::cout << "YES\n";
				for(int index = 0; index < outputArray.size(); index++){
					if(outputArray[index]){
						std::cout << "A";
					}
					else{
						std::cout << "B";
					}
					// std::cout << "\n";
				}
				std::cout << "\n";
			}
			else{
				std::cout << "NO\n";
			}
		}
	}
	else{
		std::cout << "YES\n";
		for(int index = 0; index < n; index++){
			std::cout << "A";
		}
		std::cout << "\n";
	}
	return 0;
}