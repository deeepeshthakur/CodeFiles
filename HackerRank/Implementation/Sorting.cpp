#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void action(std::vector < int > &a, int index)
{
    //std::cout << "n ";
    int temp = a[index-1];
    a[index-1] = a[index];
    a[index] = a[index+1];
    a[index+1] = temp;
}

int ret_index( std::vector < int > &a, int key)
{
    int index = 0;
    while(a[index] != key)
        index++;
    if(index == a.size() - 1)
    {
        action( a, index-1);
        index--;
    }
    return index;
}

void arrange( std::vector < int > &a, int key)
{
    int curr_index = ret_index( a, key);
    //std::cout << "initial = " << curr_index << " ";
    bool flag;

    if(a[key-1] == key)
        flag = false;
    else
        flag = true;

    while(flag)
    {
        action( a, curr_index);
        curr_index--;
        if(a[key-1] == key)
            flag = false;
        else
            flag = true;

    }
    //std::cout << "index = " << curr_index + 1 << " elem = " << a[curr_index+1] << " key = " << key << endl;
}

bool check( std::vector < int > &a)
{
    // for( auto x : a)
    //         std::cout << x << " ";
    //     std::cout << endl << endl;
    int n = a.size();
    for(int index = 0; index < n-2; index++)
    {
        if(index+1 != a[index])
        {
            arrange( a, index+1);
        }
        // for( auto x : a)
        //     std::cout << x << " ";
        // std::cout << endl << endl;
    }

    if((a[n-2] == n-1) && (a[n-1] == n))
        return true;

    return false;

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    std::cin >> t;
    
    for( int count = 0; count < t; count++)
    {
        int n;
        std::cin >> n;
        std::vector < int > A(n);
        
        for( int index = 0; index < n; index++)
            std::cin >> A[index];

        if(check(A))
            std::cout << "YES";
        else
            std::cout << "NO";
        std::cout << endl;
    }    
    return 0;
}
