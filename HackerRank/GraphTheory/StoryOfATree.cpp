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
  int score = 0;
  int total_score = 0;
  bool first_flag = true, second_flag = true;
  std::vector < edgeNode > outgoingEdges{};

  void addEdge( int w, int d){
    outgoingEdges.push_back( edgeNode( w, d));
  }

  void sortEdges(){
    std::sort( outgoingEdges.begin(), outgoingEdges.end());
  }

  int current_weight( int d){
    int index = std::lower_bound( outgoingEdges.begin(), outgoingEdges.end(), d) - outgoingEdges.begin();
    return outgoingEdges[index].weight;
  }

  void modifyEdgeWeight( int w, int d){
    int index = std::lower_bound( outgoingEdges.begin(), outgoingEdges.end(), d) - outgoingEdges.begin();
    outgoingEdges[index].weight = w;
  }

  void add_score(){
    total_score += score;
    score = 0;
  }

  void make_flags_true(){
    first_flag = true;
    second_flag = true;
  }
};

int score_calculation( int node, std::vector < newNode >& nodes_array){
  int score = 0;
  if(nodes_array[node].first_flag){
    nodes_array[node].first_flag = false;
    int edges = nodes_array[node].outgoingEdges.size();
    for(int index = 0; index < edges; index++){
      int curr_dest = nodes_array[node].outgoingEdges[index].destination;
      int curr_weight = nodes_array[node].outgoingEdges[index].weight;
      if(nodes_array[curr_dest].first_flag){
        if(curr_weight == 1){
          score++;
        }
        score += score_calculation( curr_dest, nodes_array);
      }
    }
  }
  return score;
}

void calculate_score_all( int node, std::vector < newNode >& nodes_array){
  if(nodes_array[node].second_flag){
    nodes_array[node].second_flag = false;
    int edges = nodes_array[node].outgoingEdges.size();
    for(int index = 0; index < edges; index++){
      int curr_dest = nodes_array[node].outgoingEdges[index].destination;
      int curr_weight = nodes_array[node].outgoingEdges[index].weight;
      if(nodes_array[curr_dest].second_flag){
        if(curr_weight == 0){
          nodes_array[curr_dest].score = nodes_array[node].score;          
        }

        if( curr_weight == -1){
          nodes_array[curr_dest].score = nodes_array[node].score + 1;
        }

        if(curr_weight == 1){
          nodes_array[curr_dest].score = nodes_array[node].score - 1;
        }
        calculate_score_all( curr_dest, nodes_array);
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
  
  std::vector < int > curr_guess( 2, 0);
  std::vector < std::vector < int > > guess_array_one{}, guess_array_two{};
  for(int index  = 0; index < guess; index++){
    int parent = 0, child = 0;
    scanf("%i %i", &parent, &child);
    
    parent--;
    child--;

    curr_guess[0] = parent;
    curr_guess[1] = child;
    if(nodes_array[parent].current_weight( child) == 0 && nodes_array[child].current_weight( parent) == 0){
      nodes_array[parent].modifyEdgeWeight( 1, child);
      nodes_array[child].modifyEdgeWeight( -1, parent);
      guess_array_one.push_back( curr_guess);
    }
    else
    {
      guess_array_two.push_back( curr_guess);
    }    
  }

  nodes_array[nodes/2].score = score_calculation( nodes/2, nodes_array);
  calculate_score_all( nodes/2, nodes_array);

  for(int index = 0; index < guess_array_one.size(); index++){
    int parent = guess_array_one[index][0], child = guess_array_one[index][1];
    nodes_array[parent].modifyEdgeWeight( 0, child);
    nodes_array[child].modifyEdgeWeight( 0, parent);
  }

  for(int index = 0; index < nodes; index++){
    nodes_array[index].make_flags_true();
    nodes_array[index].add_score();
  }

  for(int index = 0; index < guess_array_two.size(); index++){
    int parent = guess_array_two[index][0], child = guess_array_two[index][1];
    nodes_array[parent].modifyEdgeWeight( 1, child);
    nodes_array[child].modifyEdgeWeight( -1, parent);
  }

  nodes_array[nodes/2].score = score_calculation( nodes/2, nodes_array);
  calculate_score_all( nodes/2, nodes_array);

  for(int index = 0; index < nodes; index++){
    nodes_array[index].add_score();
  }  

  int numerator = 0, denominator = nodes;

  for(int index = 0; index < nodes; index++){
    if(nodes_array[index].total_score >= threshold_points){
      numerator++;
    }
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
