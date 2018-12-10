#include <bits/stdc++.h>

using namespace std;

void getInp(std::vector < int >& t){
	std::string a;
	std::cin >> a;
	for(int i = 0; i < t.size(); i++){
		t[i] = a[i] - '0';
	}
}

void f(){
	int n, k;
	std::cin >> n >> k;
	std::vector < int > inp(n, 0);
	getInp(inp);
	long long m = 0, p;
	for(int i = 0; i < n; i++){
		if(i + k <= n){
			p = 1;
			for(int j = 0; j < k; j++){
				p *= inp[i + j];
			}
			if(p > m){
				m = p;
			}
		}
	}
	std::cout << m << std::endl;
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