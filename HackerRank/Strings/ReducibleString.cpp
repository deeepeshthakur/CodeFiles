#include <bits/stdc++.h>

using namespace std;

string super_reduced_string(string s){
    // Complete this function
    bool checkpoint = true;
    while(checkpoint)
    {
    	//std::cout << s << endl;
    	checkpoint = false;
    	std::string temp{};
    	int len = s.length();
    	for( int index = 0; index < len; index++)
    	{
    		if((s[index] == s[index+1]) && (index < len - 1))
    		{
    			checkpoint = true;
    			index++;
    		}
    		else
    		{
    			temp += s[index];
    		}
    	}
    	s = temp;
    }

    if(s.size() == 0)
    	s = "Empty String";
    return s;
}

int main() {
    string s;
    cin >> s;
    string result = super_reduced_string(s);
    cout << result << endl;
    return 0;
}
