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
    string s;
    cin>>s;
    int sc=0;
    vector<int> a(s.size(),0);
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') sc++;
        if(s[i]==')') sc--;
        if(sc<0 || (s[i]=='#'&&sc==0)){
            cout<<"-1\n";
            return;
        }
        if(s[i]=='#'){
            sc--;
            a[i]=1;
        }
    }
    if(sc>0){
        for(int i=a.size()-1;i>=0;i--){
            if(a[i]==1){
                a[i]+=sc;
                sc=0;
                i=-1;
            }
        }
    }
    sc=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') sc++;
        if(s[i]==')') sc--;
        if(s[i]=='#') sc-=a[i];
        if(sc<0){
            cout<<"-1\n";
            return;
        }
    }
    for(int i=0;i<a.size();i++) if(a[i]>0) cout<<a[i]<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}