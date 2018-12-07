#include <bits/stdc++.h>

using namespace std;

int abs( int a, int b)
{
    if(a >= b)
        return a - b;
    return b - a;
}

bool funnyString(std::string &s)
{
    // Complete this function
    bool check = true;
    int rare = s.length() - 2, front = 1, index = 0, limit;
    if(s.length()%2)
        limit = s.length()/2 + 1;
    else
        limit = s.length()/2;

    while(check && (index <= limit))
    {
        if(abs( s[front + index], s[front - 1 + index]) != abs( s[rare - index], s[rare + 1 - index]))
            check = false;
        index++;
    }

    return check;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++)
    {
        string s;
        cin >> s;
        if(funnyString(s))
            std::cout << "Funny" << endl;
        else
            std::cout << "Not Funny" << endl;
    }
    return 0;
}
