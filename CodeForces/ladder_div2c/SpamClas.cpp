#include <bits/stdc++.h>

using namespace std;

void solveFor(){
	int n, minM, maxM;
	std::cin >> n >> minM >> maxM;
	long long A = 1, B = 0;
	long long w, y;
	for(int index = 0; index < n; index++){
		std::cin >> w >> y;
		A = (A*w)%2;
		B = (B*w + y)%2;
	}

	long long totalN, oddN, evenN, ans;
	totalN = maxM - minM + 1;
	if(totalN%2 == 0){
		oddN = totalN/2;
		evenN = totalN/2;
	}
	else{
		oddN = totalN/2;
		evenN = totalN/2;
		if(minM%2 == 1){
			oddN++;
		}
		else{
			evenN++;
		}
	}

	std::vector < long long > combin{ oddN + evenN, 0, evenN, oddN};
	ans = combin[ A*2 + B];
	std::cout << ans << " " << totalN - ans << "\n";
}

int main(){
	int test = 0;
	std::cin >> test;
	while(test--){
		solveFor();
	}
	return 0;
}