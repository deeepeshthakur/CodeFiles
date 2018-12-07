#include <string>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> genes(n);
    for(int genes_i = 0; genes_i < n; genes_i++){
       cin >> genes[genes_i];
    }
    vector<int> health(n);
    for(int health_i = 0; health_i < n; health_i++){
       cin >> health[health_i];
    }
    
    int s;
    cin >> s;
    std::vector < std::vector < int > > arranged(26);

    for( int i = 0; i < n; i++)
        arranged[genes[i][0] - 'a'].push_back(i);

    long max = 0, min = LONG_MAX;
    for(int a0 = 0; a0 < s; a0++)
    {
        int first;
        int last;
        long curr_health = 0;
        string d;
        cin >> first >> last >> d;
        int len = d.length();
        for(int index = 0; index < len; index++)
        {   
            
            int curr = d[index] - 'a';
            bool endpoint = true;
            for( auto x : arranged[curr])
            {
                endpoint = true;
                int limit = genes[x].length();
                if(index + limit <= len && (x <= last) && (x >= first))
                {
                    for( int primary = 0; primary < limit && endpoint; primary++)
                    {
                        if(d[index + primary] != genes[x][primary])
                            endpoint = false;
                    }
                }
                else
                    endpoint = false;

                if(endpoint)
                    curr_health += health[x];

            }

        }

        if(max < curr_health)
            max = curr_health;
        if(min > curr_health)
            min = curr_health;
    }

    std::cout << min << " " << max << endl;
    return 0;
}
