#include <bits/stdc++.h>

using namespace std;
int largest_profits[50001];
unsigned long long stockmax(vector <int> prices) {
    // Complete this function
    memset( largest_profits, -1, (prices.size() + 1)*sizeof(int));
    int curr_max = 0;
    for(int index = prices.size() - 1; index >= 0; index--)
    {
        if(curr_max < prices[index])
            curr_max = prices[index];
        largest_profits[index + 1] = curr_max - prices[index];        
    }

    unsigned long long sum_profits = 0;
    for( int index = 1; index <= prices.size(); index++)
    {
        if(largest_profits[index] > 0)
            sum_profits += largest_profits[index];
    }
    return sum_profits;    
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> prices(n);
        for(int prices_i = 0; prices_i < n; prices_i++){
           cin >> prices[prices_i];
        }
        unsigned long long result = stockmax(prices);
        cout << result << endl;
        
    }
    return 0;
}
