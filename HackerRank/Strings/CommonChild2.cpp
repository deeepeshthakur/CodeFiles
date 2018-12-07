#include <bits/stdc++.h>

using namespace std;

std::string s1, s2;
int bookkeeping[5001][5001];

int max_val( int a, int b)
{
	if(a >= b)
		return a;
	return b;
}

int commonChild( int n, int m){
    // Complete this function
    if(bookkeeping[n][m] != -1)
    	return bookkeeping[n][m];

    if((n == 0) || (m == 0))
    {
    	bookkeeping[n][m] = 0;
    	return 0;	
    }
    
    if(s1[n-1] == s2[m-1])
    {

    	int temp = 1 + commonChild( n-1, m-1);
    	bookkeeping[n][m] = temp;
    	return temp;
    }
    
    
    int temp2 = max_val( commonChild( n, m -1), commonChild( n-1, m));
    bookkeeping[n][m] = temp2;
    return temp2;
}

int main() {
    std::cin >> s1 >> s2;
    for( int x = 0; x < 5001; x++)
    	for( int y = 0; y < 5001; y++)
    		bookkeeping[x][y] = -1;
    int n = s1.length(), m = s2.length();
    // int result = commonChild( n, m);

    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<=m; j++)
        {
            if(i==0 || j==0)
                bookkeeping[i][j] = 0;
            else {
                if(s1[i - 1]==s2[j - 1])
                    bookkeeping[i][j] = 1+ bookkeeping[i-1][j-1];
                else
                    bookkeeping[i][j] = max(bookkeeping[i-1][j], bookkeeping[i][j-1]);
            }
        }
    }
    cout << bookkeeping[n][m] << endl;
    return 0;
}
