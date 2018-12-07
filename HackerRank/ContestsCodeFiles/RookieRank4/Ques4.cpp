#include <bits/stdc++.h>

using namespace std;

unsigned long long Dp_table[31][1000000];

unsigned long long winningHands(unsigned long long m, unsigned long long y, vector <unsigned long long> a) {
    // Complete this function
    unsigned long long ans = 0;
    std::memset( Dp_table, 0, sizeof(Dp_table));
    for(int index = 0; index < a.size(); index++)
    {
        for(int x = 0; x < 1000000; x++)
        {
            if(Dp_table[index][x] != 0)
            {
                Dp_table[index + 1][x] += Dp_table[index][x]; 
                Dp_table[index + 1][(a[index]*x)%m] += Dp_table[index][x];
            }
        }
        Dp_table[index+1][a[index]%m]++;
    }
    ans = Dp_table[a.size()][y];

    return ans;
}

int main() {
    unsigned long long n;
    unsigned long long m;
    unsigned long long x;
    cin >> n >> m >> x;
    vector<unsigned long long> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    unsigned long long result = winningHands(m, x, a);
    cout << result << endl;
    return 0;
}
