#include <bits/stdc++.h>

using namespace std;

long long Max( long long a, long long b)
{
  if(a >= b)
    return a;
  return b;
}
long long Min( long long a, long long b)
{
  if(a <= b)
    return a;
  return b;
}

long long func( int N, long long C, std::vector <long long> &A, std::vector <long long> &B)
{
  int ans = 0;
  bool flag = true;
  int start;
  for(int index = 0; index < N && flag; index++)
  {
    start = index;
    long long fuel = 0;
    bool cont = true;
    while(cont)
    {
      fuel = Min( C, fuel + A[index]);
      if(fuel >= B[index])
      {
        fuel -= B[index];
        int next = (index+1)%N;
        if(next == start)
        {
          cont = false;
          flag = false;
        }
        else
        {
          index = next;
        }
      }
      else
      {
        index++;
        cont = false;
      }
    }
  }

  if(flag == true)
    return 0;
  else
  {
    std::vector< long long > need(N);
    need[start] = 0;
    for(int index = start + N - 1; index > start; index--)
    {
      int curr_index = index%N;
      //std::cout << curr_index << " ";
      need[curr_index] = Max( 0, need[(curr_index + 1)%N] + B[curr_index] - Min( C, A[curr_index]));
    }
  
    for(int index = 0; index < N; index++)
    {
      if(need[index] == 0)
        ans++;
    }
  }

  return ans;
}

int main()
{
  int N;
  long long C;
  std::cin >> N >> C;
  std::vector < long long > A(N), B(N);
  for(int index = 0; index < N; index++)
  {
    std::cin >> A[index];
  }

  for(int index = 0; index < N; index++)
  {
    std::cin >> B[index];
  }

  long long ans = func( N, C, A, B);
  std::cout << ans << "\n";
  return 0;
}
