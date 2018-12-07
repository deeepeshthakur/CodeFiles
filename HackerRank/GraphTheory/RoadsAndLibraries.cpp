#include <bits/stdc++.h>
using namespace std;

void modified_dfs_call( int city, std::vector<bool> &dfsCheck, std::vector < std::vector <int> > &cityRoads, long& temp_ans){
  temp_ans++;
  dfsCheck[city] = true;
  int roads_from_curr_city = cityRoads[city].size();
  for(int index = 0; index < roads_from_curr_city; index++){
    if(dfsCheck[cityRoads[city][index]] == false){
      modified_dfs_call( cityRoads[city][index], dfsCheck, cityRoads, temp_ans);
    }
  }
}

void solverFuntion( int cities, int roads, long repairRoad, long repairLibrary){
  std::vector< std::vector < int > > cityRoads(cities);
  for(int index = 0; index < roads; index++){
    int cityOne = 0, cityTwo = 0;
    std::cin >> cityOne >> cityTwo;
    cityRoads[cityOne - 1].push_back(cityTwo - 1);
    cityRoads[cityTwo - 1].push_back(cityOne - 1);
  }
  std::vector <bool> dfsCheck( cities, false);
  long ans = 0;
  for(int index = 0; index < cities; index++)
  {
    long temp_ans = 0;
    if(!dfsCheck[index])
    {
      temp_ans = 0;
      modified_dfs_call( index, dfsCheck, cityRoads, temp_ans);
      ans += (repairRoad*(temp_ans-1));
      ans += repairLibrary;
    }
  }
  std::cout << ans << endl;
}

void solve(){
  int cities = 0, roads = 0;
  long repairRoad = 0, repairLibrary = 0;
  std::cin >> cities >> roads >> repairLibrary >> repairRoad;
  if(repairRoad >= repairLibrary)
  {
    int ignore = 0;
    for(int index = 0; index < 2*roads; index++)
      std::cin >> ignore;
    std::cout << (repairLibrary*((long)cities)) << std::endl;
  }
  else
  {
    solverFuntion( cities, roads, repairRoad, repairLibrary);
  }
}

int main(){
  int queries;
  std::cin >> queries;
  while(queries-- > 0){
    solve();
  }
  return 0;
}
