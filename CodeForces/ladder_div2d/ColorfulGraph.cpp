#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector < int > vertices(n, 0);
	int maxM = 0;
	for(int i = 0; i < n; i++){
		std::cin >> vertices[i];
		if(maxM < vertices[i]){
			maxM = vertices[i];
		}
	}

	std::vector < std::set < int > > qArray(maxM + 1);
	int u, v;
	for(int i = 0; i < m; i++){
		std::cin >> u >> v;
		if(vertices[u - 1] != vertices[v - 1]){
			qArray[vertices[u - 1]].insert(vertices[v - 1]);
			qArray[vertices[v - 1]].insert(vertices[u - 1]);
		}
	}

	int maxS = 0, maxI = 0;
	for(int i = 0; i < maxM + 1; i++){
		if(maxS < qArray[i].size()){
			maxS = qArray[i].size();
			maxI = i;
		}
	}
	if(maxS)
	std::cout << maxI << "\n";
	else{
		std::sort(vertices.begin(), vertices.end());
		std::cout << vertices[0] << "\n";
	}
	return 0;
}