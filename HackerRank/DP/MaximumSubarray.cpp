#include <bits/stdc++.h>

using namespace std;

int tab[100000];

vector <int> maxSubarray(vector <int> arr) {
    // Complete this function
    std::vector < int > ans(2);
    tab[0] = arr[0];
    int sub_max = tab[0];

    ans[1] += tab[0];

    for( int index = 1; index < arr.size(); index++)
    {
        if(tab[index-1] + arr[index] < arr[index])
            tab[index] = arr[index];
        else
            tab[index] = tab[index-1] + arr[index];
        if(sub_max < tab[index])
            sub_max = tab[index];

        int temp = ans[1] + arr[index];
        if(temp > ans[1])
            ans[1] = temp;
        if(arr[index] > ans[1])
            ans[1] = arr[index];
    }

    ans[0] = sub_max;

    return ans;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        vector <int> result = maxSubarray(arr);
        for (ssize_t i = 0; i < result.size(); i++) {
            cout << result[i] << (i != result.size() - 1 ? " " : "");
        }
        cout << endl;


    }
    return 0;
}
