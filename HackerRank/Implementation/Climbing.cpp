#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

 int getrank(int x, int l, int r, const std::vector<int>& cumscores)
    {
        int temp = (l + r)/2;
        int curr = temp;
        if((x < cumscores[temp - 1]) && (x > cumscores[temp + 1]))
        {
            if(x == cumscores[temp]) return temp+1;
            if((x < cumscores[temp-1]) && (x > cumscores[temp])) return temp+1;
            if((x < cumscores[temp]) && (x >= cumscores[temp+1])) return temp+2;
            //if(x == cumscores[temp + 1]) curr = temp + 1;
        }
        else
        {
            if(x > cumscores[temp]) return getrank( x, l ,temp, cumscores);
            if(x < cumscores[temp]) return getrank( x, temp, r, cumscores);
        }                        
    }


int main(){
    int n;
    cin >> n;
    vector<int> scores(n);
    for(int scores_i = 0;scores_i < n;scores_i++){
       cin >> scores[scores_i];
    }
    int m;
    cin >> m;
    vector<int> alice(m);
    for(int alice_i = 0;alice_i < m;alice_i++){
       cin >> alice[alice_i];
    }
    // your code goes here
    
    std::vector<int> cumscores{}, cumcount{};
    int index = 0;
    while( index < scores.size())
    {
        int temp = scores[index];
        int count{};
        while((index < scores.size()) && (scores[index] == temp))
        {
            count++;
            index++;
        }
       cumscores.push_back(temp);
       cumcount.push_back(count);
    }  
    
    cout << endl << cumscores.size() << endl;
    for(auto x:cumscores)
        cout << x << " ";

    int prev = cumscores.size();
    cout << endl << endl;

    for( auto x:alice)
    {
        if(x >= cumscores[0]) cout << 1 << " ";
        else 
            if(x <= cumscores[cumscores.size() - 1])
            {
                if(x == cumscores[cumscores.size() - 1]) cout << cumscores.size() << " " ;
                else if(x < cumscores[cumscores.size() - 1]) cout << cumscores.size() + 1 << " " ;
            }
            else
            {
                prev = getrank( x, 0, prev, cumscores);
                cout << prev << " " ;
            }
    }  

    cout << endl;     
    
    return 0;
}