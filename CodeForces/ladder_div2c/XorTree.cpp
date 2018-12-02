#include <bits/stdc++.h>

using namespace std;

struct nodes
{
	bool oper;
	int height, val, fval;
	std::vector < int > countt;
	std::vector < int > edges;
	nodes(){
		oper = false;
		val = 0;
		fval = 0;
		height = 0;
		edges.resize( 0);
		countt.resize( 2, 0);
	}
};

void startDFS( int node, std::vector < nodes >& tree, std::vector < bool >& checkDFS, int h){
	if(checkDFS[node]){
		checkDFS[node] = false;
		tree[node].height = h;
		for(int index = 0; index < tree[node].edges.size(); index++){
			startDFS( tree[node].edges[index], tree, checkDFS, h + 1);
		}
	}
}

void startDFS2( int node, std::vector < nodes >& tree, std::vector < bool >& checkDFS, int& ans, std::vector < int > v){
	if(!checkDFS[node]){
		checkDFS[node] = true;
		int flips = v[tree[node].height%2];
		if(flips%2){
			tree[node].val = 1 - tree[node].val;
		}

		tree[node].countt[0] = v[0];
		tree[node].countt[1] = v[1];
		if(tree[node].val != tree[node].fval){
			ans++;
			tree[node].countt[tree[node].height%2]++;
			tree[node].oper = true;
		}

		for(int index = 0; index < tree[node].edges.size(); index++){
			startDFS2( tree[node].edges[index], tree, checkDFS, ans, tree[node].countt);
		}
	}
}


int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin >> n;

	std::vector < nodes > tree( n);
	for(int index = 0; index < n - 1; index++){
		int u, v;
		std::cin >> u >> v;
		tree[u - 1].edges.push_back(v - 1);
		tree[v - 1].edges.push_back(u - 1);
	}

	std::vector < bool > checkDFS( n, true);
	startDFS( 0, tree, checkDFS, 0);

	for(int index = 0; index < n; index++){
		std::cin >> tree[index].val;
	}

	for(int index = 0; index < n; index++){
		std::cin >> tree[index].fval;
	}

	int ans = 0;
	startDFS2( 0, tree, checkDFS, ans, { 0, 0});

	std::cout << ans << "\n";
	for(int index = 0; index < n; index++){
		if(tree[index].oper){
			std::cout << index + 1 << "\n";
		}
	}

	return 0;
}