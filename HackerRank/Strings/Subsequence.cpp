#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    char a[] = "hackerrank";
    cin >> q;
    for(int a0 = 0; a0 < q; a0++)
    {
        string s;
        cin >> s;
        // your code goes here
        bool check = true;
        int index1 = 0, index2 = 0;
        while(check && (index1 < s.length()))
        {
           if(a[index2] == s[index1])
           {
            //std::cout << a[index2];
            index2++;
            if(index2 == 10)
                check = false;
           }

           index1++;
        }
        if(!check)
            std::cout << endl <<  "YES" << endl;
        else
            std::cout << endl << "NO" << endl;
    }
    return 0;
}
