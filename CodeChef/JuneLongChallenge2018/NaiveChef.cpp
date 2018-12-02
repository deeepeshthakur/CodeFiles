#include <bits/stdc++.h>

using namespace std;

void solve( int n, int a, int b){
	std::vector < int > frequency( n, 0);
	int temp = 0;
	for(int index = 0; index < n; index++){
		std::cin >> temp;
		frequency[temp - 1]++;
	}
	double a_freq = frequency[a]*1.0, b_freq = frequency[b]*1.0, den = n*1.0;
	double ans = (a_freq*b_freq)/(den*den);
	std::cout << std::fixed << std::setprecision(10) << (double)ans << "\n";
}

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

	int N, A, B;
	int queries;
	std::cin >> queries;
	while(queries--){
		std::cin >> N >> A >> B;
		solve( N, A - 1, B - 1);
	}
	return 0;
}