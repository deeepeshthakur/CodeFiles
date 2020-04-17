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
    int n=s.size();
    // vector<vector<int>> dl(n,vector<int>(26,0)),dr(n,vector<int>(26,0));
    // for(int i=0;i<n;i++){
    //     dl[i][int(s[i]-'a')]++;
    //     dr[n-1-i][int(s[n-1-i]-'a')]++; 
    //     if(i>0){
    //         for(int j=0;j<26;j++){
    //             dl[i][j]+=dl[i-1][j];
    //         }
    //     }
    //     if(n-1-i>0){
    //         for(int j=0;j<26;i++){
    //             dr[n-i-1][j]+=dr[n-i][j];
    //         }
    //     }
    // }
    int l=1,r=n,mid;
    while(r-l>1){
        mid=(l+r)/2;
        
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