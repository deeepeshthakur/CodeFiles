#include <bits/stdc++.h>

using namespace std;

vector <int> countingSort(vector <int> arr) {
    // Complete this function
    std::vector < int > counted(100);
    for( auto x : arr)
        counted[x]++;
    int count = 0;
    for(int index = 0; index < 100; index++)
    {
        for(int inner = 0; inner < counted[index]; inner++)
        {
            arr[count++] = index;
        }
    }

    return arr;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    vector <int> result = countingSort(arr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
