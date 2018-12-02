#include <bits/stdc++.h>

using namespace std;

int solveFor( int a, int b, int c){

	int ans = 0;
	if(a < b){
		int temp = a;
		a = b;
		b = temp;
	}

	if(a < c){
		int temp = a;
		a = c;
		c = temp;
	}

	if(c > b){
		int temp = c;
		c = b;
		b = temp;
	}
	if(b == 0 && c == 0){
		return 0;
	}

	int kOne = a - b, kTwo = b - c;
	if(kOne > kTwo){
		ans += kTwo;
		a -= 2*kTwo;
		b -= kTwo;
		kOne = a - b;
		kTwo = b;
		if(kOne < (2*kTwo)){
			ans += c + kOne/3;
		}
		else{
			if(kOne >= 3*kTwo){
				ans += 2*kTwo;
			}
			else{
				ans += c + kOne/3;
			}
		}
	}
	else{
		if(kOne == kTwo){
			ans = b;
		}
		else{
			// std::cout << "ajkha";
			ans = kOne;
			a -= 2*kOne;
			b -= kOne;
			ans += c;
			a -= c;
			b -= c;
			ans += (2*a)/3;			
		}
	}
	return ans;
}

int main(){
	int r, g, b;
	std::cin >> r >> g >> b;
	int ans = solveFor( r, g, b);
	std::cout << ans << "\n";
	return 0;
}