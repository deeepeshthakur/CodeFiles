#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

bool binary_search( std::vector < int > &arr, int s, int e, int key)
{
    int m = (s + e)/2;
    if(s >= e)
    {
        if(key == arr[s] || key == arr[e] || key == arr[m])
            return true;
        else
            return false;
    }

    if(key == arr[s] || key == arr[m] || key == arr[e])
        return true;

    if(key > arr[m])
        return binary_search( arr, m+1, e - 1, key);
    if(key < arr[m])
        return binary_search( arr, s + 1, m - 1, key);
}

bool check_palindrome(std::string s)
{
    int len = s.length(), limit = len/2;
    bool check = true;
    for(int index = 0; index <= limit && check; index++)
        if(s[index] != s[len - 1 - index])
            check = false;
    return check;
}

string richieRich(string s, int n, int k){
    // Complete this function
    int changes = 0, len = s.length(), limit = len/2;
    std::string return_string {}, max_num {s};

    for(int index = 0; index < n; index++)
        max_num[index] = '9';

    if(check_palindrome(s))
    {
        if(k >= n)
            {
                return_string = max_num;
            }
            else
            {
                if(n%2)
                {
                    int pot_changes = 0;
                    for(int index = 0; index < len/2; index++)
                        if(s[index] != '9')
                            pot_changes +=2;

                    if(s[len/2] != '9');
                    pot_changes++;

                    if(pot_changes <= k)
                        return_string = max_num;
                    else
                    {
                        int changes = 0;
                        bool checkpoint = true;
                        for(int index = 0; index < len/2 && checkpoint; index++)
                            {
                                if(s[index] != '9')
                                {
                                    if(changes + 2 <= k)
                                    {
                                        changes += 2;
                                        s[index] = '9';
                                        s[len - 1 - index] = '9';
                                    }
                                    else
                                        checkpoint = false;
                                }
                            }
                        if(changes < k)
                            if(s[len/2] != '9')
                                {
                                    changes++;
                                    s[len/2] = '9';
                                }
                        return_string = s;
                    }
                }
                else
                {
                    int pot_changes = 0;
                    for( int index = 0; index < len/2; index++)
                        if(s[index] != '9')
                            pot_changes += 2;
                    if(k >= pot_changes)
                        return_string = max_num;
                    else
                    {
                        int changes = 0;
                        bool checkpoint = true;
                        for( int index = 0; index < len/2 && checkpoint; index++)
                            if(s[index] != '9')
                            {
                                if(changes + 2 <= k)
                                {
                                    s[index] = '9';
                                    s[len - 1 - index] = '9';
                                    changes += 2;
                                }
                                else
                                    checkpoint = false;
                            }

                        return_string = s;
                    }
                }
            }
    }
    else
    {
        int pot_changes = 0, smaller_nums = 0;
        for(int index = 0; index < len/2; index++)
            {
                if(s[index] != s[len - 1 - index])
                    pot_changes++;
                if(s[index] != '9')
                    smaller_nums++;
                if(s[len - 1 - index] != '9')
                    smaller_nums++;
            }

        if(len%2 && s[len/2] != '9')
            smaller_nums++;
        if(pot_changes > k)
            return_string = "-1";
        else
            if(pot_changes == k)
            {
                for(int index = 0; index < len/2; index++)
                    if(s[index] != s[len - 1 - index])
                    {
                        if(s[index] > s[len - 1 - index])
                        {
                            s[len - 1 - index] = s[index];
                        }
                        else
                        {
                            s[index] = s[len - 1 - index];
                        }
                    }
                return_string = s;
            }
            else
            {
                if(smaller_nums <= k)
                    return_string = max_num;
                else
                {   
                    std::vector < int > indices{};
                    int changes = 0;
                    for( int index = 0; index < len/2; index++)
                    {
                        if(s[index] != s[len - 1 - index])
                        {
                            if(s[index] > s[len - 1 - index])
                            {
                                s[len - 1 - index] = s[index];
                                changes++;
                                if(s[index] != '9')
                                    indices.push_back(index);                                
                            }
                            else
                            {
                                s[index] = s[len - 1 - index];
                                changes++;
                                if(s[index] != '9')
                                    indices.push_back(index);
                            }
                        }
                    }

                    bool endpoint = true;
                    if(changes >= k)
                        endpoint = false;
                    else
                        endpoint = true;

                    if(endpoint)
                    {
                        for( int index = 0; index < len/2 && endpoint; index++)
                        {
                            if(s[index] != '9' && endpoint)
                            {
                                if(binary_search( indices, 0, indices.size() - 1, index))
                                {
                                    s[index] = '9';
                                    s[len - 1 - index] = '9';
                                    changes++;
                                    if(changes >= k)
                                        endpoint = false;
                                }
                                else
                                {
                                    if(changes + 2 <= k)
                                    {
                                        changes += 2;
                                        s[index] = '9';
                                        s[len - 1 - index] = '9';
                                        if(changes >= k)
                                            endpoint = false;
                                    }
                                }
                            }
                        }
                    }

                    if(len%2 && endpoint)
                    {
                        if(s[len/2] != '9')
                        {
                            changes++;
                            s[len/2] = '9';
                        }
                    }

                    return_string = s;
                }
            }
    }
    return return_string;
}

int main() 
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;
    string result = richieRich(s, n, k);
    cout << result << endl;
    return 0;
}
