#include <bits/stdc++.h>

using namespace std;
int minIndex;

int rmQuery( std::vector < int >& heights, std::vector < int >& segTree, int s, int e, int qs, int qe, int i){
	if( qs <= s && qe >= e){
		return segTree[i];
	}

	if(e < qs || s > qe){
		return minIndex;
	}

	int mid = (s + e)/2;

	int l = rmQuery( heights,segTree, s, mid, qs, qe, 2*i + 1);
	int r = rmQuery( heights, segTree, mid + 1, e, qs, qe, 2*i + 2);

	if(heights[l] > heights[r]){
		return l;
	}
	return r;
}

int constructSt( std::vector < int >& heights, int s, int e, std::vector < int >& segTree, int i){
	if(s == e){
		segTree[i] = s;
		return s;
	}

	int mid = (s + e)/2;

	int l = constructSt( heights, s, mid, segTree, i*2 + 1);
	int r = constructSt( heights, mid + 1, e, segTree, i*2 + 2);

	if(heights[l] > heights[r]){
		segTree[i] = l;
	}
	else{
		segTree[i] = r;
	}

	return segTree[i];
}	


int rec( int s, int e, std::vector < int >& heights, std::vector < int >& segTree){
	if(s > e){
		return 0;
	}
	if(s == e){
		return 1;
	}

	int in = rmQuery( heights, segTree, 0, heights.size() - 1, s, e, 0);
	
	return std::min( rec( s, in - 1, heights, segTree) + 1, rec( in + 1, e, heights, segTree) + 1);

}

void solve(){
	int n;
	std::cin >> n;
	std::vector < int > heights( n, 0);
	int minM = 1000000000;
	for(int index = 0; index < n; index++){
		std::cin >> heights[index];
		if(minM > heights[index]){
			minM = heights[index];
			minIndex = index;
		}
	}

	int x = int(std::ceil(log2(n)));
	int maxS = 2*(int)pow( 2, x + 1) - 1;

	std::vector < int > segTree( maxS, 0);

	constructSt( heights, 0, n - 1, segTree, 0);

	int ans = rec( 0, n - 1, heights, segTree);
	std::cout << ans << "\n";
}

int main(){
	int t;
	std::cin >> t;
	for(int i = 0; i < t; i++){
		solve();
	}
	return 0;
}