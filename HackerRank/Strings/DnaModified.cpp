#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> raw_genes(n);
    for(int genes_i = 0; genes_i < n; genes_i++){
       cin >> raw_genes[genes_i];
    }
    vector<int> raw_health(n);
    for(int health_i = 0; health_i < n; health_i++){
       cin >> raw_health[health_i];
    }
    std::vector < int > modified_index (n);
    std::vector < std::string > genes{};
    std::vector < int > health {};

    genes.push_back(raw_genes[0]);
    health.push_back(raw_health[0]);

    for(int index = 1; index < n; index++)
    {
        int curr_size = genes.size();
        bool check = true;
        for(int inner_index = 0; inner_index < curr_size && check; inner_index++)
        {
            if(genes[inner_index] == raw_genes[index])
            {
                health[inner_index] += raw_health[index];
                modified_index[index] = inner_index;
                check = false;
            }
        }

        if(check)
        {
            modified_index[index] = curr_size;
            genes.push_back(raw_genes[index]);
            health.push_back(raw_health[index]);
        }
    }

    std::cout << genes.size() << " NN " << endl;
    long max = 0, min = LONG_MAX;
    int s;
    cin >> s;
    for(int a0 = 0; a0 < s; a0++)
    {
        std::cout << a0 << " ";
        int first;
        int last;
        long curr_health = 0;
        string d;
        cin >> first >> last >> d;
        // your code goes here
        first = modified_index[first];
        last = modified_index[last];
        int len = d.length();
        for(int index = 0; index < len; index++)
        {
            for( int inner = first; inner <= last; inner++)
            {
                if(d[index] == genes[inner][0])
                    {
                        int curr_len = genes[inner].length();
                        bool check_point = true;
                        if(index + curr_len <= len)
                            {
                                for( int i = 0; i < curr_len && check_point; i++)
                                    {
                                        if(d[index + i] != genes[inner][i]);
                                        check_point = false;
                                    }
                            }
                            else
                                check_point = false;
                        if(check_point)
                            {
                                curr_health += health[inner];
                            }
                    }

            }
            
        }

        if(max < curr_health)
            max = curr_health;
        if(min > curr_health)
            min = curr_health;
        //std::cout << endl;
    }
    std::cout << endl;
    std::cout << min << " " << max << endl;
    return 0;
}
