#include <string>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <utility>

using namespace std;

int main(){
    int n;
    cin >> n;
    int gene_size_max = 0;
    vector<string> genes(n);
    for(int genes_i = 0; genes_i < n; genes_i++){
       cin >> genes[genes_i];
       if(gene_size_max < genes[genes_i].size())
        gene_size_max = genes[genes_i].size();
    }

    vector<int> health(n);
    for(int health_i = 0; health_i < n; health_i++){
       cin >> health[health_i];
    }
    std::vector < std::vector < std::vector < std::vector < std::vector < int > > > > > arranged( 26, std::vector < std::vector < std::vector < std::vector < int > > > >( gene_size_max, std::vector < std::vector < std::vector < int > > >( 26, std::vector < std::vector < int > >(26))));

    for( int i = 0; i < n; i++)
    {
        int len = genes[i].length() - 1;
        std::string temp = genes[i];
        int ch1 = temp[0] - 'a', ch2 = 0, ch3 = 0;
        if(len > 0)
            ch2 = temp[1] - 'a';
        if(len > 1)
            ch3 = temp[2] - 'a';
        arranged[ch1][len][ch2][ch3].push_back(i);
    }
    //std::cout << gene_size_max << endl;
    long max = 0, min = LONG_MAX;
    int s, first, last, len, primary, secondary, temp_len, ch1, ch2,ch3;
    std::string d{};
    long curr_health = 0;
    std::cin >> s;
    //std::cout << s << endl;
    for(int a0 = 0; a0 < s; a0++)
    {
        std::cout << a0 << " ";
        curr_health = 0;
        std::cin >> first >> last >> d;
        len = d.length();

        //std::cout << len << endl;
        for(primary = 0; primary < len; primary++)
        {
            //std::cout << primary << " ";
            std::string temp{};
            temp_len = 0;
            ch1 = d[primary] - 'a';
            ch2 = 0;
            ch3 = 0;
            for(secondary = primary; secondary < len && (secondary - primary + 1 <= gene_size_max); secondary++)
            {
                temp += d[secondary];
                temp_len = temp.size();
                if(temp_len == 1)
                {
                    for( auto x : arranged[ch1][0][0][0])
                        if((x <= last) && (x >= first))
                        {
                            curr_health += health[x];
                        }
                }
                else
                {
                    ch2 = temp[1] - 'a';
                    if(temp_len == 2)
                    {
                        for( auto x : arranged[ch1][1][ch2][0])
                            if((x >= first) && (x <= last))
                            {
                                curr_health += health[x];
                            }
                    }
                    else
                    {
                            ch3 = temp[2] - 'a';
                            if(temp_len == 3)
                            {
                                for( auto x : arranged[ch1][2][ch2][ch3])
                                    if((x <= last) && (x >= first))
                                        curr_health += health[x];
                            }
                            else
                                {
                                    for( auto x : arranged[ch1][temp_len - 1][ch2][ch3])
                                        {
                                            if((x >= first) && (x <= last))
                                                {
                                                    bool endpoint = true;
                                                    for( int counter = 3; counter < temp_len && endpoint; counter++ )
                                                        if(temp[counter] != genes[x][counter])
                                                            endpoint = false;
                                                    if(endpoint)
                                                        curr_health += health[x];
                                                }
                                        }
                                }
                    }
                }

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
