#include <bits/stdc++.h>

using namespace std;

int dp_table[2001];

int max_return( int a, int b)
{
    int ans = a;
    if(b > ans)
        ans = b;
    return ans;
}

int unboundedKnapsack(int k, vector <int> arr) {
    // Complete this function
    std::memset(dp_table, 0, sizeof(dp_table));
    for(int i = 0; i <= k; i++)
    {
        for(int index = 0; index < arr.size(); index++)
        {
            if(arr[index] <= i)
            {
                dp_table[i] = max_return( dp_table[i], dp_table[i - arr[index]] + arr[index]);
            }
        }
    }
    return dp_table[k];
}

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        int k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        int result = unboundedKnapsack(k, arr);
        cout << result << endl;
    }
    return 0;
}
