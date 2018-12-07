#include <bits/stdc++.h>

using namespace std;
long long MOD = 1000000007;
std::vector < bool > isPrime(8192, true);

void fillPrimes(){
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 0; i*i < 8192; i++){
        if(isPrime[i]){
            for(int x = i; x*i < 8192; x++){
                isPrime[x*i] = false;
            }
        }
    }
}

void f(){
    int n;
    std::cin >> n;
    std::vector < int > counterArray(1001, 0ll);
    while(n--){
        int t;
        std::cin >> t;
        counterArray[t - 3500]++;
    }

    std::vector < std::vector < long long > > dpTable(2, std::vector < long long >( 8192, 0ll));
    dpTable[0][0] = 1;
    for(int x = 0; x < 1001; x++){
        int num = x + 3500;
        long long b = counterArray[x]/2 + counterArray[x]%2, a = b - counterArray[x]%2;
        for(int y = 0; y < 8192; y++){
            dpTable[1][y] = (dpTable[1][y] + dpTable[0][y]*(a + 1))%MOD;
            dpTable[1][y^num] = (dpTable[1][y^num] + dpTable[0][y]*b)%MOD;
        }
        for(int y = 0; y < 8192; y++){
            dpTable[0][y] = dpTable[1][y];
            dpTable[1][y] = 0;
        }
    }

    long long ans = 0;
    for(int i = 0; i < 8192; i++){
        if(isPrime[i]){
            ans += dpTable[0][i];
        }
    }

    ans %= MOD;
    std::cout << ans << std::endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    fillPrimes();
    int q = 0;
    std::cin >> q;
    while(q--){
        f();
    }
    return 0;
}

