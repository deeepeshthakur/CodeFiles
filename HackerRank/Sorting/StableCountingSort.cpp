#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    std::vector < std::vector < std::string > > arranged(100);
    for(int a0 = 0; a0 < n; a0++){
        int x;
        string s;
        cin >> x >> s;
        if(a0 < n/2)
        	s = "-";
        arranged[x].push_back(s);
    }

    for( int index = 0; index < 100; index++)
    {
    	for( auto x : arranged[index])
    		std::cout << x << " ";
    }
    std::cout << endl;
    return 0;
}
