#include <bits/stdc++.h>

using namespace std;

std::vector < int > solve4(std::vector < int > vec){
	std::vector < int > ans(4, 0);
	ans[2] = (vec[0]^(vec[1]^vec[2]));
	ans[3] = (vec[1]^(vec[2]^vec[3]));
	ans[0] = (vec[2]^ans[2]^ans[3]);
	ans[1] = (vec[1]^ans[2]^ans[3]);
	return ans;
}

std::vector < int > solve5(std::vector < int > v){
	std::vector < int > ans(5, 0);
	ans[0] = (v[1]^(v[2]^v[4]));
	ans[1] = (v[0]^(v[2]^v[3]));
	ans[2] = (v[0]^(ans[0]^ans[1]));
	ans[3] = (v[1]^(ans[1]^ans[2]));
	ans[4] = (v[2]^(ans[2]^ans[3]));
	return ans;
}

std::vector < int > solve7(std::vector < int > v){
	std::vector < int > ans(7, 0);
	ans[0] = (v[0]^v[2]^v[3]^v[5]^v[6]);
	ans[1] = (v[0]^v[1]^v[3]^v[4]^v[6]);
	ans[2] = (v[0]^ans[0]^ans[1]);
	ans[3] = (v[1]^ans[1]^ans[2]);
	ans[4] = (v[2]^ans[2]^ans[3]);
	ans[5] = (v[3]^ans[3]^ans[4]);
	ans[6] = (v[4]^ans[4]^ans[5]);
	return ans;
}

void inpFunction(int k, int n, std::vector < int >& vec){
	for(int i = 0; i < n; i++){
		std::cout << 1 << " " << k + (i%n) << " " << k + (i + 1)%n << " " << k + (i + 2)%n << std::endl;
		std::cin >> vec[i];
	}
}

void f0(int n){
	std::vector < int > ans(n, 0);
	for(int i = 1; i < n; i+= 4){
		std::vector < int > vec(4, 0);
		inpFunction( i, 4, vec);
		std::vector < int > temp(4, 0);
		temp = solve4(vec);
		ans[i - 1] = temp[0];
		ans[i + 0] = temp[1];
		ans[i + 1] = temp[2];
		ans[i + 2] = temp[3];
	}
	std::cout << 2 << "\n";
	for(int i = 0; i < ans.size(); i++){
		std::cout << ans[i] << " ";
	}
	std::cout << std::endl;
	int inp;
	std::cin >> inp;
}

void f1(int n){
	std::vector < int > ans(n, 0);
	{
		std::vector < int > vec(5, 0);
		inpFunction(1, 5, vec);
		std::vector < int > temp(5, 0);
		temp = solve5(vec);
		int i = 1;
		ans[i - 1] = temp[0];
		ans[i + 0] = temp[1];
		ans[i + 1] = temp[2];
		ans[i + 2] = temp[3];
		ans[i + 3] = temp[4];
	}

	for(int i = 6; i < n; i+= 4){
		std::vector < int > vec(4, 0);
		inpFunction( i, 4, vec);
		std::vector < int > temp(4, 0);
		temp = solve4(vec);
		ans[i - 1] = temp[0];
		ans[i + 0] = temp[1];
		ans[i + 1] = temp[2];
		ans[i + 2] = temp[3];
	}

	std::cout << 2 << "\n";
	for(int i = 0; i < ans.size(); i++){
		std::cout << ans[i] << " ";
	}
	std::cout << std::endl;
	int inp;
	std::cin >> inp;

}

void f2(int n){
	std::vector < int > ans(n, 0);
	{
		std::vector < int > vec(5, 0);
		inpFunction(1, 5, vec);
		std::vector < int > temp(5, 0);
		temp = solve5(vec);
		int i = 1;
		ans[i - 1] = temp[0];
		ans[i + 0] = temp[1];
		ans[i + 1] = temp[2];
		ans[i + 2] = temp[3];
		ans[i + 3] = temp[4];
	}

	{
		std::vector < int > vec(5, 0);
		inpFunction(6, 5, vec);
		std::vector < int > temp(5, 0);
		temp = solve5(vec);
		int i = 6;
		ans[i - 1] = temp[0];
		ans[i + 0] = temp[1];
		ans[i + 1] = temp[2];
		ans[i + 2] = temp[3];
		ans[i + 3] = temp[4];
	}

	for(int i = 11; i < n; i+= 4){
		std::vector < int > vec(4, 0);
		inpFunction( i, 4, vec);
		std::vector < int > temp(4, 0);
		temp = solve4(vec);
		ans[i - 1] = temp[0];
		ans[i + 0] = temp[1];
		ans[i + 1] = temp[2];
		ans[i + 2] = temp[3];
	}

	std::cout << 2 << "\n";
	for(int i = 0; i < ans.size(); i++){
		std::cout << ans[i] << " ";
	}
	std::cout << std::endl;
	int inp;
	std::cin >> inp;
}

void f3(int n){
	std::vector < int > ans(n, 0);
	{
		std::vector < int > vec(7, 0);
		inpFunction(1, 7, vec);
		std::vector < int > temp(7, 0);
		temp = solve7(vec);
		int i = 1;
		ans[i - 1] = temp[0];
		ans[i + 0] = temp[1];
		ans[i + 1] = temp[2];
		ans[i + 2] = temp[3];
		ans[i + 3] = temp[4];
		ans[i + 4] = temp[5];
		ans[i + 5] = temp[6];
	}

	for(int i = 8; i < n; i+= 4){
		std::vector < int > vec(4, 0);
		inpFunction( i, 4, vec);
		std::vector < int > temp(4, 0);
		temp = solve4(vec);
		ans[i - 1] = temp[0];
		ans[i + 0] = temp[1];
		ans[i + 1] = temp[2];
		ans[i + 2] = temp[3];
	}

	std::cout << 2 << "\n";
	for(int i = 0; i < ans.size(); i++){
		std::cout << ans[i] << " ";
	}
	std::cout << std::endl;
	int inp;
	std::cin >> inp;
}

void f(){
	int n;
	std::cin >> n;

	if(n%4 == 0){
		f0(n);
	}

	if(n%4 == 1){
		f1(n);
	}

	if(n%4 == 2){
		f2(n);
	}

	if(n%4 == 3){
		f3(n);
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--){
		f();
	}
	return 0;
}