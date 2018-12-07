#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check( int r, int x)
{
	if((x < 0) || (x == r))
		return false;
	else
		return true;
}

std::vector < std::vector < bool > > blast( std::vector < std::vector < bool > > a, std::vector < std::vector < bool > > b)
{	
	//std::cout << "Blast called" << endl;
	int r = b.size();
	int c = b[0].size();

	// std::cout << "inside blast" << endl;
	// std::cout << r << " " << c << endl;

	for( int x = 0; x < r; x++)
		for( int y = 0; y < c; y++)
			if(a[x][y])
			{
				b[x][y] = false;
				if(check( r, x-1))
					b[x-1][y] = false;
				if(check( r, x+1))
					b[x+1][y] = false;
				if(check( c, y-1))
					b[x][y-1] = false;
				if(check(c, y+1))
					b[x][y+1] = false;
			}

	// std::cout << "bfinal" << endl;

 //    for( int x = 0; x < r; x++)
	// {
 //    	for( int y = 0; y < c; y++)
 //    		if(b[x][y])
 //    			std::cout << "O";
 //    		else
 //    			std::cout << ".";
 //    	std::cout << endl;
 //    }

    return b;
	// std::cout << "blast ends" << endl;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int r, c, n;
    std::cin >> r >> c >> n;
    //std::cout << r << " " << c << " " << n << endl; 
    std::vector < std::vector < bool > > grid {}, even_grid {};
    
    for( int x = 0; x < r; x++)
    {
    	std::vector < bool > temp{}, temp2 {};
    	for( int y = 0; y < c; y++)
    	{
    		char in_ch;
    		std::cin >> in_ch;
    		bool in_bool, true_bool = true;
    		if(in_ch == 'O')
    			in_bool = true;
    		else
    			in_bool = false;
    		temp.push_back(in_bool);
    		temp2.push_back(true_bool);

      	}

      	grid.push_back(temp);
      	even_grid.push_back(temp2);
      	// std::cout << "Input taken" << endl;
    }

 //    std::cout << "grid" << endl;

 //    for( int x = 0; x < r; x++)
	// {
 //    	for( int y = 0; y < c; y++)
 //    		if(grid[x][y])
 //    			std::cout << "O";
 //    		else
 //    			std::cout << ".";
 //    	std::cout << endl;
 //    }

    std::vector < std::vector < bool > > temp {}, three_grid {even_grid}, five_grid {even_grid};

    // std::cout << "check point 1" << endl;

 //    for( int x = 0; x < r; x++)
	// {
 //    	for( int y = 0; y < c; y++)
 //    		if(three_grid[x][y])
 //    			std::cout << "O";
 //    		else
 //    			std::cout << ".";
 //    	std::cout << endl;
 //    }

    three_grid = blast( grid, three_grid);
    five_grid = blast( three_grid, five_grid);

 //    std::cout << "grid" << endl;

 //    for( int x = 0; x < r; x++)
	// {
 //    	for( int y = 0; y < c; y++)
 //    		if(grid[x][y])
 //    			std::cout << "O";
 //    		else
 //    			std::cout << ".";
 //    	std::cout << endl;
 //    }

    // std::cout << "three_grid" << endl;

 //    for( int x = 0; x < r; x++)
	// {
 //    	for( int y = 0; y < c; y++)
 //    		if(three_grid[x][y])
 //    			std::cout << "O";
 //    		else
 //    			std::cout << ".";
 //    	std::cout << endl;
 //    }

    // std::cout << "five_grid" << endl;

 //    for( int x = 0; x < r; x++)
	// {
 //    	for( int y = 0; y < c; y++)
 //    		if(five_grid[x][y])
 //    			std::cout << "O";
 //    		else
 //    			std::cout << ".";
 //    	std::cout << endl;
 //    }

    // std::cout << "check point 2" << endl;

    if(n%2)
    {
    	if(n == 1)
    		temp = grid;
    	else
    		if((n-2)%4 == 1)
    			temp = three_grid;
    		else
    			if((n-2)%4 == 3)
    				temp = five_grid;
    }
    else
    	temp = even_grid;

    // std::cout << "check point 3" << endl;

    for( int x = 0; x < r; x++)
	{
    	for( int y = 0; y < c; y++)
    		if(temp[x][y])
    			std::cout << "O";
    		else
    			std::cout << ".";
    	std::cout << endl;
    }    
    return 0;
}
