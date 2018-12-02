#include <bits/stdc++.h>

using namespace std;

int main(){
  int test;
  std::cin >> test;
  std::vector < std::vector < long long > > timeVsPopulation( 3, std::vector < long long >( 1601, 0));
  timeVsPopulation[0][1] = 1;
  for(int index = 0; index < 1601; index++){
    if(index > 15)
      timeVsPopulation[0][index] = timeVsPopulation[2][index - 16]*2;
    if(index > 1)
      timeVsPopulation[1][index] = timeVsPopulation[0][index - 2];
    if(index > 7)
      timeVsPopulation[2][index] = timeVsPopulation[1][index - 8];
  }

  for(int index = 1600; index >= 0; index--){
    for(int x = std::max( 0, index - 1); x < index; x++){
      timeVsPopulation[0][index] += timeVsPopulation[0][x];
    }

    for(int x = std::max( 0, index - 7); x < index; x++){
      timeVsPopulation[1][index] += timeVsPopulation[1][x];
    }

    for(int x = std::max( 0, index - 15); x < index; x++){
      timeVsPopulation[2][index] += timeVsPopulation[2][x];
    }
  }
  int t = 0;
  while(test--){
    std::cin >> t;
    std::cout << timeVsPopulation[0][t] << " " << timeVsPopulation[1][t] << " " << timeVsPopulation[2][t] << "\n";
  }

  return 0;
}
