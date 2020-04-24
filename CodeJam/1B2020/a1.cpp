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

void solve(int test_case){
    long long x,y;
    cin>>x>>y;
    long long sm=abs(x)+abs(y);
    long long mul=1;
    while(mul<=sm){
        mul=mul*2ll;
    }
    mul-=1;
    if(sm%2==1 && (mul-sm)%2==0){
        long long del=(mul-sm)/2;
        string s;
        int ctr=0;
        long long up=1;
        while(up<=mul){
            up*=2ll;
            ctr++;
        }
        s.resize(ctr);
        for(int i=0;i<s.size();i++){
            s[i]=(y>0)?'N':'S';
            // cout<<(2&(1ll<<(i*1ll)))<<"Here\n";
            if((abs(x)&(1ll<<(i*1ll)))!=0){
                s[i]=(x>0)?'E':'W';
            }
            if((del&(1ll<<(i*1ll)))!=0){
                s[i]=(y>0)?'S':'N';
            }
        }
        cout<<"Case #"<<test_case<<": "<<s<<"\n";
        return;
    }
    cout<<"Case #"<<test_case<<": "<<"IMPOSSIBLE"<<"\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}