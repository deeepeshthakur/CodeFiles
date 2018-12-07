#include <bits/stdc++.h>

using namespace std;

bool check_palindrome( std::string s)
{
    int len = s.length();
    int limit = len/2;
    bool check = true;

    for( int index = 0; index <= limit && check; index++)
    {
        if(s[index] != s[len - 1 - index])
            check = false;
    }

    return check;
}

int palindromeIndex(string s)
{
    // Complete this function
    int len = s.length(), ret_value = -1;
    bool cont = true;
    if(!check_palindrome(s))
    {
        int limit = len/2;
        for(int index = 0; index <= limit && cont; index++)
        {
            if(s[index] != s[len - 1 - index])
            {
                bool check = true;
                if(check)
                {
                    std::string temp {};
                    for( int i = 0; i < len; i++)
                        if(i != index)
                            temp += s[i];

                    if(check_palindrome(temp))
                        {
                            check = false;
                            ret_value = index;
                            cont = false;
                        }
                }

                if(check)
                {
                    std::string temp {};
                    for( int i = 0; i < len; i++)
                        if(i != (len - 1 -index))
                            temp += s[i];

                    if(check_palindrome(temp))
                        {
                            check = false;
                            ret_value = len - 1 -index;
                            cont = false;
                        }
                }

                if(check)
                {
                    cont = false;
                }
            }
        }
    }

    return ret_value;
}   

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = palindromeIndex(s);
        cout << result << endl;
    }
    return 0;
}
