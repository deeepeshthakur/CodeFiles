#include <bits/stdc++.h>

using namespace std;

bool isValid(string s){
    // Complete this function
    int len = s.length(), min = len, count[26], max = 0, zero_freq = 0;
    for(int index = 0; index < 26; index++)
    	count[index] = 0;

    for(int index = 0; index < len; index++)
    	count[s[index] - 'a']++;

    for(int index = 0; index < 26; index++)
    	{
    		if(count[index] < min && count[index] != 0)
    			min = count[index];
    		if(count[index] > max)
    			max = count[index];
    		if(!count[index])
    			zero_freq++;
    	}

    int sum = 0;

    for(int index = 0; index < 26; index++)
    	if(count[index])
    		sum += (count[index] - min);

    //std::cout << min << " " << max << " " << sum << endl; ;

    if(sum == 0 || sum == 1)
    	return true;
    if(min == 1)
    {
    	if(sum == (26 - 1 - zero_freq)*(max - min))
    		return true;
    }

    return false;
}

int main() {
    string s;
    cin >> s;
    bool result = isValid(s);
    if(result)
    	std::cout << "YES" << endl;
    else
    	std::cout << "NO" << endl;
    return 0;
}
