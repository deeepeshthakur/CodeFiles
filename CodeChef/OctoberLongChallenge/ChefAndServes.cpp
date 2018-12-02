#include <bits/stdc++.h>

using namespace std;

int main(){
  std::ios::sync_with_stdio(false);
  int test;
  std::cin >> test;
  while(test--){
    long long p1, p2, k;
    std::cin >> p1 >> p2 >> k;
    long long points = p1 + p2;
    long long quo = points/k, rem = points%k;
    if(quo%2 == 0){
      std::cout << "CHEF\n";
    }
    else{
      std::cout << "COOK\n";
    }
  }
  return 0;
}
