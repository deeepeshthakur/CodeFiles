#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int l;
	if(n%2){
		l = n/2 + 1;
	}
	else{
		l = n/2;
	}

	for(int i = 1; i <= l; i++){
		std::cout << i << " ";
		if(n - i + 1 != i){
			std::cout << n - i + 1 << " ";		
		}
	}
	std::cout << "\n";
	return 0;
}