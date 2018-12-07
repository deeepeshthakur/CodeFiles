#include <bits/stdc++.h>

using namespace std;

int calc[1005];

int operations(int diff_i)
{
    int oper = 0, diff = diff_i;
    if(diff != 0)
    {
        oper += diff/5;
        diff %= 5;
        oper += diff/2;
        diff %= 2;
        oper += diff;
    }
    return oper;
}


int equal(std::vector <int> &arr, int min_ele) {
    // Complete this function
    std::vector < int > oper(5);
    int mini;
    for(int index = 0; index < arr.size(); index++)
    {
        for(int inner = 0; inner < 5; inner++)
        {
            oper[inner] += calc[arr[index] - min_ele + inner];
        }
    }

    mini = oper[0];
    for(int inner = 0; inner < 5; inner++)
        if(mini > oper[inner])
            mini = oper[inner];

    return mini;
}

int main() {
    int t;
    cin >> t;
    std::vector < int > result{};
    std::vector < int > result_final(t);

    for( int x = 0; x < 1005; x++)
        {
            calc[x] = operations(x);
        }
   for(int a0 = 0; a0 < t; a0++){
        int n;
        int mini = 1000;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
           if(mini > arr[arr_i])
            mini = arr[arr_i];
        }
        result.push_back(equal( arr, mini));
    }

    for(int index = 0; index < t; index++)
        std::cin >> result_final[index];

    for( int index = 0; index < t; index++)
    {
        std::cout << result[index] << "\n";
    }

    return 0;
}
