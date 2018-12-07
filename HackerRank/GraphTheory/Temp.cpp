#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct MyComparator
{
    const vector<int> & value_vector;

    MyComparator(const vector<int> & val_vec):
        value_vector(val_vec) {}

    bool operator()(int i1, int i2)
    {
      std::cout << i1 << "                    " << i2 << std::endl;
        return value_vector[i1] < value_vector[i2];
    }
};

int main(){
  int n = 10;
  // std::cin >> n;
  std::vector< int > A(n), B(n);

  for(int index = 0; index < n; index++)
  {
    std::cin >> A[index];
    B[index] = index + 1;
  }

  sort(A.begin(), A.end(), MyComparator(B));
  sort(B.begin(), B.end());
  for(int index = 0; index < n; index++){
    std::cout << A[index] << "  " << B[index] << endl;
  }


  return 0;
}

// #include <algorithm>
// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <ctime>
//
// using namespace std;
//
// struct MyComparator
// {
//     const vector<int> & value_vector;
//
//     MyComparator(const vector<int> & val_vec):
//         value_vector(val_vec) {}
//
//     bool operator()(int i1, int i2)
//     {
//         return value_vector[i1] < value_vector[i2];
//     }
// };
//
// void print(const vector<int> & v, const char * msg)
// {
//     int size = v.size();
//
//     for (int i = 0; i < size; ++i)
//         cout << v[i] << "     ";
//
//     cout << msg << endl;
// }
//
// int main()
// {
//     srand(time(0));
//
//     vector<int> A(10), B(10);
//
//     for (int i = 0; i < 10; ++i)
//     {
//         A[i] = rand() % 100;
//         B[i] = i + 1;
//     }
//
//     std::cout << std::endl;
//     for(int index = 0; index < 10; index++){
//       std::cout << A[index] << "  " << B[index] << std::endl;
//     }
//
//     sort(B.begin(), B.end(), MyComparator(A));
//     std::cout << std::endl;
//     // sort(A.begin(), A.end());
//     for(int index = 0; index < 10; index++){
//       std::cout << A[index] << "  " << B[index] << std::endl;
//     }
//
//     // cout << "\n(hit enter to quit)";
//     // cin.get();
//
//     return 0;
// }
