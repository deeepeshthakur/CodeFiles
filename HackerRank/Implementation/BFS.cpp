#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void BFS( int s, int nodes, std::vector< std::vector<int> > &edges, std::vector<bool> &visited, std::vector<int> &prev)
{
	int que[1000];
	visited[s] = true;
	for(int trans = 0; trans < 1000; trans++) que[trans] = 0;
	int first = 0, last =0;
	que[last++] = s;
	while(first <= last)
	{
		int curr = que[first];
		first++;
		for( int index = 0; index < nodes; index++)
		{
			if((curr != index) && (visited[index] == false))
			{
				if((index < nodes) && (edges[curr][index] == 1) && ( visited[index] == false))
				{
					visited[index] = true;
					prev[index] = curr;
					que[last++] = index;
				}
			}
		}
	}
}

int main()
{
 std::cout << "Enter Number of nodes " ;
 int nodes{};
 std::cin >> nodes;
 std::vector< std::vector<int> > edges;
 cout << "Enter the edges ";

 for(int x = 0; x < nodes; x++)
 {
 	std::vector<int> pernode{};
 	if(x != nodes-1) std::cout << std::endl << "For node " << x+1 << " ";
 	for(int y = 0; y <= x; y++) pernode.push_back(0);
 	for(int y = x+1; y < nodes; y++)
 	{
 		int temp;
 		std::cin >> temp;
 		pernode.push_back(temp);
 	}
 	edges.push_back(pernode);
 }

 for(int x = 0; x < nodes; x++)
 	for(int y = 0; y <= x; y++)
 	{
 		if(x == y) {edges[x][y] = 1;}
 		else {
 			edges[x][y] = edges[y][x];
 		}
 	}

 std::vector<bool> visited(nodes);
 for(int index = 0; index < nodes; index++)	visited[index] = false;

 std::vector<int> prev(nodes);
 for(int index = 0; index < nodes; index++)	prev[index] = -5;

 int sour, dest;
 std::cout << "Enter source ";
 std::cin >> sour;
 std::cout << std::endl << "Enter destination ";
 std::cin >> dest;

 if(sour == dest)	cout << "The Entered Source and Destination are same.";

 if(sour != dest)
 {
	--sour;
	--dest;
	BFS( sour, nodes, edges, visited, prev);
	int index = dest;
	int path[100];
	for(int x = 0; x < 100; x++) path[x] = -2;
	int pathindex = 0;
	if(visited[dest]){
		while((prev[index] != sour) && (prev[index] != -5))
		{
			path[pathindex] = index;
			pathindex++;
			index = prev[index];
		}
		if((prev[index] == sour)) {
			path[pathindex] = index;
			pathindex++;
			path[pathindex] = sour;
		}

		std::cout << std::endl << "Shortest Path is : Source=";
		if(pathindex > 0){
			for( int xx = pathindex; xx >= 0; xx--)
			{
				std::cout << "Node" << path[xx] + 1;
				if(xx != 0) std::cout << " -> ";
			}
			std::cout << "=Destination"<< std::endl;
		}
		else
		{
			std::cout << "Node" << dest + 1 << " is not connected to " << "Node" << sour + 1 << std::endl;
		}
	}
	else
	{
		std::cout << "Node" << dest + 1 << " is not connected to " << "Node" << sour + 1 << std::endl;
	}
 }

 return 0;
}