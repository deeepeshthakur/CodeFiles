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
    int n;cin>>n;
    queue<int> a,b;
    for(int i=0;i<2*n;i++){
        int x;cin>>x;
        if(x%2==1) a.push(i+1);
        else b.push(i+1);
    }
    if(a.size()%2==1){
        a.pop();
        b.pop();
    }
    else{
        if(!a.empty()){
            a.pop();
            a.pop();
        }
        else{
            b.pop();
            b.pop();
        }
    }
    while(!a.empty()){
        cout<<a.front()<<" ";
        a.pop();
        cout<<a.front()<<"\n";
        a.pop();
    }
    while(!b.empty()){
        cout<<b.front()<<" ";
        b.pop();
        cout<<b.front()<<"\n";
        b.pop();
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}