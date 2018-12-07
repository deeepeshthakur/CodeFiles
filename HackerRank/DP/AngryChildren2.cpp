#include <bits/stdc++.h>

using namespace std;

long long sum[100000];

long long func(std::vector < long long > &packets, int index, int k, long long unfairness)
{
    sum[index] = sum[index - 1] - packets[index-1] + packets[index + k - 1];
    unfairness = unfairness + k*packets[index-1] - sum[index-1];
    unfairness = unfairness + k*packets[index + k - 1] - sum[index];
    return unfairness;
}

long long angryChildren(int K, vector <long long> packets) {
    // Complete this function
    sum[0] = 0;
    long long unfairness = 0;
    std::sort( packets.begin(), packets.end());
    // for( long long x : packets)
    //     std::cout << x  << " ";
    // std::cout << "\n";

    for(int index = 0; index < K; index++)
    {
        sum[0] += packets[index];
        unfairness += (index - 0)*(packets[index]);
        unfairness -= (K - 1 - index)*(packets[index]);
    }


    long long temp = unfairness;
    // std::cout << 0 << " " << temp << "\n";
    for(int index = 1; index <= packets.size() - K; index++)
    {
        
        temp = func( packets, index, K, temp);
        if(unfairness > temp)
            unfairness = temp;
        // std::cout << index << "     " << temp << "   " << sum[index] << "\n";
    }

    return unfairness;    
}

int main() {
    int N;
    cin >> N;
    int K;
    cin >> K;
    vector<long long> packets(N);
    for(int packets_i = 0; packets_i < N; packets_i++){
       cin >> packets[packets_i];
    }
    long long result = angryChildren(K, packets);
    cout << result << endl;
    return 0;
}
