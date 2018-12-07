#include <bits/stdc++.h>

using namespace std;

std::vector < long > tab{};

long maxi( long a, long b)
{
    long ans = 0;
    if(a >= b)
        ans = a;
    else
        ans = b;
    return ans;
}

long cand_calc( std::vector < int > &arr, int index)
{
    //std::cout << "called  " << index << "  ";
    long ans = 0;
    if(tab[index] == -1)
    {
        //std::cout << "calc\n";
        if(index == 0)
        {
            if(arr[index] > arr[index + 1])
            {
                ans = cand_calc( arr, index + 1) + 1;
                tab[index] = ans;
            }
            else
            {
                ans = 1;
                tab[index] = ans;
            }
        }
        else
            if(index == arr.size() - 1)
            {
                if(arr[index] > arr[index - 1])
                {
                    ans = cand_calc( arr, index - 1) + 1;
                    tab[index] = ans;
                }
                else
                {
                    ans = 1;
                    tab[index] = ans;
                }
            }
            else
            {
                int max, min, index_max, index_min;
                if(arr[index-1] >= arr[index+1])
                {
                    index_min = index + 1;
                    index_max = index - 1;
                    max = arr[index-1];
                    min = arr[index+1];
                }
                else
                {
                    index_min = index - 1;
                    index_max = index + 1;
                    max = arr[index+1];
                    min = arr[index-1];
                }

                if(arr[index] > max)
                {
                    ans = maxi( cand_calc( arr, index_max), cand_calc( arr, index_min)) + 1;
                    tab[index] = ans;
                }
                else
                    if(arr[index] <= min)
                    {
                        ans = 1;
                        tab[index] = ans;
                    }
                    else
                        if(arr[index] <= max && arr[index] > min)
                        {
                            ans = cand_calc( arr, index_min) + 1;
                            tab[index] = ans;
                        }
                
            }
    }
    else
        {
            //std::cout << "tab\n";
            ans = tab[index];
        }
    return ans;
}

long candies(int n, vector <int> arr) {
    // Complete this function
    long sum = 0;
    for(int index = 0; index < n; index++)
        sum += cand_calc( arr, index);

    // for( auto x : arr)
    //     std::cout << x << " ";
    // std:cout << "\n";

    // for( auto x: tab)
    //     std::cout << x << " ";
    // std::cout << "\n";

    return sum;    
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
   for( int index = 0; index < n; index++)
        tab.push_back(-1);

    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    long result = candies(n, arr);
    cout << result << endl;
    return 0;
}
