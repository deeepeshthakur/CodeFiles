#include <bits/stdc++.h>

using namespace std;



vector <int> quickSort(vector <int> arr) {
    // Complete this function
    std::vector < int > left{}, equal{}, right{};
    int val = arr[0];
    for( auto x : arr)
    {
        if(x < val)
            left.push_back(x);
        if(x > val)
            right.push_back(x);
        if(x == val)
            equal.push_back(x);
    }

    int count = 0;
    for( auto x : left)
        arr[count++] = x;
    for( auto x : equal)
        arr[count++] = x;
    for( auto x : right)
        arr[count++] = x;

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
