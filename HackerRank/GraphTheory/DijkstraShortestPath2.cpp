#include <bits/stdc++.h>
using namespace std;

// long long counter3 = 0, counter2 = 0;

struct edgeNode{
  int dest;
  int weight;
};

edgeNode getEdge( int dest, int weight){
  edgeNode temp_edge { dest, weight};
  return temp_edge;
}

void Input_function( int nodes, int edges, std::vector< std::vector < edgeNode > >& outgoing_edges){
  for(int index = 0; index < edges; index++){
    int src = 0, dest = 0, weight = 0;
    std:cin >> src >> dest >> weight;
    src--;
    dest--;
    outgoing_edges[src].push_back(getEdge( dest, weight));
    outgoing_edges[dest].push_back(getEdge( src, weight));
  }
}

struct heapNode{
  int vertex = 0;
  long long distance = 0;
};

struct heapStructure{
  int capacity = 0;
  int size = 0;
  heapNode *heap_array = NULL;
  int *position_array = NULL;
};

void decrease_distance_function( heapStructure &curr_heap, int vertex, long long value){

  int position_curr_vertex = curr_heap.position_array[vertex];
  curr_heap.heap_array[position_curr_vertex].distance = value;
  int parent_vertex = curr_heap.heap_array[(position_curr_vertex-1)/2].vertex;
  int position_parent_vertex = (position_curr_vertex - 1)/2;

  while(curr_heap.heap_array[position_parent_vertex].distance > curr_heap.heap_array[position_curr_vertex].distance && (position_curr_vertex > 0)){
    curr_heap.position_array[parent_vertex] = position_curr_vertex;
    curr_heap.position_array[vertex] = position_parent_vertex;

    heapNode temp = curr_heap.heap_array[position_parent_vertex];
    curr_heap.heap_array[position_parent_vertex] = curr_heap.heap_array[position_curr_vertex];
    curr_heap.heap_array[position_curr_vertex] = temp;

    position_curr_vertex = curr_heap.position_array[vertex];
    parent_vertex = curr_heap.heap_array[(position_curr_vertex - 1)/2].vertex;
    position_parent_vertex = (position_curr_vertex - 1)/2;
  }
}

void heapify_function( heapStructure &curr_heap, int position){
  while(position < curr_heap.size){
    int right = 2*position + 2, left = 2*position + 1, smallest = position;
    if((right < curr_heap.size) && curr_heap.heap_array[right].distance < curr_heap.heap_array[left].distance){
      smallest = right;
    }

    if(((right < curr_heap.size) && !(curr_heap.heap_array[right].distance < curr_heap.heap_array[left].distance)) || (left < curr_heap.size && right >= curr_heap.size)){
      smallest = left;
    }

    if(curr_heap.heap_array[position].distance > curr_heap.heap_array[smallest].distance){
      int temp_position = curr_heap.position_array[curr_heap.heap_array[position].vertex];
      curr_heap.position_array[curr_heap.heap_array[position].vertex] = curr_heap.position_array[curr_heap.heap_array[smallest].vertex];
      curr_heap.position_array[curr_heap.heap_array[smallest].vertex] = temp_position;

      heapNode temp_node = curr_heap.heap_array[position];
      curr_heap.heap_array[position] = curr_heap.heap_array[smallest];
      curr_heap.heap_array[smallest] = temp_node;

      position = smallest;
    }
    else
    {
      position = curr_heap.size;
    }
  }
}

heapNode extract_Min(heapStructure &curr_heap, std::vector < std::vector < edgeNode> >& outgoing_edges){
  heapNode minNode = curr_heap.heap_array[0];
  int curr_size = curr_heap.size;

  heapNode temp_node = curr_heap.heap_array[0];
  curr_heap.heap_array[0] = curr_heap.heap_array[curr_size - 1];
  curr_heap.heap_array[curr_size - 1] = temp_node;

  curr_heap.position_array[curr_heap.heap_array[0].vertex] = 0;
  curr_heap.position_array[curr_heap.heap_array[curr_size - 1].vertex] = curr_size - 1;

  curr_heap.size = curr_size - 1;
  heapify_function( curr_heap, 0);

  int curr_vertex = minNode.vertex;

  int curr_destination;
  long long curr_edge_weight;
  long long curr_shortest_path;


  for(int index = 0; index < outgoing_edges[curr_vertex].size(); index++){
    curr_destination = outgoing_edges[curr_vertex][index].dest;
    if(curr_heap.position_array[curr_destination] < curr_heap.size){
      curr_edge_weight = outgoing_edges[curr_vertex][index].weight;

      curr_shortest_path = curr_heap.heap_array[curr_heap.position_array[curr_destination]].distance;
      if(curr_shortest_path > (minNode.distance + curr_edge_weight)){
        // counter3++;
        decrease_distance_function( curr_heap, curr_destination, minNode.distance + curr_edge_weight);
      }
    }
  }

  return minNode;
}


void dijkstra_fuction_call( int nodes, int edges, int source, std::vector < std::vector < edgeNode > >& outgoing_edges){
  std::vector < long long > shortest_distances( nodes);
  heapStructure curr_heap{};
  curr_heap.capacity = nodes;
  curr_heap.size = nodes;
  curr_heap.heap_array = new heapNode[curr_heap.capacity];
  curr_heap.position_array = new int[curr_heap.capacity];

  for(int index = 0; index < nodes; index++){
    curr_heap.heap_array[index].vertex = index;
    curr_heap.heap_array[index].distance = 6444854775807;
    curr_heap.position_array[index] = index;
  }

  shortest_distances[source] = 0;
  decrease_distance_function( curr_heap, source, 0);
  for(int index = 0; index < nodes; index++){
    heapNode curr_min = extract_Min( curr_heap, outgoing_edges);
    shortest_distances[curr_min.vertex] = curr_min.distance;
    if(shortest_distances[curr_min.vertex] >= 6444854775807){
      shortest_distances[curr_min.vertex] = -1;
    }
  }

  for(int index = 0; index < source; index++){
    if(shortest_distances[index] < 6444854775807){
      std::cout << shortest_distances[index] << " ";
    }
    else{
      std::cout << -1 << " ";
    }
  }

  for(int index = source + 1; index < nodes; index++){
    if(shortest_distances[index] < 6444854775807){
      std::cout << shortest_distances[index] << " ";
    }
    else{
      std::cout << -1 << " ";
    }
  }

  std::cout << std::endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int queries = 0;
  std::cin >> queries;

  while(queries--){
    int nodes_count = 0, edges_count = 0;
    std::cin >> nodes_count >> edges_count;
    std::vector < std::vector < edgeNode > > list_of_edges(nodes_count);
    Input_function( nodes_count, edges_count, list_of_edges);
    int source = 0;
    std::cin >> source;
    source--;
    dijkstra_fuction_call( nodes_count, edges_count, source, list_of_edges);
  }

  // std::cout <<counter2 <<  "    gdgsz " << counter3 << std::endl;
  return 0;
}
