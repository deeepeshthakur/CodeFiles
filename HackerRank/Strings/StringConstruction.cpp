#include <bits/stdc++.h>

using namespace std;

int stringConstruction(string s) {
    // Complete this function
    bool a[26];
    for( int index = 0; index < 26; index++)
    {
        a[index] = false;
    }

    for( auto x : s)
        a[x - 'a'] = true;

    int count = 0;
    for( int index = 0; index < 26; index++)
        if(a[index])
            count++;
    return count;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = stringConstruction(s);
        cout << result << endl;
    }
    return 0;
}
