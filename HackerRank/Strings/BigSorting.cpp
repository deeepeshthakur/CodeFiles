#include <bits/stdc++.h>

using namespace std;

void sub_sort( std::vector < std::string> &arr, std::vector < int > &indices, int first, int last, int pos, int len)
{
    if(last - first == 1 || pos == len)
    {
        if(last - first == 1)
        {
            bool flag = true;
            for(int index = pos; (index < len) && flag; index++)
            {
                if(arr[indices[first]][index] < arr[indices[last]][index] && flag)
                    flag = false;
                if(arr[indices[first]][index] > arr[indices[last]][index] && flag)
                {
                    int temp = indices[first];
                    indices[first] = indices[last];
                    indices[last] = temp;
                    flag = false;
                }
            }
        }        
    }
    else
        if(first != last)
        {
            std::vector < std::vector < int > > arranged(10);
            for( int index = first; index <= last; index++)
            {
                arranged[arr[indices[index]][pos] - '0'].push_back(indices[index]);
            }

            int count = 0;
            for(int index = 0; index < 10; index++)
            {
                if(arranged[index].size() > 1)
                    sub_sort( arr, arranged[index], 0, arranged[index].size() - 1, pos + 1, len);
                for(int inner_index = 0; inner_index < arranged[index].size(); inner_index++)
                {
                    indices[count] = arranged[index][inner_index];
                    count++;
                }
            }
        }

}

void sort_len(std::vector < std::string > &arr, std::vector < int > &indices, int len, std::vector < std::string > &ans)
{
    std::vector < std::vector < int > > arranged(9);
    for( int index = 0; index < indices.size(); index++)
    {
        arranged[arr[indices[index]][0] - '1'].push_back(indices[index]);
    }
    int count = 0;
    for(int index = 0; index < 9; index++)
    {
        if(arranged[index].size() > 1)
            {
                // std::cout << index << endl;
                sub_sort( arr, arranged[index], 0, arranged[index].size() - 1, 1, len);
            }

        for(int inner_index = 0; inner_index < arranged[index].size(); inner_index++)
        {
            indices[count] = arranged[index][inner_index];
            count++;
        }
    }
    //std::cout << "HE"
    for(int index = 0; index < indices.size(); index++)
        ans.push_back(arr[indices[index]]);

}

std::vector <string> bigSorting(std::vector <string> &arr, int n) {
    // Complete this function
    std::vector < std::string > ans{};
    std::vector< std::vector < int > > arranged(n);
    //std::cout << "HERE";
    for(int index = 0; index < arr.size(); index++)
    {
        arranged[arr[index].length() - 1].push_back(index);
    }

    for(int index = 1; index <= n; index++)
    {
        // std::cout << index << " ";
        sort_len( arr, arranged[index - 1], index, ans);
    }
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<string> arr(n), ans(n);
    int max_len = 0;
    for(int arr_i = 0; arr_i < n; arr_i++)
    {
        // std::string temp {};
        std::cin >> arr[arr_i];
        if(arr[arr_i].length() > max_len)
            max_len = arr[arr_i].length();
    }

    for(int index = 0; index < n; index++)
        std::cin >> ans[index];

    //std::cout << "call";
    std::vector <string> result = bigSorting( arr, max_len);
    for(int index = 0; index < n; index++)
        {
            // if(ans[index] != result[index])
            //     std::cout << index << "                    " << ans[index] << "              " << 
            std::cout << result[index] << endl;
        }
    std::cout << endl;
    return 0;
}
