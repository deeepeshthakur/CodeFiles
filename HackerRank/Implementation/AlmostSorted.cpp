#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check_sort( std::vector <int > &a)
{
	//std::cout << " sort checked " << endl;
	bool flag = true;
	for( int index = 0; (index < a.size()-1) && flag; index++)
	{
		if(a[index] > a[index+1])
			flag = false;
	}
	return flag;
}


bool check_swap( std::vector < int > &input)
{
	std::vector < int > a{input};
	bool checkpoint1 = true;
	int index = 0;

	while(checkpoint1)
	{
		if(a[index] > a[index+1])
			checkpoint1 = false;
		else
			index++;
	}

	int first_index = index;
	index++;

	index = a.size() - 1;
	checkpoint1 = true;

	while(checkpoint1)
	{
		if(a[index-1] > a[index])
		{
			checkpoint1 = false;
		}
		else
			index--;
	}


	int second_index = index;

	int temp = a[second_index];
	a[second_index] = a[first_index];
	a[first_index] = temp;

	// for( auto x : a)
	// 	std::cout << x << " ";
	// std::cout << endl;

	if(check_sort(a))
	{
		std::cout << "yes" << endl << "swap " << first_index + 1 << " " << second_index + 1 << endl;
		return true;
	}

	return false;
}

bool check_reverse( std::vector < int > &input)
{
	int size = input.size();
	std::vector < int > a{input};
	int index = 0;
	bool checkpoint = true;
	int first_index = 0, last_index = size - 1;

	while(checkpoint && (index < size))
	{
		if(a[index+1] < a[index])
			checkpoint = false;
		else
			index++;
	}

	last_index = index;
	checkpoint = true;
	index = size - 1;

	while(checkpoint && (index >= 0))
	{
		if(a[index] < a[index - 1])
			checkpoint = false;
		else
			index--;
	}

	first_index = index;

	bool checkpoint2 = true;
	index = first_index;

	while(checkpoint2 && (index > last_index))
	{
		if(a[index] > a[index - 1])
			checkpoint2 = false;
		else
			index--;
	}

	if(index == last_index)
	{
		int temp_size = first_index - last_index + 1;
		std::vector < int > b(temp_size);
		for( int count = first_index, index_count = 0; count >= last_index; count--, index_count++)
		{
			b[index_count] = a[count];
		}

		for( int count = last_index, index_count = 0; count <= first_index; count++, index_count++)
			a[count] = b[index_count];

		if(check_sort( a))
		{
			std::cout << "yes" << endl << "reverse " << last_index + 1 << " " << first_index + 1 << endl;
			return true;
		}

	}
	return false;

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    std::cin >> n;
    std::vector < int > arr(n);

    for( int index = 0; index < n; index++)
    	std::cin >> arr[index];

    if(check_sort( arr))
    	std::cout << "yes";
    else
    	if(!check_swap( arr) && !(check_reverse( arr)))
    		std::cout << "no";
    std::cout << endl;

    return 0;
}
