#include <cmath>
#include <string>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>

unsigned long long modul = 1000000007;
unsigned long long A_elements[1000001];
unsigned long long Add_distance[1000001];
unsigned long long Nodes[1000001];
unsigned long long Internal_sum[1000001];
unsigned long long Sum_of_distances[1000001];

unsigned long long auxilary_function( int n)
{
	std::memset( A_elements, 0, sizeof(A_elements));
	std::memset( Internal_sum, 0, sizeof(Internal_sum));
	std::memset( Sum_of_distances, 0, sizeof(Sum_of_distances));
	std::memset( Add_distance, 0, sizeof(Add_distance));
	std::memset( Nodes, 0, sizeof(Nodes));

	A_elements[0] = 0;
	for(int index = 1; index <= n; index++)
	{
		std::cin >> A_elements[index];
	}

	Add_distance[0] = 0;
	Nodes[0] = 1;
	Internal_sum[0] = 0;
	Sum_of_distances[0] = 0;

	for(int index = 1; index <= n; index++)
	{
		Nodes[index] = (4*Nodes[index-1]) + 2;
		Nodes[index] %= modul;

		Add_distance[index] = (3*A_elements[index]) + (2*Add_distance[index-1]);
		Add_distance[index] %= modul;

		Sum_of_distances[index] = (Sum_of_distances[index-1]*4) + Add_distance[index-1]*(3*Nodes[index-1] + 2) + A_elements[index]*(8*Nodes[index-1] + 3);
		Sum_of_distances[index] %=modul;

		Internal_sum[index] = (4*Internal_sum[index-1]) + Sum_of_distances[index-1]*(12*Nodes[index-1] + 8) + A_elements[index]*(16*((Nodes[index-1]*Nodes[index-1])%modul) + 12*Nodes[index-1] + 1);
		Internal_sum[index] %= modul;
	}


	unsigned long long ans = Internal_sum[n];
	return ans;
}


using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n = 0;
    std::cin >> n;
    unsigned long long result = auxilary_function(n);
    std::cout << result << "\n";
    return 0;
}
