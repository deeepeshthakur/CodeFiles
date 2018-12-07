#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::string str{};
    getline( cin, str);
    std::vector < int > a(26);
    for( int index = 0; index < str.length(); index++)
    {
    	if((str[index] >= 'a') && (str[index] <= 'z'))
    		a[str[index] - 'a']++;
    	if((str[index] >= 'A') && (str[index] <= 'Z'))
    		a[str[index] - 'A']++;
    }
    bool check = true;
    for( auto x : a)
    	if(x == 0)
    		check = false;

    if(check)
    	std::cout << "pangram" << endl;
    else
    	std::cout << "not pangram" << endl;
    return 0;
}
