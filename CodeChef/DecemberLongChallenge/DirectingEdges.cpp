#include <bits/stdc++.h>

using namespace std;


void f(){
	int n, m;
	std::cin >> n >> m;
	std::vector < bool > isNodeDiscovered(n, false);
	std::vector < std::vector < int > > edges(m, std::vector < int >(2, 0));
	std::vector < std::vector < int > > outgoingEdges(n);
	for(int i = 0; i < m; i++){
		std::cin >> edges[i][0] >> edges[i][1];
		edges[i][0]--;
		edges[i][1]--;
		outgoingEdges[edges[i][0]].push_back(edges[i][1]);
		outgoingEdges[edges[i][1]].push_back(edges[i][0]);			
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