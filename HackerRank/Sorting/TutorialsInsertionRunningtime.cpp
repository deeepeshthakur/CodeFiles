#include <bits/stdc++.h>

using namespace std;

int runningTime(vector <int> arr) {
    // Complete this function
    int count = 0;
    for(int x = 1; x < arr.size(); x++)
    {
        int value = arr[x];
        bool flag = true;
        for( int y = x - 1; y >= 0 && flag; y--)
        {
            if(value < arr[y])
                {
                    arr[y + 1] = arr[y];
                    arr[y] = value;
                    count++;
                }
        }
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = runningTime(arr);
    cout << result << endl;
    return 0;
}
