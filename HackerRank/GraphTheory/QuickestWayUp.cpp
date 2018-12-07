#include <bits/stdc++.h>
using namespace std;

void bfs_call( std::queue< int > &bfs_queue, std::vector < int > &quickest_path, std::vector< std::vector< int > > &outgoing_paths){
  int curr_node = bfs_queue.front();
  // std::cout << curr_node;
  for(int index = 1; index <= 6; index++){
    int curr_dest_node = curr_node + index;
    if(curr_dest_node >=0 && curr_dest_node < 100){
      if(quickest_path[curr_dest_node] == 0){
      if(outgoing_paths[curr_dest_node].size() > 0){
        quickest_path[curr_dest_node] = -1;
        for(int path_index = 0; path_index < outgoing_paths[curr_dest_node].size(); path_index++){
          quickest_path[outgoing_paths[curr_dest_node][path_index]] = quickest_path[curr_node] + 1;
          bfs_queue.push(outgoing_paths[curr_dest_node][path_index]);
        }
      }
      else
      {
        quickest_path[curr_dest_node] = quickest_path[curr_node] + 1;
        bfs_queue.push(curr_dest_node);
      }
     }
    }
   }
}


void solve(){
  int ladders = 0, snakes = 0;
  std::vector< std::vector < int > > outgoing_paths(100);
  std::cin >> ladders;
  for(int index = 0; index < ladders; index++){
    int start_point = 0, end_point = 0;
    std::cin >> start_point >>end_point;
    outgoing_paths[start_point - 1].push_back(end_point - 1);
  }

  std::cin >> snakes;
  for(int index = 0; index < snakes; index++){
    int start_point = 0, end_point = 0;
    std::cin >> start_point >> end_point;
    outgoing_paths[start_point - 1].push_back(end_point - 1);
  }

  std::vector< int > quickest_path(100,0);
  std::queue < int > bfs_queue;
  quickest_path[0] = 0;
  bfs_queue.push(0);
  while(!bfs_queue.empty()){
    bfs_call( bfs_queue, quickest_path, outgoing_paths);
    bfs_queue.pop();
  }
  if(quickest_path[99] > 0){
    std::cout << quickest_path[99] << std::endl;
  }
  else{
    std::cout << -1 << std::endl;
  }
}

int main(){
  int queries = 0;
  std::cin >> queries;
  while(queries--){
    solve();
  }
  return 0;
}
