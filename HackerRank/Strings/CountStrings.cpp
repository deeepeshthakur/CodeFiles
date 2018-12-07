#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

std::string s{};

std::vector< int > &Multi( std::vector < int > &a, std::vector < int > &b)
{
	int a_limit = 0, b_limit = 0;
	if(a.length() > s.length())
		a_limit = s.length();
	else
		a_limit = a.length();

	if(b.length() > s.length())
		b_limit = s.length();
	else
		b_limit	= b.length();

	int ans_limit = 0;
	if(a_limit * b_limit > s.length())
		ans_limit = s.length();
	else
		ans_limit = a_limit*b_limit;

	std:: vector < int > vec_ans(ans_limit);

	for()


}


std::string recurse()

int count_per( int curr)
{
	return 1;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t = 0;
    std::cin >> t;
    
    for(int index = 0; index < t; index++)
    {
    	std::cin >> s;
    	int len = 0;
    	std::cin >> len;
    	int ans = count_per(1);
    	std::cout << ans << endl;
    }  
    return 0;
}
