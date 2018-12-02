#include <bits/stdc++.h>

using namespace std;
std::vector< long > multiplier{ 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
std::vector< bool > primes{ false, false, true, true, false, true, false, true, false, false, false, true, false, true, false, false, false, true};
std::map< long, int > states{};
std::queue< long > bfs_queue{};
std::vector< std::vector < int > > moves{ { 1, 3},
                                          { 0, 2, 4},
                                          { 1, 5},
                                          { 0, 4, 6},
                                          { 1, 3, 5, 7},
                                          { 2, 4, 8},
                                          { 3, 7},
                                          { 4, 6, 8},
                                          { 5, 7}};

long getIndex( std::vector< int >& state){
  long ans = 0;
  for(int ii = 0; ii < 9; ii++){
    ans += ((long)state[ii])*multiplier[ii];
  }
  return ans;
}

std::vector< int > getState( long index){
  std::vector < int > state(9);
  for(int iindex = 0; iindex < 9; iindex++){
    state[iindex] = index%10;
    index /= 10;
  }
  return state;
}

// int countt = 0;
void modified_BFS( long state_index){
  // countt++;
  std::vector < int > curr_state = getState( state_index);
  std::vector < int > moved(9);
  int curr_moves = states.find(state_index)->second;
  for(int index = 0; index < 9; index++){
      for( int ii = 0; ii < moves[index].size(); ii++){
        for(int cc = 0; cc < 9; cc++){
          moved[cc] = curr_state[cc];
        }
        if(primes[curr_state[index] + curr_state[moves[index][ii]]]){
          int sp = moved[index];
          moved[index] = moved[moves[index][ii]];
          moved[moves[index][ii]] = sp;
          
          long move_index = getIndex( moved);
          if(states.find(move_index) == states.end()){
            states.insert( std::pair < long, int>(move_index, curr_moves + 1));
            bfs_queue.push(move_index);
          }
        }
      }
  }
}

int main(){
  int quer = 0;
  std::vector< long > testCases{};
  std::cin >> quer;
  while(quer--){
  	std::vector< int > temp_state(9);
  	for(int index = 0; index < 9; index++){
  		std::cin >> temp_state[index];
  	}
  	long tempIndex = getIndex( temp_state);
  	testCases.push_back(tempIndex);
  }
  std::vector< int > goal_state{ 1, 2, 3, 4, 5, 6, 7, 8, 9};
  long curr_index = getIndex( goal_state);
  states.insert( std::pair < long, int >( curr_index, 0));
  bfs_queue.push( curr_index);
  while(!bfs_queue.empty()){
  	modified_BFS(bfs_queue.front());
    bfs_queue.pop();
  }

  // std::cout << states.size() << std::endl;
  for( auto x : testCases){
  	if(states.find(x) == states.end()){
  		std::cout << -1 << std::endl;
  	}
  	else{
  		std::cout << states.find(x)->second << std::endl;
  	}
  }
  return 0;
}
