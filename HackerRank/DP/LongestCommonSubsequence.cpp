#include <bits/stdc++.h>

using namespace std;
bool dp_call[101][101];
std::vector < std::vector < std::vector < int > > > dp_table( 101, std::vector < std::vector < int > >(101));

void aux_function( int first_index, int second_index, std::vector < int > &a, std::vector < int > &b)
{
    std::vector < int > temp{};
    if(first_index > 0 && second_index > 0)
    {
        if(a[first_index] == b[second_index])
        {
            if(!dp_call[first_index-1][second_index-1])
                aux_function( first_index-1, second_index-1, a, b);
            temp = dp_table[first_index-1][second_index-1];
            temp.push_back(a[first_index]);
        }
        else
        {
            if(!dp_call[first_index][second_index-1])
                aux_function( first_index, second_index-1, a, b);
            if(!dp_call[first_index-1][second_index])
                aux_function( first_index-1, second_index, a, b);
            if(dp_table[first_index][second_index-1].size() >= dp_table[first_index-1][second_index].size())
                temp = dp_table[first_index][second_index-1];
            else
                temp = dp_table[first_index - 1][second_index];
        }
    }
    else
    {
        if(first_index == 0)
        {
            if(second_index != 0)
            {
                if(a[first_index] == b[second_index])
                    temp.push_back(a[first_index]);
                else
                {
                    if(!dp_call[first_index][second_index - 1])
                        aux_function( first_index, second_index - 1, a, b);
                    temp = dp_table[first_index][second_index - 1]; 
                }
            }
            else
            {
                if(a[first_index] == b[second_index])
                    temp.push_back(a[first_index]);
            }
        }
        else
        {
            if(first_index != 0)
            {
                if(a[first_index] == b[second_index])
                    temp.push_back(a[first_index]);
                else
                {
                    if(!dp_call[first_index-1][second_index])
                        aux_function( first_index - 1, second_index, a, b);
                    temp = dp_table[first_index-1][second_index];
                }
            }
        }
    }
    dp_table[first_index][second_index] = temp;
    dp_call[first_index][second_index] = true;    
}

vector <int> longestCommonSubsequence(vector <int> a, vector <int> b) {
    // Complete this function
    std::memset(dp_call, false, sizeof(dp_call));
    for(int x = 0; x < a.size(); x++)
    {
        for( int y = 0; y < b.size(); y++)
        {
            aux_function( x, y, a, b);
        }
    }
    return dp_table[a.size() - 1][b.size() - 1];
    
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    vector <int> result = longestCommonSubsequence(a, b);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;
    return 0;
}
