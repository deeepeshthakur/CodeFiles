#include <string>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;


int main(){
    string s;
    cin >> s;
    char previous = s[0];
    int curr_weight = 0;
    std::vector < int > weights(26);
    for( int index = 0; index <= s.length(); index++)
    {
        if((s[index] == previous) && (index < s.length()))
        {
            curr_weight++;
        }
        else
        {
            curr_weight = curr_weight*(previous - 'a' + 1);
            if(weights[previous - 'a'] < curr_weight)
                weights[previous - 'a'] = curr_weight;
            previous = s[index];
            curr_weight = 1;
        }
    }

    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        int x;
        cin >> x;
        bool check = false;
        // your code goes here
        for(int index = 0; index < 26; index++)
        {
            if(x <= weights[index])
                if(!(x%(index+1)))
                    check = true;
        }

        if(check)
            std::cout << "Yes" << endl;
        else
            std::cout << "No" << endl;
    }
    return 0;
}
