#include <bits/stdc++.h>
 
using namespace std;
long long g(long long x,long long y)
{
    if(y==0)
    return x;
    return g(y,x%y);
}
 
int main(){
long long n;
cin>>n;
vector<int>fact;
long long df=1000010;
for(long long i=2;i<=min(df,n-1);i++)
if(n%i==0)
{fact.push_back(i);
fact.push_back(n/i);}
if(fact.size()==0)
{
    cout<<n;
    return 0;
}
long long gcd=fact[0];
for(int i=0;i<fact.size();i++){
	cout << fact[i] << " ";

gcd=g(fact[i],gcd);
}
std::cout << "\n";
cout<<gcd<<"\n";
    
    return 0;
}
 