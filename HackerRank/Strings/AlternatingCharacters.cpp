#include <bits/stdc++.h>

using namespace std;

int alternatingCharacters(string s){
    // Complete this function
    char d[2];

    if(s[0] == 'A')
    {
        d[0] = 'A';
        d[1] = 'B';
    }
    else
    {
        d[0] = 'B';
        d[1] = 'A';
    }


    int count = 0, index = 0;
    for( auto x : s)
    {
        if(d[index%2] == x)
        {
            index++;
        }
        else
            count++;
    }

    return count;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = alternatingCharacters(s);
        cout << result << endl;
    }
    return 0;
}
