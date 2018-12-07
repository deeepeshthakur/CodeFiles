#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int abs( int a, int b)
{
	if( a >= b)
		return a - b;
	else
		return b - a;
}

bool range_check( int r, int x)
{
	if((x < 0) || (x == r))
		return false;
	else
		return true;
}

bool check_valid( std::vector < int > a, std::vector < int > b)
{
	if(a[1] == b[1])
	{
		if(abs( a[2], b[2]) > (a[0] + b[0] - 2))
			return true;
		else
			return false;
	}

	if(a[2] == b[2])
	{
		if(abs( a[1], b[1]) > (a[0] + b[0] - 2))
			return true;
		else
			return false;
	} 

	if((a[1] != b[1]) && (a[2] != b[2]))
	{
		int min, max;
		if(a[0] <= b[0])
			{
				min = a[0] ;
				max = b[0];
			}
		else
		{
			min = b[0];
			max = a[0];
		}

		if((abs( a[1], b[1]) >= max) || ( abs( a[2], b[2]) >= max))
			return true;
		else
		{
			if((abs( a[1], b[1]) >= min) && ( abs( a[2], b[2]) >= min))
			{
				return true;
			}
			else
				return false;
		}

	}
}

std::vector < std::vector < int > > sorting( std::vector < std::vector < int > > a, int max)
{
	std::vector < std::vector < int > > temp {};
	for( int count = max; count >= 1; count--)
	{
		for( int len = 0; len < a.size(); len++)
			if(count == a[len][0])
			{
				temp.push_back(a[len]);
			}
	}

	return temp;
}


int area_max( std::vector < std::string > a, int x, int y)
{
	int fac = -1;
	bool flag = true;
	int r = a.size();
	int c = a[0].size();

	while(flag)
	{
		fac++;
		if(range_check( r, x - fac))
		{
			if(a[x - fac][y] == 'B')
				flag = false;
		}
		else
			flag = false;

		if(range_check( r, x + fac))
		{
			if(a[x + fac][y] == 'B')
				flag = false;
		}
		else
			flag = false;

		if(range_check( c, y - fac))
		{
			if(a[x][y - fac] == 'B')
				flag = false;
		}
		else 
			flag = false;

		if(range_check( c, y + fac))
		{
			if(a[x][y + fac] == 'B')
				flag = false;	
		}
		else
			flag = false;

	}
	int area = 4*fac - 3;
	return area;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int m {}, n {};
    std::cin >> m >> n;
    std::vector < std::string > grid {};
    for( int x = 0; x < m; x++)
    {
    	std::string temp {};
    	std::cin >> temp;
    	grid.push_back(temp);
    } 

    std::vector < int > ar{ 0, 0};
    int max_len = 0;
    
    std::vector < std::vector < int > > arr {}, sorted {};
    for( int x = 0; x < m; x++)
    {
    	for( int y = 0; y < n; y++)
    	{
            if(grid[x][y] == 'G')
    		{
    			int max = 0;
    			max = area_max( grid, x, y);
    			if(max >= ar[1])
    			{
    				ar[0] = ar[1];
    				ar[1] = max;
    			}
                int fac = (max - 1)/4;
                fac++;
                if(fac > max_len)
                	max_len = fac;

                for( int all_poss = fac; all_poss >= 1; all_poss--)
                {
                	std::vector < int > temp(3);
                	temp[0] = all_poss;
                	temp[1] = x;
                	temp[2] = y;
                	arr.push_back(temp);
                }
            }
    	}
    }

    sorted = sorting( arr, max_len);
    int product_max = 0;

    int len = sorted.size();

    for( int index = 0; index < len; index++)
    {
    	int product = 0;
    	bool flag = true;

    	int inner_index = index + 1;
    	while(flag && (inner_index < len))
    	{
    		if(check_valid( sorted[index], sorted[inner_index]))
    		{
    			product = (4*sorted[index][0] -3)*(4*sorted[inner_index][0] -3);
    			if(product > product_max)
    				product_max = product;
    			flag = false;
    		}
    		inner_index++;
    	}
    }
    std::cout << product_max << endl;
    return 0;
}
