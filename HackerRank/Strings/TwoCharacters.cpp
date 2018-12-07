
#include <bits/stdc++.h>

using namespace std;

bool check( std::string s, char a, char b)
{
	std::string temp {};
	char even_char, odd_char;
	bool checkpoint = true;
	for(int index = 0; index < s.length(); index++)
	{
		if((s[index] == a) || (s[index] == b))
		{
			temp += s[index];
		}
	}

	if(temp[0] == a)
	{
		even_char = a;
		odd_char = b;
	}
	else
	{
		even_char = b;
		odd_char = a;
	}

	for( int index = 0; index < temp.length() && checkpoint; index++)
	{
		if(index%2)
		{
			if(temp[index] != odd_char)
				checkpoint = false;
		}
		else
		{
			if(temp[index] != even_char)
				checkpoint = false;
		}
	}
	if(temp.length() <= 1)
		checkpoint = false;
	return checkpoint;

}

int maxLen(string s)
{
    // Complete this function
    int A[26];
    for(int index = 0; index < 26; index++)
    	A[index] = 0;

    for( auto x : s)
    	A[x - 'a']++;

    int maxlen = 0;
    for( int index = 0; index < 25; index++)
    {
    	for( int inner_index = index + 1; inner_index < 26; inner_index++)
    	{
    		if((A[index] - A[inner_index] == 0) || (A[index] - A[inner_index] == 1) || (A[index] - A[inner_index] == -1))
    		{
    			if(check( s, (char)(index + 'a'), (char)(inner_index + 'a')))
    			{
    				if(maxlen < A[index] + A[inner_index])
    					maxlen = A[index] + A[inner_index];
    			}
    		}
    	}
    }

    return maxlen;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int result = maxLen(s);
    cout << result << endl;
    return 0;
}
