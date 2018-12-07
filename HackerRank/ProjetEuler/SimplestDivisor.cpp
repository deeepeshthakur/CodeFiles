#include <bits/stdc++.h>

using namespace std;
void f(){
	int n;
	std::cin >> n;
	std::vector < int > numb( n);
	for(int index = 0; index < n; index++){
		numb[index] = index + 1;
	}

	long long ans = 1;
	for(int index = 1; index < n; index++){
		if(numb[index] != 1){
			int x = index, y = numb[index];
			ans *= (long long)y;
			while(x < n){
				numb[x] /= (y);
				x += (index + 1);
			}
		}
	}
	
	std::cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	int test = 0;
	std::cin >> test;
	while( test--){
		f();
	}
	return 0;
}