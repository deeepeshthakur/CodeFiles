#include <bits/stdc++.h>

using namespace std;

int abs( int a, int b)
{
    if(a >= b)
        return a - b;
    return b - a;
}

int theLoveLetterMystery(string s){
    // Complete this function
    int len = s.length();
    int limit = len/2, count = 0;

    for( int index = 0; index < limit; index++)
    {
        if(s[index] != s[len - 1 - index])
        {
            count += abs( s[index], s[len - 1 - index]);
        }
    }

    return count;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = theLoveLetterMystery(s);
        cout << result << endl;
    }
    return 0;
}
