#include <bits/stdc++.h>

using namespace std;

int absol( int a, int b)
{
    if((a - b) >= 0) return a - b;
    else return b - a;
}

int main() {
    vector< vector<int> > s(3,vector<int>(3));
    for(int s_i = 0;s_i < 3;s_i++){
       for(int s_j = 0;s_j < 3;s_j++){
          cin >> s[s_i][s_j];
       }
    }
    
    int cost{};
    cost += absol( s[1][1], 5);
    s[1][1] = 5;
       
    //  Print the minimum cost of converting 's' into a magic square
    int arr[9] = {0,0,0,0,0,0,0,0,0};
    for( int index = 0; index < 9; index++)
        arr[s[index/3][index%3] - 1]++;

    for( int index = 0; index < 9; index++)
        cout << arr[index] << " ";
    cout << endl;



        
    
    return 0;
    
}
