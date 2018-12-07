// #include <map>
// #include <set>
// #include <list>
// #include <cmath>
// #include <ctime>
// #include <deque>
// #include <queue>
// #include <stack>
#include <string>
//#include <bitset>
#include <cstdio>
//#include <limits>
#include <vector>
//#include <climits>
//#include <cstring>
// #include <cstdlib>
// #include <fstream>
// #include <numeric>
// #include <sstream>
#include <iostream>
#include <algorithm>
//#include <unordered_map>

using namespace std;


int main(){
    int Q;
    std::cin >> Q;
    std::vector< std::string > input(Q);
    std::vector< int > Num(Q);

    for( int index = 0; index < Q; index++)
    {
    	std::cin >> Num[index];
    	std::cin >> input[index];
    }

    for(int a0 = 0; a0 < Q; a0++){
        int n = Num[a0];
        std::string b {};
        b += input[a0];        
        int A[27];
        for( int index = 0; index < 27; index++)
        	A[index] = 0;

        for( int index = 0; index < n; index++)
        {
        	if(b[index] == '_')
        		A[26]++;
        	else
        		A[b[index] - 'A']++;
        }

        if(A[26])
        {
        	for( int index = 0; index < 26; index++)
        	{
        		if(A[index] == 1)
        			{
        				std::cout << "NO" << endl;
        				index = 26;
        			}
        		else
        			if(index == 25)
        				std::cout << "YES" << endl;
        	}
        }
        else
        {
        	int index = 0;
        	bool check = true;
        	while(check && (index < n))
        	{
        		if(index == 0)
        		{
        			if(b[0] != b[1])
        				check = false;
        		}
        		else
        			if(index == n-1)
        			{
        				if(b[n-1] != b[n-2])
        					check = false;
        			}
        			else
        			{
        				if((b[index] != b[index-1]) && (b[index] != b[index+1]))
        					check = false;
        			}
        	}

        	if(check)
        		std::cout << "YES" << endl;
        	else
        		std::cout << "NO" << endl;
        }


    }
    return 0;
}
