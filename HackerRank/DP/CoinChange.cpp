#include <bits/stdc++.h>

using namespace std;

long getWays(long n, vector < long > c){
    // Complete this function

    std::vector< long > sol(n+1);
    sol[0] = 1;

    for(int index = 0; index < c.size(); index++)
    {
        for( int inner = c[index]; inner < n + 1; inner++)
        {
            sol[inner] += sol[inner - c[index]];
        }
    }

    return sol[n];    
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);

    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    std::sort( c.begin(), c.end());
    long ways = getWays(n, c);
    std::cout << ways << "\n";
    return 0;
}
