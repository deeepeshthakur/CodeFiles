#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print_matrix( std::vector < std::vector < int > > &matrix)
{
	int m = matrix.size();
	

	for( int x = 0; x < m; x++)
	{
		int n = matrix[x].size();
		for( int y = 0; y < n; y++)
		{
			std::cout << matrix[x][y] << " ";
		}
		std::cout << endl;
	}
}

void rotate( std::vector < std::vector < int > > &matrix, int r)
{
	std::vector < std::vector < int > > rotated_matrix{};
	int m = matrix.size(), n = matrix[0].size(), min, limit;
	if(m <= n)
		min = m ;
	else
		min = n;
	// std::cout << min << endl << endl << endl;

	limit = min/2 + min%2;

	for(int count = 0; count < limit; count++)
	{
		// std::cout << count << endl;
		std::vector < int > arr{};
		int x = count, y = count, x_counter = x, y_counter = y;
		int x_limit = m - 1 - count, y_limit = n - 1 - count;

		if((x == x_limit) || (y == y_limit))
		{
			if(x == x_limit)
			{
				while(y_counter <= y_limit)
				{
					arr.push_back(matrix[x][y_counter]);
					y_counter++;
				}
			}
			else
			{
				while(x_counter <= x_limit)
				{
					arr.push_back(matrix[x_counter][y]);
					x_counter++;
				}
			}

		}
		else
			{
				while(y_counter <= y_limit)
				{
					arr.push_back(matrix[x_counter][y_counter]);
					y_counter++;
				}
				y_counter = y_limit;
				x_counter++;

				while(x_counter <= x_limit)
				{
					arr.push_back(matrix[x_counter][y_counter]);
					x_counter++;
				}
				x_counter = x_limit;
				y_counter--;

				while(y_counter >= y)
				{
					arr.push_back(matrix[x_counter][y_counter]);
					y_counter--;
				}
				y_counter = y;
				x_counter--;

				while(x_counter > x)
				{
					arr.push_back(matrix[x_counter][y_counter]);
					x_counter--;
				}
				x_counter = x;
			}
		// for(auto x: arr)
		// 	std::cout << x << " ";
		// std::cout << endl << endl;

		rotated_matrix.push_back(arr);
	}

	// print_matrix( rotated_matrix);
	// std::cout << endl;

	for( int index = 0; index < limit; index++)
	{
		std::vector < int > temp{rotated_matrix[index]};
		for( int inner_counter = 0; inner_counter < temp.size(); inner_counter++)
		{
			temp[(r*temp.size() + inner_counter - r)%temp.size()] = rotated_matrix[index][inner_counter];
		}
		rotated_matrix[index] = temp;
	}

	// print_matrix( rotated_matrix);
	// std::cout << endl;
	m = matrix.size(), n = matrix[0].size();

	for(int count = 0; count < limit; count++)
	{
		int x = count, y = count, x_counter = x, y_counter = y;
		int x_limit = m - 1 - count, y_limit = n - 1 - count, index_counter = 0;

		if((x == x_limit) || (y == y_limit))
		{
			if(x == x_limit)
			{
				while(y_counter <= y_limit)
				{
					matrix[x][y_counter] = rotated_matrix[count][index_counter];
					index_counter++;
					y_counter++;
				}
			}
			else
			{
				while(x_counter <= x_limit)
				{
					matrix[x][y_counter] = rotated_matrix[count][index_counter];
					index_counter++;
					x_counter++;
				}
			}
		}
		else
			{
				while(y_counter <= y_limit)
				{
					matrix[x_counter][y_counter] = rotated_matrix[count][index_counter];
					index_counter++;
					y_counter++;
				}
				y_counter = y_limit;
				x_counter++;

				while(x_counter <= x_limit)
				{
					matrix[x_counter][y_counter] = rotated_matrix[count][index_counter];
					index_counter++;
					x_counter++;
				}
				x_counter = x_limit;
				y_counter--;

				while(y_counter >= y)
				{
					matrix[x_counter][y_counter] = rotated_matrix[count][index_counter];
					index_counter++;
					y_counter--;
				}
				y_counter = y;
				x_counter--;

				while(x_counter > x)
				{
					matrix[x_counter][y_counter] = rotated_matrix[count][index_counter];
					index_counter++;
					x_counter--;
				}
				x_counter = x;
			}
	}
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m, n, r;
    std::cin >> m >> n >> r;
    std::vector < std::vector < int > > matrix{};
    for( int x = 0; x < m; x++)
    {
    	std::vector < int > arr {};
    	for( int y = 0; y < n; y++)
    	{
    		int temp {};
    		std::cin >> temp;
    		arr.push_back(temp);
    	}
    	matrix.push_back(arr);
    }

    rotate( matrix, r);
    print_matrix( matrix);
    return 0;
}
