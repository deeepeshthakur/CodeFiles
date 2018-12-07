#include <bits/stdc++.h>

using namespace std;

bool check_further( int first, int second, std::string &a, std::string &b, int n)
{
    if(n == 0)
        return true;
    if(a[first] < b[second])
        return true;
    else
        if(a[first] > b[second])
            return false;
    bool temp;
    if(a[first] == b[second])
    {
        if(first + 1 < a.length() && second + 1 < b.length())
        {
            temp = check_further( first + 1, second + 1, a, b, n - 1);
        }
        else
            temp = true;
    }

    return temp;
}


std::string morganAndString(std::string a, std::string b) {
    // Complete this function
    std::string temp {};
    int first = 0, second = 0;
    int limit = a.length() + b.length();
    bool flag = true;

    for( int index = 0; index < limit && flag; index++)
    {
        if( first < a.length() && second < b.length())
        {
            if(a[first] < b[second])
            {
                temp += a[first];
                first++;
            }
            else
                if(a[first] > b[second])
                    {
                        temp += b[second];
                        second++;
                    }
                    else
                        if(a[first] == b[second])
                        {
                            if(check_further( first + 1, second + 1, a, b, 10))
                                {
                                    temp += a[first];
                                    first++;
                                }
                                else
                                {
                                    temp += b[second];
                                    second++;
                                }

                        }
        }
        else
        {
            if(first >= a.length())
            {
                for( int i = second; i < b.length(); i++)
                    temp += b[i];
                flag = false;
            }
            else
            {
                for( int i = first; i < a.length(); i++)
                    temp += a[i];
                flag = false;
            }
        }
    }

    return temp;

}

int main() {
    int t;
    std::cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        std::string a;
        std::cin >> a;
        std::string b;
        std::cin >> b;
        std::string result = morganAndString(a, b);
        std::cout << result << endl;
    }
    return 0;
}
