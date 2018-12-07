#include <bits/stdc++.h>
using namespace std;

void modified_bfs_call( int curr_node, std::vector < int > &bfs_check, std::vector< std::vector < int > > &bookkeeping, std::vector < int > &bfs_sequence){
  int size_limit = bookkeeping[curr_node].size();
  for(int index = 0; index < size_limit; index++){
    if(bfs_check[bookkeeping[curr_node][index]] == -1){
      bfs_check[bookkeeping[curr_node][index]] = bfs_check[curr_node] + 1;
      bfs_sequence.push_back(bookkeeping[curr_node][index]);
    }
  }
}

void solve(){
  int nodes = 0, edges = 0;
  std::cin >> nodes >> edges;
  std::vector < std::vector < int > > bookkeeping(nodes);
  std::vector < int > bfs_check(nodes, -1);
  std::vector< int > bfs_sequence{};
  for(int index = 0 ; index < edges; index++)
  {
    int first_node = 0, second_node = 0;
    std::cin >> first_node >> second_node;
    bookkeeping[first_node - 1].push_back(second_node - 1);
    bookkeeping[second_node - 1].push_back(first_node - 1);
  }
  int start_node = 0;
  std::cin >>start_node;
  start_node--;
  bfs_check[start_node] = 0;
  bfs_sequence.push_back(start_node);
  int curr_node = 0;
  while(curr_node < bfs_sequence.size()){
    modified_bfs_call(bfs_sequence[curr_node], bfs_check, bookkeeping, bfs_sequence);
    curr_node++;
  }
  for(int index = 0; index < bfs_check.size(); index++){
    if(bfs_check[index] > 0){
      std::cout << (bfs_check[index]*6) << " ";
    }
    else
    if(bfs_check[index] < 0)
    {
      std::cout << -1 << " ";
    }
  }
  std::cout << std::endl;
}

int main(){
  int queries = 0;
  std::cin >> queries;
  for(int index = 0; index < queries; index++)
  {
    solve();
  }
  return 0;
}
