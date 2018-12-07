#include <bits/stdc++.h>
using namespace std;

void solver_function( int node, std::vector< std::vector < int > > &outgoing_edges, std::vector < int > &child_counting_array, int& ans){
  int outgoing_edges_count = outgoing_edges[node].size();
  for(int index = 0; index < outgoing_edges_count; index++){
    if(child_counting_array[outgoing_edges[node][index]]%2 == 0){
      ans++;
    }
    solver_function(outgoing_edges[node][index], outgoing_edges, child_counting_array, ans);
  }
}

void modified_dfs( int node, std::vector< std::vector < int > > &outgoing_edges, std::vector< int > &child_counting_array){
  int outgoing_edges_count = outgoing_edges[node].size();
  for(int index = 0; index < outgoing_edges_count; index++){
    modified_dfs( outgoing_edges[node][index], outgoing_edges, child_counting_array);
    child_counting_array[node] += (child_counting_array[outgoing_edges[node][index]]);
  }
  child_counting_array[node]++;
}

void solve(int nodes, int edges){
  std::vector < std::vector < int > > outgoing_edges(nodes);
  for( int index = 0; index < edges; index++){
    int first_index = 0, second_index = 0;
    std::cin >> first_index >> second_index;
    // outgoing_edges[first_index - 1].push_back(second_index -1);
    outgoing_edges[second_index - 1].push_back(first_index - 1);
  }

  std::vector < int > child_counting_array( nodes, 0);
  // dfs_check[0] = false;
  modified_dfs( 0, outgoing_edges, child_counting_array);
  int ans = 0;
  solver_function( 0, outgoing_edges, child_counting_array, ans);
  std::cout << ans << endl;
}

int main(){
  int nodes = 0, edges = 0;
  std::cin >> nodes >> edges;
  solve( nodes, edges);
  return 0;
}
