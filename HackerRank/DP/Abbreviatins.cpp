#include <bits/stdc++.h>

using namespace std;
int coun = 0, previ = 0;

// std::string reduce( std::string a)
// {
//     std::string temp {};

// }

bool alp_check( char a, char b)
{
    bool ans = false;

    if(a - 'a' == b - 'A')
        ans = true;
    return ans;
}

bool check(std::string &a, std::string &b, int a_index, int b_index)
{
    coun++;
    if(coun > 10000)
        return false;

    //std::cout << a_index << " " << b_index << "\n";
    bool ans;
    if(b_index == b.length() || a_index == a.length())
        {
            if(b_index == b.length())
                {
                    ans = true;
                    for( int index = a_index; index < a.length(); index++)
                        if(a[index] >= 'A' && a[index] <= 'Z')
                        {
                            ans = false;
                        }
                }
            else
                ans = false;
        }
    else
    {
        if(a[a_index] >= 'A' && a[a_index] <= 'Z')
        {
            if(a[a_index] == b[b_index])
            {
                previ = a_index;
                ans = check( a, b, a_index + 1, b_index + 1);
            }
            else
            {
                //std::cout << a_index << " ";
                if(a[previ] >= 'a' && a[previ] <= 'z')
                {
                    if((a[previ] - 'a' == a[a_index] - 'A'))
                    {
                        previ = a_index;
                        ans = check( a, b, a_index + 1, b_index);
                    }
                    else
                    {
                        if(a[a_index] == b[0])
                            {
                                previ = a_index;
                                ans = check( a, b, a_index + 1, 1);
                            }
                        else
                            ans = check( a, b, a_index + 1, 0);
                    }
                }
                else
                {
                    if(a[a_index] == b[0])
                        {
                            previ = a_index;
                            ans = check( a, b, a_index + 1, 1);
                        }
                    else
                        ans = check( a, b, a_index + 1, 0);
                }
            }
        }
        else
        {
            if(alp_check( a[a_index], b[b_index]))
            {
                previ = a_index;
                ans = check( a, b, a_index+1, b_index+1);
            }
            else
            {
                ans = check( a, b, a_index+1, b_index);
            }
        }
    }

    return ans;
}

std::string abbreviation(std::string a, std::string b) {
    // Complete this function
    std::string ans{};
    previ = 0;
    // a = reduce(a);
    if(check( a, b, 0, 0))
        ans = "YES";
    else
        ans = "NO";
    coun = 0;
    return ans;
}

int main() {
    int q;
    std::cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        std::string a;
        std::cin >> a;
        std::string b;
        std::cin >> b;
        std::string result = abbreviation(a, b);
        std::cout << result << std::endl;
    }
    return 0;
}
