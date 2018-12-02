#include <bits/stdc++.h>

using namespace std;
struct st{
	int a, b, c;
};

bool greatr( st x, st y){
	if(x.a >= y.a && x.b >= y.b && x.c >= y.c){
		if(x.a > y.a || x.b > y.b || x.c > y.c){
			return true;
		}
	}

	return false;
}

bool check( st x, st y){
	return (greatr( x, y) || greatr( y, x));
}

void solve(){
	st x, y, z;
	std::cin >> x.a >> x.b >> x.c;
	std::cin >> y.a >> y.b >> y.c;
	std::cin >> z.a >> z.b >> z.c;
	bool ans = false;

	ans = ( check( x, y) && check( y, z) && check ( x, z));

	if( ans){
		std::cout << "yes\n";
	}
	else{
		std::cout << "no\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t;
	std::cin >> t;
	for(int index = 0; index < t; index++){
		solve();
	}
	return 0;
}