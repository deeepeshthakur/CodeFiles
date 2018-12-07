#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    std::string s;
    std::cin >> s;
    int len = s.length();
   	int row = (int)sqrt(len);
   	int col = 0;
   	if(row*row == len)
   		col = row;
   	else
   		col = row + 1;
   	std::vector < std::string> ans;
   	for( int index = 0; index < col; index++)
   	{
   		std::string temp {};
   		for( int x = index; x < len;)
   		{
   			temp = temp + s[x];
   			x = x + col;
   		}
   		ans.push_back(temp);
   	}

   	for( auto x: ans)
   		cout << x << " ";
   	cout << endl;
    return 0;
}
