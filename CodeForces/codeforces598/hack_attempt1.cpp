#include<bits/stdc++.h>
using namespace std;

int main(){
	srand(time(0));
	int n = rand()%1000 + 1,m = rand()%n + 1,d = rand()%n + 1;
	// std::cin >> n >> m >> 
	std::cout << n << " " << m << " " << d << "\n";

	for(int i=0;i<m;i++){
		std::cout << rand()%(n/m) + 1 << (i < m -1 ? " ":"\n"); 
	}

}