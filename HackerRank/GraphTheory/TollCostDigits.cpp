#include <bits/stdc++.h>
using namespace std;

class edgeNode{
private:
	bool discovered = false;
	int source;
	int destination;
	int weight;
public:
	edgeNode() = default;
	edgeNode( int s, int d, int w) : source(s), destination(d), weight(w) , discovered(false) {}

	void setSource( int s){
		source = s;
	}

	void setDestination( int d){
		destination = d;
	}

	void setWeight( int w){
		weight = w;
	}

	void setAll( int s, int d, int w){
		setSource( s);
		setDestination( d);
		setWeight( w);
	}

	void setDiscovered(){
		discovered = true;
	}

	int getSource(){
		return source;
	}

	int getDestination(){
		return destination;
	}

	int getWeight(){
		return weight;
	}

	bool getStatus(){
		return discovered;
	}
};

class node{
private:
	std::vector< long long > outgoing_table, incoming_table;

public:
	node() : outgoing_table( 10, 0), incoming_table( 10, 0) {}

	long long getFromOutgoingTable( int index){
		return outgoing_table[index];
	}

	void addToOutgoingTable( int index, long long val){
		outgoing_table[index] += val;
	}

};

void discover_edge( int index, std::vector< node >& node_array, std::vector < edgeNode >& edge_array){
	if(!edge_array[index].getStatus()){

		edge_array[index].setDiscovered();
		int source = edge_array[index].getSource(), destination = edge_array[index].getDestination(), weight = edge_array[index].getWeight();
		std::vector< long long > addtionalSource( 10, 0);
		std::vector< long long > addtionalDestination( 10, 0);



		for(int index = 0; index < 10; index++){
			addtionalSource[(10 - weight + index)%10] += node_array[destination].getFromOutgoingTable(index);
			addtionalDestination[(weight + index)%10] += node_array[source].getFromOutgoingTable(index);
		}

		addtionalSource[(10 - weight)%10]++;
		addtionalDestination[(weight)%10]++;

		for(int index = 0; index < 10; index++){
			node_array[source].addToOutgoingTable( index, addtionalSource[index]);
			node_array[destination].addToOutgoingTable( index, addtionalDestination[index]);
		}
	}
}


void solve( int nodes, int edges){
	std::vector< node > node_array(nodes);
	std::vector< edgeNode > edge_array(edges);

	for( int input = 0; input < edges; input++){
		int source = 0, destination = 0, weight = 0;
		std::cin >> source >> destination >> weight;
		source--; destination--; weight %= 10;
		edge_array[input].setAll( source, destination, weight);
		// node_array[source].addEdge( index);
	}

	for(int index = 0; index < edges; index++){
		discover_edge( index, node_array, edge_array);
	}

	std::vector< long long > ans( 10, 0);
	for(int index = 0; index < nodes; index++){
		for(int x = 0; x < 10; x++){
			ans[x] += node_array[index].getFromOutgoingTable( x);
		}
	}

	for(int index = 0; index < 10; index++){
		std::cout << ans[index] << "\n";
	}
}

int main(){
	int nodes = 0, edges = 0;
	std::cin >> nodes >> edges;
	solve( nodes, edges);
	return 0;
}
