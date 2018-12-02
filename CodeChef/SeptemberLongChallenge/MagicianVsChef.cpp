#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n = 0, x = 0, s = 0;
	std::cin >> n >> x >> s;
	int a, b;
	for(int index = 0; index < s; index++){
		std::cin >> a >> b;
		if( x == a || x == b){
			if(x == a){
				x = b;
			}
			else{
				x = a;
			}
		}
	}
	std::cout << x << "\n";
}

int main(){
	int testCases = 0;
	std::cin >> testCases;
	while(testCases--){
		solve();
	}
	return 0;
}