#include <bits/stdc++.h>

using namespace std;

void partition( std::vector < int > & arr, int first, int last)
{
    if(last - first < 2)
    {
        if(last - first == 1)
        {
            if(arr[first] > arr[last])
            {
                int temp = arr[first];
                arr[first] = arr[last];
                arr[last] = temp;
            }
        }
    }
    else
    {
        bool flag = true;
        int small = first, large = last - 1;
        while(flag)
        {
            while(arr[small] <= arr[last] && (small < large))
                small++;
            while(arr[large] > arr[last] && small < large)
                large--;
            if(small < large)
            {
                int temp = arr[small];
                arr[small] = arr[large];
                arr[large] = temp;

            }

            if(small >= large)
            {
                flag = false;
                int temp = arr[last];
                arr[last] = arr[large];
                arr[large] = temp;
            }
        }
        partition( arr, first, large - 1);
        partition( arr, large + 1, last);
    }
}

vector <int> quickSort(vector <int> arr) {
    // Complete this function
    partition( arr, 0, arr.size() - 1);
    return arr;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    vector <int> result = quickSort(arr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
