#include <bits/stdc++.h>

using namespace std;

std::vector< long > tab{};

// long convert( std::string s1)
// {
// 	int len = s1.length();
// 	long ans = 0, multi = 1;
// 	for(int index = len -1; index > -1; index--)
// 	{
// 		ans += (s1[index] - '0')*multi;
// 		multi *= 10;
// 	}
// 	return ans;
// }

long substrings(string balls) {
    // Complete this function
    tab[0] = balls[0] - '0';
    tab[1] = tab[0]*10 + (2*(balls[1] - '0'));
    long sum = tab[0] + tab[1];
	for(int index = 2; index < balls.length(); index++)
	{
		long temp = 0;
		temp = (tab[index - 1])*10 + (index+1)*(balls[index] - '0');
		tab[index] = temp % 1000000007;
		sum += tab[index];
	}
	// for(auto x : tab)
	// 	std::cout << x << " ";
	// std::cout << "\n";
	sum %= 1000000007;

	return sum;
}

int main() {
    string balls;
    cin >> balls;
    int len = balls.length();
    for( int index = 0; index < len; index++)
    	tab.push_back(0);

    long result = substrings(balls);
    cout << result << endl;
    return 0;
}
