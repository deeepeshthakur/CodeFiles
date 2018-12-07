#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long dpTableFunc( int first_index, int second_index, int third_index, std::vector < std::vector < std::vector < long long > > > &Dp_Table, std::vector < int > &Heights, std::vector < int > &Colours)
{
  if(Dp_Table[first_index][second_index][third_index] == -1)
  {


  }
  return Dp_Table[first_index][second_index][third_index];
}

int func( int N, int K, std::vector < int > &Heights, std::vector < int > &Colours)
{
  std::vector < std::vector < std::vector < long long > > > Dp_Table( N, std::vector < std::vector < long long > > ( N, std::vector < long long >( 128, -1)));


}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, K;
    std::cin >> N >> K;
    std::vector < int > Heights( N, 0);
    std::vector < int > Colours( N, 0);
    for(int index = 0; index < N; index++)
    {
      std::cin >> Heights[index] >> Colours[index];
    }
    int ans = func( N, K, Heights, Colours);
    std::cout << ans << "\n";
    return 0;
}
