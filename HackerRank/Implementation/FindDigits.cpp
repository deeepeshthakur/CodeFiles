#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool divisible( int a, int b)
{
	if(!b)
	{
		return false;
	}
	else
	{
		if(a%b)
			return false;
		else 
			return true;
	}
}

int find_digit( int n)
{
	int digits[10];
	int temp = n;
	for( int index = 0; index < 10; index++)
		digits[index] = 0;

	for( int index = 0; index < 10; index++)
	{
		digits[index] = temp%10;
		temp = (temp - temp%10)/10;
	}

	int count = 0;
	for( int index = 0; index < 10; index++)
	{
		if( divisible( n, digits[index]))
		{
			count++;
		}
	}

	return count;

}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;

        cout << find_digit(n) << endl;
    }
    return 0;
}
