#include <bits/stdc++.h>

using namespace std;

bool check(int a, int b){
	int t = std::sqrt(a*a + b*b);
	if((a*a + b*b) == t*t){
		return true;
	}
	return false;
}

void preReq(std::vector < long long >& v){
	for(int a = 1; a <= 3000; a++){
		for(int b = a + 1; b <= 3000; b++){
			if(check( a, b)){
				if(a + b + int(sqrt(a*a + b*b)) < 3001){
					v[a + b + int(sqrt(a*a + b*b))] = max(v[a + b + int(sqrt(a*a + b*b))], 1ll*a*b*(int(sqrt(a*a + b*b))));
				}
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::vector < long long > ansA(3001, -1ll);
	preReq(ansA);
	int t, n;
	std::cin >> t;
	while(t--){
		std::cin >> n;
		std::cout << ansA[n] << std::endl;
	}
	return 0;
}