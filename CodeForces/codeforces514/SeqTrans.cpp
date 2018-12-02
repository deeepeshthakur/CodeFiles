#include <bits/stdc++.h>

using namespace std;

int recurseF( int numb, std::vector < int >& ans){
	int currEven = 2, currGCD = ans[ans.size() - 1];
	for(int index = 2; index < n + 1; index++){
		if(index%2 == 0){
			if(index > currEven){
				currEven = index;
			}
		}
		else{
			if(ans.size()){
				ans.push_back( currGCD);
			}
			else{
				ans.push_back(1);
			}
		}
	}
	ans.push_back( currGCD*2);
}

int main(){
	int n;
	std::cin >> n;
	if(n == 1){
		std::cout << "1\n";
		return 0;
	}

	if(n == 2){
		std::cout << "1 2\n";
		return 0;
	}

	if(n == 3){
		std::cout << "1 1 3\n";
		return 0;
	}

	std::vector < int > ans{};
	// std::vector < int > numb( n);
	// for(int index = 0; index < n; index++){
	// 	numb[index] = index + 1;
	// }


	while(n > 3){
		n = recurseF( n, ans);
	}

}