#include <bits/stdc++.h>

using namespace std;

int binary_search( std::vector< int > arr, int s, int e, int key)
{
    int m = (s+e)/2;
    cout<< arr[m] << " ";
    if( arr[m] == key) return m;

    if( m+1 > e)
    {
        if( arr[m] < key) return m;
    }
    else
    {
        if((arr[m] < key) && (key < arr[m+1])) return m;
    }

    if( m-1 < 0)
    {
        if( arr[m] > key ) return 0;
    }
    else
        {
            if((arr[m-1] < key) && ( key < arr[m])) return m-1;
        }


    if(arr[m] > key)
        e = m-1;
    if(arr[m] < key)
        s = m+1;

    return binary_search( arr, s, e, key);
}

int getMoneySpent(vector < int > keyboards, vector < int > drives, int s){
    // Complete this function
    std::sort( keyboards.begin(), keyboards.end());
    std::sort( drives.begin(), drives.end());

    cout << " Sorted" << endl;

    cout << endl;
    for( auto x: keyboards)
        cout << x << " ";
    cout << endl;

    for( auto x: drives)
        cout << x << " ";
    cout << endl;   

    if(keyboards[0] + drives[0] > s)
        return -1;

    int n = keyboards.size();
    int m = drives.size();

    int key_price = s - drives[0];
    int dri_price = s - keyboards[0];

    int key_ind = n - 1, dri_ind = m - 1;

    for( int index = 0; index < n; index++)
    {
        if(keyboards[index] > key_price)
        {
            key_ind = index-1;
            index = n;
        }
    }

    for( int index = 0; index < m; index++)
    {
        if(drives[index] > dri_price)
        {
            dri_ind = index - 1;
            index = m;
        }
    }

    cout << "key_ind = " << key_ind << " " << "price = "<< keyboards[key_ind] << endl;
    cout << "dri_ind = " << dri_ind << " " << "price = "<< drives[dri_ind] << endl;
    int max_sum = keyboards[0] + drives[0];

    for( int index = key_ind; index >= 0; index--)
    {
        int sum {};
        cout << keyboards[index] << "----";
        sum = keyboards[index] + drives[binary_search( drives, 0, dri_ind, s - keyboards[index])];
        if( sum > max_sum)
            max_sum = sum;
        cout << "    ::" << max_sum << "  " << sum << endl;
    }

    // max_sum = drives[binary_search( drives, 0, drives.size(), 23)];
    // cout << endl;
    return max_sum;
}

int main() {
    int s;
    int n;
    int m;
    cin >> s >> n >> m;
    vector<int> keyboards(n);
    for(int keyboards_i = 0; keyboards_i < n; keyboards_i++){
       cin >> keyboards[keyboards_i];
    }
    vector<int> drives(m);
    for(int drives_i = 0; drives_i < m; drives_i++){
       cin >> drives[drives_i];
    }

    cout << "   Done   " << endl;
    //  The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
    int moneySpent = getMoneySpent(keyboards, drives, s);
    cout << moneySpent << endl;
    return 0;
}
// answer is 9846