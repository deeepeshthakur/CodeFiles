#include <bits/stdc++.h>
using namespace std;

void modified_dfs_call( int id, std::vector< bool > &dfsCheck, std::vector < std::vector < int > > &bookkeeping, long& astronauts_same_nationality){
  if(dfsCheck[id]){
    dfsCheck[id] = false;
    astronauts_same_nationality++;
    int pairs_count_curr_id = bookkeeping[id].size();
    for(int index = 0; index < pairs_count_curr_id; index++){
      modified_dfs_call(bookkeeping[id][index], dfsCheck, bookkeeping, astronauts_same_nationality);
    }
  }
}

void solve( int astronauts, int nationality_pairs){
  std::vector < std::vector < int > > bookkeeping(astronauts);
  for(int index = 0; index < nationality_pairs; index++)
  {
    int first_astaonaut = 0, second_astronaut = 0;
    std::cin >> first_astaonaut >> second_astronaut;
    bookkeeping[first_astaonaut].push_back(second_astronaut);
    bookkeeping[second_astronaut].push_back(first_astaonaut);
  }
  std::vector < bool > dfsCheck(astronauts, true);
  std::vector < long > same_nation_pairs{};

  for(int index = 0; index < astronauts; index++)
  {
    long astronauts_same_nationality = 0;
    if(dfsCheck[index]){
      modified_dfs_call( index, dfsCheck, bookkeeping, astronauts_same_nationality);
    }
    same_nation_pairs.push_back((astronauts_same_nationality*(astronauts_same_nationality - 1)/2));
  }
  long ans = ((long)astronauts)*((long)astronauts-1)/2;

  for(int index = 0; index < same_nation_pairs.size(); index++)
  {
    ans -= same_nation_pairs[index];
  }
  std::cout << ans << endl;
}

int main(){
  int astronauts = 0, nationality_pairs = 0;
  std::cin >> astronauts >> nationality_pairs;
  solve( astronauts, nationality_pairs);
  return 0;
}
