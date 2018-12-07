#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void encrypt( char ch, int k)
{
	int temp = 0;
	if((ch >= 'a') && (ch <= 'z'))
	{
		//std::cout << 1 << " ";
		temp = ch - 'a';
		ch = 'a';
		temp += k;
		temp = temp%26;
	}

	if((ch >= 'A') && (ch <= 'Z'))
	{
		//std::cout << 2 << " ";
		temp = ch - 'A';
		ch = 'A';
		temp += k;
		temp = temp%26;
	}

	std::cout << (char)(ch + temp);
}

int main(){
    int n;
    cin >> n;
    char str[101];
    for( int index = 0; index < n; index++)
    	std::cin >> str[index];
    int k;
    cin >> k;

    for( int index = 0; index < n; index++)
    {
    	encrypt( str[index], k);
    }
    std::cout << endl;

    return 0;
}
