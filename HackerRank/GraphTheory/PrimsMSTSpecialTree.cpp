#include <bits/stdc++.h>
using namespace std;

struct edgeNode{
	int destination;
	int weight;

	edgeNode( int d, int w){
		destination = d;
		weight = w;
	}

	bool operator < ( edgeNode a){
		return weight < a.weight;
	}


	bool operator < ( int w){
		return weight < w;
	}
};

class myCompare{
public:
	int operator() (const edgeNode& e1, const edgeNode& e2){
		return e1.weight > e2.weight;
	}
};

struct node{
	bool detected = false;
	std::vector < edgeNode > edges{};

	void addEdge( int d, int w){
		edges.push_back(edgeNode( d, w));
	}
};

struct heapStructure{
	
	std::vector < bool > detected{};

	std::priority_queue < edgeNode, std::vector < edgeNode >, myCompare> current_heap;

	void addNode( int n, std::vector < node >& nodes_array){
		detected[n] = true;
		int edge_count = nodes_array[n].edges.size();
		for(int index = 0; index < edge_count; index++){
			if(!detected[nodes_array[n].edges[index].destination]){
				current_heap.push(nodes_array[n].edges[index]);
			}
		}
	}

	edgeNode getEdge(){
		edgeNode temp = current_heap.top();
		while(detected[temp.destination] && (!current_heap.empty())){
			current_heap.pop();
			temp = current_heap.top();
		}
		if(current_heap.empty()){
			temp.weight = 0;
		}
		return temp;
	}

	void resizeDetectedArray( int nodes_count){
		detected.resize( nodes_count, false);
	}
};

int solve( int start, int nodes, int edges, std::vector < node >& nodes_array){

	int total_weight = 0;
	int detected_nodes_count = 0;
	heapStructure heap;
	heap.resizeDetectedArray( nodes);
	heap.addNode( start, nodes_array);
	nodes_array[start].detected = true;
	detected_nodes_count++;

	while(detected_nodes_count <= nodes){
		edgeNode e = heap.getEdge();
		nodes_array[e.destination].detected = true;
		detected_nodes_count++;
		heap.addNode( e.destination, nodes_array);
		total_weight += e.weight;
	}

	return total_weight;
}

int main(){
	int nodes = 0, edges = 0;
	scanf("%i %i", &nodes, &edges);
	std::vector < node > nodes_array( nodes);
	for(int index = 0; index < edges; index++){
		int n1 = 0, n2 = 0, weight = 0;
		scanf("%i %i %i", &n1, &n2, &weight);
		n1--;
		n2--;
		nodes_array[n1].addEdge( n2, weight);
		nodes_array[n2].addEdge( n1, weight);
	}

	int start = 0;
	scanf("%i", &start);
	start--;

	int ans = solve( start, nodes, edges, nodes_array);
	printf("%i\n", ans);
	return 0;
}