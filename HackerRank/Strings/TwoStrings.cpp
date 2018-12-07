#include <bits/stdc++.h>

using namespace std;

bool twoStrings(string s1, string s2){
    // Complete this function
    bool a[26], check = true;
    for( int index = 0; index < 26; index++)
    {
        a[index] = false;
    }

    for( auto x : s1)
        a[x - 'a'] = true;

    for(int index = 0; index < s2.length() && check; index++)
    {
        if(a[s2[index] - 'a'])
            check = false;
    }

    return (!check);

}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        bool result = twoStrings(s1, s2);
        if(result)
            std::cout << "YES" << endl;
        else
            std::cout << "NO" << endl;
    }
    return 0;
}
