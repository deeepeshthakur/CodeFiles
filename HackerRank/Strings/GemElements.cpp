#include <bits/stdc++.h>

using namespace std;

int gemstones(vector <string> arr)
{
    // Complete this function
    std::vector < int > a(26);

    for( auto x : arr)
    {
        std::vector < int > temp(26);
        for( auto y : x)
            temp[y - 'a'] = 1;

        for( int index = 0; index < 26; index++)
            a[index] += temp[index];
    }

    int count = 0;
    for( auto x : a)
        if(x == arr.size())
            count++;

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = gemstones(arr);
    cout << result << endl;
    return 0;
}
