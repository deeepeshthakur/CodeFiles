#include <bits/stdc++.h>

using namespace std;

unsigned long long dp_table[100000];

unsigned long long abs_value( unsigned long long a, unsigned long long b)
{
    if(b > a)
        return b - a;
    return a - b;
}

unsigned long long mandragora(std::vector < unsigned long long > health, unsigned long long Sum) {
    // Complete this function
    unsigned long long Max_P = Sum;
    dp_table[0] = 0;
    for(int index = 1; index < health.size(); index++)
    {
        dp_table[index] = dp_table[index-1] + health[index-1];
        unsigned long long temp = (Sum - dp_table[index])*(index + 1);
        if(temp > Max_P)
            Max_P =temp;
    }
    return Max_P;
}

int main() {
    int test_cases = 0;
    std::cin >> test_cases;
    int count = 0;
    std::vector < std::vector < unsigned long long > > answers( test_cases, std::vector < unsigned long long > ( 2, 0));
    while(test_cases--)
    {   
        std::memset( dp_table, 0, sizeof(dp_table));
        int N;
        std::cin >> N;
        std::vector < unsigned long long > Health(N);
        unsigned long long Sum = 0;
        for(int index = 0; index < N; index++)
        {
            std::cin >> Health[index];
            Sum += Health[index];
        }
        std::sort( Health.begin(), Health.end());
        unsigned long long result = mandragora( Health, Sum);
        std::cout << result << "\n";
    }    
    return 0;
}
