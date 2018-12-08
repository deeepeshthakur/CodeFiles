#include <bits/stdc++.h>

using namespace std;
int rec(int a, int b, int c){
	// if(c > 30){
	// 	c = 30;
	// }
	double inc = ((b - a + 1)*1.0)/((c + 2)*1.0);
	if(inc < 1.0){
		inc = 1.0;
	}
	return (a + int(inc));
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, c, t = 1000, ns = 0;
	std::cin >> n >> c;
	int n1 = 1, n2 = n;
	int inp;
	while(n1 < n2){
		int y = rec(n1, n2, c);
		std::cout << 1 << " " << y << std::endl;
		std::cin >> inp;
		if(inp == 0){
			ns = y;
			n1 = y + 1;
			t--;			
		}
		else{
			if(inp = 1){
				std::cout << 2 << std::endl;
				t -= (c + 1);
				n1 = ns;
				n2 = y - 1;
			}
			else{
				n1 = ns;
				n2 = n1;
			}
		}
	}
	inp = 0;
	while(inp == 0){
		ns++;
		std::cout << 1 << " " << ns << std::endl;
		std::cin >> inp;
	}

	std::cout << 3 << " " << ns << std::endl;
	return 0;
}