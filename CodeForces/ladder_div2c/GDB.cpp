#include <bits/stdc++.h>

using namespace std;

int rec( int s, int e, std::vector < int >& heights){
	if(s > e){
		return 0;
	}
	if(s == e){
		return 1;
	}

	int max = 0, in = 0;
	for(int index = s; index <= e; index++){
		if(heights[index] > max){
			max = heights[index];
			in = index;
		}
	}

	return std::min( rec( s, in - 1, heights) + 1, rec( in + 1, e, heights) + 1);

}

void solve(){
	int n;
	std::cin >> n;
	std::vector < int > heights( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> heights[index];
	}

	int ans = rec( 0, n - 1, heights);
	std::cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int test;
	std::cin >> test;
	while( test--)
	{
		solve();
	}
	return 0;
}