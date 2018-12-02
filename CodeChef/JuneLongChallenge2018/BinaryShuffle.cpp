#include <bits/stdc++.h>

using namespace std;

int pofnum(long int num){
	int pofans = 0, index = 0;
	std::vector < int > binar(80,0);
	std::cout << num << " ";
	long int two = 2;
	while(num > 0){
		pofans += (num%two);
		binar[index++] = num%two;
		num /= two;
	}
	std::cout << pofans << "               ";
	for(int i = 79; i >=0; i--){
		std::cout << binar[i];
	}
	std::cout << "\n";
	return pofans;
}

int solve(){
	long int a, b;
	std::cin >> a >> b;
	int ans = 0;
	if(a != b){
		// std::cout << a << " " << b << "\n";
		if(b == 0){
			return -1;
		}else{
			int pofa = pofnum(a), pofb_dash = pofnum(b - 1);
			if(pofa == pofb_dash){
				ans = 1;
			}
			else{
				if(pofa > pofb_dash){
					ans = 2;
				}

				if(pofa < pofb_dash){
					ans = pofb_dash - pofa + 1;
				}
				
			}
		}
	}
	pofnum(b);
	return ans;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int queries;
	std::cin >> queries;
	while( queries--){
		std::cout << solve() << "\n";
	}
	return 0;
}