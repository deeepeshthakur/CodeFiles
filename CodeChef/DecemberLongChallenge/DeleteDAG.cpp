#include <bits/stdc++.h>

using namespace std;

struct node{
	int index, height, minParent, childern;
	long long order;
	std::vector < int > edges;
	std::vector < int > oedges;
};

struct compareOrder{
	bool operator()(node const& n1, node const& n2){
		return n1.order > n2.order;
	}
};

void dfs(int curr, std::vector < node >& graph, std::vector < bool >& isDiscovered){
	if(!isDiscovered[curr]){
		isDiscovered[curr] = true;
		for(int i = 0; i < graph[curr].edges.size(); i++){
			dfs(graph[curr].edges[i], graph, isDiscovered);
		}

		int m = 0;
		for(int i = 0; i < graph[curr].edges.size(); i++){
			if(graph[graph[curr].edges[i]].height > m){
				m = graph[graph[curr].edges[i]].height;
			}
		}

		graph[curr].height = m + 1;
	}
}

// void printpq(std::priority_queue < node, std::vector < node >, compareOrder > pq){
// 	while(!pq.empty()){
// 		std::cout << pq.top().index << " " << pq.top().order << " " << pq.top().childern << " " << pq.top().height << " " << pq.top().minParent << std::endl;
// 		pq.pop();
// 	}
// }

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector < bool > isDiscovered(n, false);
	std::vector < node > graph(n);
	for(int i = 0; i < n; i++){
		graph[i].index = i;
		graph[i].height = 0;
		graph[i].minParent = 10000000;
		graph[i].order = 0;
		graph[i].childern = 0;
	}
	{
		int u, v;
		for(int i = 0; i < m; i++){
			std::cin >> u >> v;
			u--;
			v--;
			graph[u].edges.push_back(v);
			graph[v].oedges.push_back(u);
			graph[u].childern++;
		}
	}

	for(int i = 0; i < n; i++){
		if(!isDiscovered[i])
			dfs(i, graph, isDiscovered);
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < graph[i].edges.size(); j++){
			if(graph[graph[i].edges[j]].minParent > graph[i].height){
				graph[graph[i].edges[j]].minParent = graph[i].height;
			}
		}
	}

	for(int i = 0; i < n; i++){
		graph[i].order = graph[i].height*100000000ll + graph[i].minParent;
	}

	std::vector < int > isDeleted(n, false);
	priority_queue <node, std::vector < node >, compareOrder> pq{};
	for(int i = 0; i < n; i++){
		pq.push(graph[i]);
	}

	// int mm;
	// printpq(pq);
	// std::cin >> mm;

	std::vector < long long > ans{};
	while(!pq.empty()){
		while(!pq.empty() && isDeleted[pq.top().index]){
			pq.pop();
		}
		if(!pq.empty()){
			node t = pq.top();
			pq.pop();
			while(!pq.empty() && isDeleted[pq.top().index]){
				pq.pop();
			}
			if(!pq.empty() && pq.top().height == 1){
				ans.push_back((t.index + 1)*10000000ll + pq.top().index + 1);
				node t2 = pq.top();
				pq.pop();
				for(int i = 0; i < t.oedges.size(); i++){
					graph[t.oedges[i]].childern--;
					if(graph[t.oedges[i]].childern <= 0){
						node temp = graph[t.oedges[i]];
						temp.height = 1;
						temp.order = temp.minParent;
						pq.push(temp);
					}
				}
				isDeleted[t.index] = true;
				for(int i = 0; i < t2.oedges.size(); i++){
					graph[t2.oedges[i]].childern--;
					if(graph[t2.oedges[i]].childern <= 0){
						node temp = graph[t2.oedges[i]];
						temp.height = 1;
						temp.order = temp.minParent;
						pq.push(temp);
					}
				}
				isDeleted[t2.index] = true;
			}
			else{
				ans.push_back(t.index + 1);
				for(int i = 0; i < t.oedges.size(); i++){
					graph[t.oedges[i]].childern--;
					if(graph[t.oedges[i]].childern <= 0){
						node temp = graph[t.oedges[i]];
						temp.height = 1;
						temp.order = temp.minParent;
						pq.push(temp);
					}
				}
				isDeleted[t.index] = true;
			}
		}
	}

	std::cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++){
		if(ans[i] >= 10000000ll){
			std::cout << 2 << " " << ans[i]/10000000ll << " " << ans[i]%10000000ll << "\n";
		}
		else{
			std::cout << 1 << " " << ans[i] << "\n";
		}
	}

	return 0;
}