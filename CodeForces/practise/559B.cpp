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

string are_eq(int n, string a){
    string ans;
    if(n%2==0){
        string x(n/2,'a'),y(n/2,'a');
        for(int i=0;i<n/2;i++){
            x[i]=a[i];
            y[i]=a[i+n/2];
        }
        x=are_eq(x.size(),x);
        y=are_eq(y.size(),y);
        if(x>y) swap(x,y);
        ans=a;
        for(int i=0;i<n;i++){
            if(i<n/2) ans[i]=x[i];
            else ans[i]=y[i-n/2];
        }
    }
    else{
        ans=a;
    }
    return ans;
}

void solve(){
    string a,b;
    cin>>a>>b;
    if(are_eq(a.size(),a)==are_eq(b.size(),b)) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}