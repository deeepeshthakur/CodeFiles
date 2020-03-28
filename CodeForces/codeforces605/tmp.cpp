#include <iostream>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
#define int long long
 
main(){
int q;
cin >> q;
for (int j=0; j<q; j++){
    int a,b,c,x=0;
    cin >> a >> b >> c;
    x=abs(a-b)+abs(a-c)+abs(c-b)-4;
    if (x<0) x=0;
    cout << x << endl;
}
}