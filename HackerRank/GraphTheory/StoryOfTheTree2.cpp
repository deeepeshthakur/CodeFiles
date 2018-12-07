#include <bits/stdc++.h>
using namespace std;

struct edgeNode{
  int weight;
  int destination;

  edgeNode( int w, int d){
    weight = w;
    destination = d;
  }

  bool operator < ( edgeNode b){
    return destination < b.destination;
  }

  bool operator < ( int d){
    return destination < d;
  }
};

struct newNode{
  int parent_big_node = -1;
  std::vector < edgeNode > outgoingEdges{};

  void change_parent_node( int p){
    parent_big_node = p;
  }

  void addEdge( int w, int d){
    outgoingEdges.push_back( edgeNode( w, d));
  }

  void sortEdges(){
    std::sort( outgoingEdges.begin(), outgoingEdges.end());
  }

  void modifyEdgeWeight( int w, int d){
    int index = std::lower_bound( outgoingEdges.begin(), outgoingEdges.end(), d) - outgoingEdges.begin();
    outgoingEdges[index].weight = w;
  }
};

struct bigNode{
  int child_node_count = 0;
  int score = 0;
  bool collect = true, distribute = true;
  std::vector < int > internal_nodes{};
  std::vector < int > outgoing_edges{};
  std::vector < int > incoming_edges{};

  void addInternalNode( int n){
    internal_nodes.push_back(n);
  }

  void addOutgoingEdge( int n){
    outgoing_edges.push_back(n);
  }

  void addIncomingEdge( int n){
    incoming_edges.push_back(n);
  }

  void sortInternalNodes(){
    std::sort(internal_nodes.begin(), internal_nodes.end());
  }

  void sortOutgoingEdges(){
    std::sort( outgoing_edges.begin(), outgoing_edges.end());
  }

  void sortIncomingEdges(){
    std::sort( incoming_edges.begin(), incoming_edges.end());
  }
};

void modified_dfs( int node, int &big_node_count, std::vector< newNode >& nodes_array, std::vector < bool >& dfs_search, bigNode& ans){
  if(dfs_search[node]){
    ans.child_node_count++;
    ans.addInternalNode( node);
    nodes_array[node].change_parent_node(big_node_count);
    dfs_search[node] = false;
    int index = 0;
    while(index < nodes_array[node].outgoingEdges.size()){
      if(nodes_array[node].outgoingEdges[index].weight == 0){
        int curr_dest = nodes_array[node].outgoingEdges[index].destination;
        modified_dfs( curr_dest, big_node_count, nodes_array, dfs_search, ans);
      }
      index++;
    }
  }
}

void collector_function( int big_node, std::vector < bigNode >& big_nodes_array){
  if(big_nodes_array[big_node].collect){
    
    big_nodes_array[big_node].collect = false;
    big_nodes_array[big_node].score = 0;
    for(int index = 0; index < big_nodes_array[big_node].outgoing_edges.size(); index++){
      if(big_nodes_array[big_nodes_array[big_node].outgoing_edges[index]].collect){
        collector_function( big_nodes_array[big_node].outgoing_edges[index], big_nodes_array);
        big_nodes_array[big_node].score += big_nodes_array[big_nodes_array[big_node].outgoing_edges[index]].score + 1;
      }
    }

    for(int index = 0; index < big_nodes_array[big_node].incoming_edges.size(); index++){
      if(big_nodes_array[big_nodes_array[big_node].incoming_edges[index]].collect){
        collector_function( big_nodes_array[big_node].incoming_edges[index], big_nodes_array);
        big_nodes_array[big_node].score += big_nodes_array[big_nodes_array[big_node].incoming_edges[index]].score;
      }

    }
    
  }
}

void distributor_function( int big_node, std::vector < bigNode >& big_nodes_array){
  if(big_nodes_array[big_node].distribute){
    big_nodes_array[big_node].distribute = false;
    for(int index = 0; index < big_nodes_array[big_node].outgoing_edges.size(); index++){
      int dest = big_nodes_array[big_node].outgoing_edges[index];
      if(big_nodes_array[dest].distribute){
        big_nodes_array[dest].score = big_nodes_array[big_node].score - 1;
        distributor_function( dest, big_nodes_array);
      }
    }

    for(int index = 0; index < big_nodes_array[big_node].incoming_edges.size(); index++){
      int dest = big_nodes_array[big_node].incoming_edges[index];
      if(big_nodes_array[dest].distribute){
        big_nodes_array[dest].score = big_nodes_array[big_node].score + 1;
        distributor_function( dest, big_nodes_array);
      }
    }
    
  }
}

void reduced_form( int &numerator, int &denominator){
  int factor = numerator;
  while(factor > 1){
    if(denominator%factor == 0 && numerator%factor == 0){
      numerator /= factor;
      denominator /= factor;
      factor = 1;
    }
    factor--;
  }
}

void solve(){
  int nodes = 0;
  scanf("%i", &nodes);

  std::vector < newNode > nodes_array(nodes);
  for(int index = 0; index < nodes - 1; index++){
    int source = 0, destination = 0;
    scanf("%i %i", &source, &destination);
    source--;
    destination--;
    nodes_array[source].addEdge( 0, destination);
    nodes_array[destination].addEdge( 0, source);
  }
  
  for(int index = 0; index < nodes_array.size(); index++){
    nodes_array[index].sortEdges();
  }
  
  int guess = 0, threshold_points = 0;
  scanf("%i %i", &guess, &threshold_points);
  
  std::vector < std::vector < int > > guess_array( guess, std::vector< int >(2));
  for(int index  = 0; index < guess; index++){
    int source = 0, destination = 0;
    scanf("%i %i", &source, &destination);
    
    source--;
    destination--;
    nodes_array[source].modifyEdgeWeight( 1, destination);
    nodes_array[destination].modifyEdgeWeight( 1, source);
    guess_array[index][0] = source;
    guess_array[index][1] = destination;
  }
  
  
  std::vector< bool > dfs_search( nodes, true);
  std::vector< bigNode > big_nodes_array{};
  int big_node_count = 0;
  for(int index = 0; index < nodes; index++){
    if(dfs_search[index]){
      
      bigNode temp;
      modified_dfs( index, big_node_count, nodes_array, dfs_search, temp);
      big_nodes_array.push_back(temp);
      big_node_count++;
    }
  }

  for(int index = 0; index < guess; index++){
    int source_big_node = nodes_array[guess_array[index][0]].parent_big_node, destination_big_node = nodes_array[guess_array[index][1]].parent_big_node;
    big_nodes_array[source_big_node].addOutgoingEdge( destination_big_node);
    big_nodes_array[destination_big_node].addIncomingEdge( source_big_node);
  }
  
  collector_function( 0,  big_nodes_array);
  distributor_function( 0, big_nodes_array);

  int numerator = 0, denominator = nodes;
  for(int index = 0; index < big_nodes_array.size(); index++){    
    if(big_nodes_array[index].score >= threshold_points){
      numerator += big_nodes_array[index].child_node_count;
    }
  }

  for(int index = 0; index < nodes_array.size(); index++){
    std::cout << index + 1 << " ";
    std::cout << big_nodes_array[nodes_array[index].parent_big_node].score << std::endl;
  }

  if(numerator > 0){
    reduced_form( numerator, denominator);
  }else{
    denominator = 1;
  }
  printf("%i/%i\n", numerator, denominator);
}

int main(){
  int queries = 0;
  scanf("%i",&queries);
  while(queries--){
    solve();
  }
  return 0;
}
