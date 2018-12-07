#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    std::cin >> n;
    std::vector< std::string> grid(n);
    for(int grid_i = 0; grid_i < n; grid_i++){
       std::cin >> grid[grid_i];
    }

    for( int x = 1; x < n - 1; x++)
    	for( int y = 1; y < n - 1; y++)
    	{
    		if((grid[x-1][y] != 'X') && (grid[x][y-1] < grid[x][y]) && (grid[x-1][y] < grid[x][y]) && (grid[x][y+1] < grid[x][y]) && (grid[x+1][y] < grid[x][y]))
    		{
    			grid[x][y] = 'X';
    			y++;
    		}
    	}

    for( int x = 0; x < n; x++)
    	{
    	    for( int y = 0; y < n; y++)
    	    	{
    	    		cout << grid[x][y];
    	    	}
    	    cout << endl;
    	}	

    return 0;
}
