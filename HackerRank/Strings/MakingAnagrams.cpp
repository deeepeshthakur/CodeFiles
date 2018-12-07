#include <bits/stdc++.h>

using namespace std;

int abs( int a)
{
    if(a < 0)
        a = (-a);
    return a;
}

int makingAnagrams(string s1, string s2){
	// Complete this function
	int count[26];
	for(int i = 0; i < 26; i++)
        count[i] = 0;

    for(auto x : s1)
    	count[x - 'a']++;
    for(auto x : s2)
    	count[x - 'a']--;

    int sum = 0;
    for(int i = 0; i < 26; i++)
        sum += abs(count[i]);

    return sum;
}

int main() {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int result = makingAnagrams(s1, s2);
    cout << result << endl;
    return 0;
}
