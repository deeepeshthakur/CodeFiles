#include <bits/stdc++.h>

using namespace std;

string gameOfThrones(string s){
    // Complete this function
    int count[26];

    for( int index = 0; index < 26; index++)
    	count[index] = 0;

    for(auto x : s)
    	count[x - 'a']++;
    int sum = 0;
    for(int index = 0; index < 26; index++)
    	sum += count[index]%2;

    std::string temp{};

    if(sum == s.length()%2)
    	temp = "YES";
    else
    	temp = "NO";

    retrun temp; 
}

int main() {
    string s;
    cin >> s;
    string result = gameOfThrones(s);
    cout << result << endl;
    return 0;
}
