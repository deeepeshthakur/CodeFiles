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
    vector<int> a(n,0),b(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int x=0,y=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            x++;
        }
        if(a[i]==-1){
            y++;
        }
    }

    bool flag=true;
    for(int i=n-1;i>=0;i--){
        if(a[i]==1){
            x--;
        }
        if(a[i]==-1){
            y--;
        }
        if(b[i]!=a[i]){
            if(b[i]>a[i] && x<=0){
                flag=false;
            }
            if(b[i]<a[i] && y<=0){
                flag=false;
            }
        }
    }
    if(flag){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
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