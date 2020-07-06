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
    int curr=0;
    queue<int> q;
    vector<int> b(n,0),a(n,0);
    for(int i=0;i<n;i++){
        b[i]=n+10+i;
    }
    for(int i=0;i<n;i++) cin>>a[i];
    bool flag=true;
    for(int i=0;i<n && flag;i++){
        if(a[i]>curr){
            b[i]=curr;
            curr++;
        }
        else{
            q.push(i);
        }
        while(!q.empty() && a[i]>curr){
            b[q.front()]=curr;
            q.pop();
            curr++;
        }
        if(a[i]>curr){
            flag=false;
        }
    }

    if(flag){
        for(int i=0;i<n;i++) cout<<b[i]<<(i+1<n?" ":"\n");
    }
    else{
        cout<<"-1\n";
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}