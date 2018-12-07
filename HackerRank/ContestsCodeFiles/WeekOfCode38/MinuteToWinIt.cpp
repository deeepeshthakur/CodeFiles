#include <bits/stdc++.h>

using namespace std;

int main(){
	int N, K;
	std::cin >> N >> K;
	std::vector< int > input_array(N);
	for(int index = 0; index < N; index++){
		std::cin >> input_array[index];
	}

	std::vector < int > first_elements(N);
	for(int index = 0; index < N; index++){
		first_elements[index] = input_array[index] - (index*K);
	}
	std::sort(first_elements.begin(), first_elements.end());
	int curr_count = 0, max_count = 0, curr_element = first_elements[0];
	for(int index = 0; index < N; index++){
		if(first_elements[index] == curr_element){
			curr_count++;
		}
		else{
			curr_count = 1;
			curr_element = first_elements[index];
		}

		if(curr_count > max_count){
			max_count = curr_count;
		}
	}

	std::cout << N - max_count << std::endl;
	return 0;
}