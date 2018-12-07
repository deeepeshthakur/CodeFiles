#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int N;
    std::cin >> N;
    vector<int> B(N);
    for(int B_i = 0;B_i < N;B_i++){
       std::cin >> B[B_i];
    }

    int count = 0;
    for(int index = 0; index < N-1; index++)
    {
    	if(B[index]%2)
    	{
    		B[index]++;
    		B[index+1]++;
    		count += 2;
    	}
    }

    if(B[N-1]%2)
    	std::cout << "NO" << endl;
    else
    	std::cout << count << endl;
    return 0;
}
