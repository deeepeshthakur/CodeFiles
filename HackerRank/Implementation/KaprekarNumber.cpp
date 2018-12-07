#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int digit_check( long a)
{
	int digit = 0;
	long temp = a;
	while(temp)
	{	
		//std::cout << temp << " ";
		temp = temp/10;
		digit++;
	}

	return digit;
}

bool check_kaprekar( long a)
{
	int nu_dig = digit_check( a);
	long sq = a*a;
	long r {}, l {};
	long deno = pow( 10, nu_dig);

	r = sq%(deno);
	l = sq/(deno);
	if(r + l == a)
		return true;
	else
		return false;	
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long p, q;
    std::cin >> p >> q;
    bool flag = false;
    //std::cout << p << " " << q << endl;
    for( long index = p; index <= q; index++)
    {
    	if(check_kaprekar( index))
    		{
    			flag = true;
    			std::cout << index << " ";
    		}
    }

    if(!flag)
    	std::cout << "INVALID RANGE";

    std::cout << endl;
    return 0;
}
