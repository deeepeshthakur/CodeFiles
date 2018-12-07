#include <bits/stdc++.h>

using namespace std;

int minSteps(int n, string B){
    // Complete this function
    int count = 0;
    for( int index = 0; index < n - 2; index++)
    {
    	if((B[index] == '0') && (B[index+1] == '1') && (B[index+2] == '0'))
    	{
    		B[index+2] = '1';
    		count++;
    	}
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    string B;
    cin >> B;
    int result = minSteps(n, B);
    cout << result << endl;
    return 0;
}
