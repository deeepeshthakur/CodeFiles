#include <bits/stdc++.h>

using namespace std;

void solveFor(){
	int n;
	std::cin >> n;
	std::vector < int > inputArray( 4, 0);
	for(int index = 0; index < n; index++){
		int temp;
		std::cin >> temp;
		inputArray[temp%4]++;
	}

	int sum = 0;
	bool currentWinner = true;
	while(sum%4 != 2){
		if(sum%4 == 0){
			if(inputArray[1] > 0){
				sum += 1;
				sum %= 4;
				inputArray[1]--;
			}
			else{
				if(inputArray[3] > 0){
					sum += 3;
					sum %= 4;
					inputArray[3]--;
				}
				else{
					if(inputArray[0] > 0){
						sum += 0;
						sum %= 4;
						inputArray[0]--;
					}
					else{
						if(inputArray[2] > 0){
							sum += 2;
							sum %= 4;
							inputArray[2]--;
						}
						else{
							sum = 2;
						}
					}
				}
			}
		}

		if(sum%4 == 1){
			if(inputArray[3] > 0){
				inputArray[3]--;
				sum += 3;
				sum %= 4;
			}
			else{
				if(inputArray[2] > 0){
					inputArray[2]--;
					sum += 2;
					sum %= 4;
				}
				else{
					if(inputArray[0] > 0){
						inputArray[0]--;
						sum %= 4;
					}
					else{
						if(inputArray[1] > 0){
							inputArray[1]--;
							sum += 1;
							sum %= 4;
						}
						else{
							sum = 2;
						}
					}
				}
			}
		}

		if(sum%4 == 3){
			if(inputArray[0] > 0){
				inputArray[0]--;
			}
			else{
				if(inputArray[2] > 0){
					inputArray[2]--;
					sum += 2;
					sum %= 4;
				}
				else{
					if(inputArray[1] > 0){
						inputArray[1]--;
						sum += 1;
						sum %= 4;
					}
					else{
						if(inputArray[3] > 0){
							inputArray[3]--;
							sum += 3;
							sum %= 4;
						}
						else{
							sum = 2;
						}
					}
				}
			}
		}

		currentWinner = !(currentWinner);
	}

	if(currentWinner){
		std::cout << "Ghayeeth\n";
	}
	else{
		std::cout << "Siroj\n";
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