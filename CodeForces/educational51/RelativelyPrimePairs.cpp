#include <bits/stdc++.h>

using namespace std;

int main(){
	unsigned long long ll = 0, rr = 0, one = 1;
	std::cin >> ll >> rr;
	std::cout << "YES\n";
	while(ll < rr){
		std::cout << ll << " " << ll + one << "\n";
		ll += (one + one);
	}
	return 0;
}