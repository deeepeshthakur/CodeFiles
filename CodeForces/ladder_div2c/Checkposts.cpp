#include <bits/stdc++.h>

using namespace std;

struct node{
	bool discovered = false;
	int index, root;
	long long cost;
	std::vector < int > incomingRoads, outgoingRoads;
	node(){
		root = -1;
		cost = 0;
	}

	node( int _i){
		index = _i;
		root = -1;
		cost = 0;
	}
};

void addRoad( int u, int v, std::vector < node >& allNodes){
	allNodes[u].outgoingRoads.push_back( v);
	allNodes[v].incomingRoads.push_back( u);
}

void discoverNode( int index, std::stack< int >& currStack, std::vector < node >& allNodes){
	
	if(!allNodes[index].discovered){
		allNodes[index].discovered = true;
		for(int x = 0; x < allNodes[index].outgoingRoads.size(); x++){
			discoverNode( allNodes[index].outgoingRoads[x], currStack, allNodes);
		}
		currStack.push(index);
	}
}

void assignFuntion( int v, int root, std::vector < node >& allNodes){
	if(allNodes[v].root == -1){
		allNodes[v].root = root;
		for(int x = 0; x < allNodes[v].incomingRoads.size(); x++){
			assignFuntion( allNodes[v].incomingRoads[x], root, allNodes);
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector < node > allNodes( n);
	for(int index = 0; index < n; index++){
		allNodes[index].index = index;
		std::cin >> allNodes[index].cost;
		allNodes[index].root = -1;
	}

	int m;
	std::cin >> m;
	while( m--){
		int u, v;
		std::cin >> u >> v;
		addRoad( u - 1, v - 1, allNodes);
	}

	std::stack < int > currStack{};
	for(int index = 0; index < n; index++){
		discoverNode( index, currStack, allNodes);
	}

	while(!currStack.empty()){
		int currV = currStack.top();
		currStack.pop();
		assignFuntion( currV, currV + 1, allNodes);

	}

	std::map < int , std::pair < long long, long long > > minMs{};
	for(int index = 0; index < n; index++){
		if(minMs.find(allNodes[index].root) != minMs.end() && minMs.size() > 0){
			auto it = minMs.find( allNodes[index].root);
			if(it->second.first == allNodes[index].cost){
				it->second.second++;
			}
			else{
				if(it->second.first > allNodes[index].cost){
					it->second.first = allNodes[index].cost;
					it->second.second = 1ll;
				}
			}
		}
		else{
			minMs.insert({ allNodes[index].root, { allNodes[index].cost, 1ll}});
		}
	}

	long long cost = 0, waysM = 1;
	for(auto it = minMs.begin(); it != minMs.end(); it++){
		cost += (it->second.first);
		waysM *= (it->second.second);
		waysM %= 1000000007;
	}

	std::cout << cost << " " << waysM << "\n";
	return 0;
}