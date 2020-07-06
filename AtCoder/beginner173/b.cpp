#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define full(a) a.begin(),a.end()
#define rfull(a) a.rbegin(),a.rend()

using namespace std;
const double pi=acos(-1.0);
const double pii=2*pi;
const double eps=1e-6;
const long long MOD=1e9+7;

void solve(){
    int n;
    cin>>n;
    map<string,int> ht;
    ht.insert({"AC",0});
    ht.insert({"WA",0});
    ht.insert({"TLE",0});
    ht.insert({"RE",0});
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        ht[s]++;
    }
    cout<<"AC x "<<ht["AC"]<<"\n";
    cout<<"WA x "<<ht["WA"]<<"\n";
    cout<<"TLE x "<<ht["TLE"]<<"\n";
    cout<<"RE x "<<ht["RE"]<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}