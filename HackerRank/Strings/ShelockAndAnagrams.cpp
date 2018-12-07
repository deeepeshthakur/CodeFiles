#include <bits/stdc++.h>

using namespace std;

bool check_anagram( std::string &s, int index1, int index2, int len)
{
    //std::cout << index1 << " " << index2 << " " << len << std::endl;
    int temp = 0;
    bool flag = true;
    int count[26];
    for( int index = 0; index < 26; index++)
        count[index] = 0;
    for(; temp < len; temp++)
    {
        count[s[index1 + temp] - 'a']++;
        count[s[index2 + temp] - 'a']--;
    }

    int index = 0;
    while(flag)
    {
        if(count[index] != 0)
            flag = false;
        index++;
        if(!(index < 26))
            break;
    }
    return flag;
}

int sherlockAndAnagrams(std::string s){
    // Complete this function
    int anagrams = 0, len = s.length();
    for( int count_len = 1; count_len <= len - 1; count_len++)
    {
        for( int prim = 0; prim <= len - count_len; prim++)
        {
            for( int sec = prim + 1; sec <= len - count_len; sec++)
            {
                if(check_anagram( s, prim, sec, count_len))
                    anagrams++;
            }
        }
    }
    return anagrams;
}

int main() {
    int q;
    std::cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        std::string s;
        std::cin >> s;
        int result = sherlockAndAnagrams(s);
        std::cout << result << endl;
    }
    return 0;
}
