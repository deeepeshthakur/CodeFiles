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

void frmt(string& a){
    for(int i=0;i<a.size();i++){
        if(a[i]>='a' && a[i]<='z'){
            a[i]=char(int('A'+a[i]-'a'));
        }
    }
}

void solve(){
    int n;
    cin>>n;
    map<string,int> ht;
    ht.insert({"POLYCARP",0});
    string a,b,c;
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        frmt(a);
        frmt(c);
        ht.insert({a,ht[c]+1});
        mx=max(ht[a],mx);
    }
    cout<<mx+1<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}