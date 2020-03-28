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
    string x;
    cin>>x;
    vector<int> a(n,0),b(n,0);
    bool flag=true;
    for(int i=0;i<n;i++){
        if(flag){
            if(x[i]=='1'){
                a[i]=1;
                flag=false;
            }
            else{
                a[i]=int(x[i]-'0')/2;
                b[i]=a[i];
            }
        }
        else{
            b[i]=int(x[i]-'0');
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    cout<<"\n";
        for(int i=0;i<n;i++){
        cout<<b[i];
    }
    cout<<"\n";
    
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