#include <bits/stdc++.h>

using namespace std;

int abs( int a)
{
    if(a < 0)
        a = (-a);
    return a;
}

int anagram(string s){
    // Complete this function
    int ret_value = -1;
    int len = s.length(), index = 0, count[26];
    for(int i = 0; i < 26; i++)
        count[i] = 0;
    if(len%2 == 0)
    {
        for(; index < len/2; index++)
            count[s[index] - 'a']++;
        for(; index < len; index++)
            count[s[index] - 'a']--;

        int sum = 0;
        for(int i = 0; i < 26; i++)
            sum += abs(count[i]);
        ret_value = sum;
    }

    return ret_value;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = anagaram(s);
        cout << result << endl;
    }
    return 0;
}
