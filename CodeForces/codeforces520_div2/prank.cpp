#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector < bool > inpA(1001, false);
	for(int i = 0; i < n; i++){
		int ii;
		std::cin >> ii;
		inpA[ii] = true;
	}

	int maxG = 0;
	if(inpA[1]){
		int i = 1;
		while(i + 1 < 1001 && inpA[i + 1]){
			i++;
		}
		{
			maxG = i - 1;
		}
	}

	if(inpA[1000]){
		int i = 1000;
		while(i - 1 > -1 && inpA[i - 1]){
			i--;
		}
		{
			if(maxG < 1000 - i){
				maxG = 1000 - i;
			}
		}
	}

	for(int i = 1; i < 1001; i++){
		if(inpA[i]){
			int e = i;
			while(e + 1 < 1001 && inpA[e + 1]){
				e++;
			}
			
				if(e - i - 1 > maxG){
					maxG = e - i - 1;
				}
			
		}
	}

	std::cout << maxG << "\n";

	return 0;
}