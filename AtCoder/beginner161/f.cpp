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
    int n,k,c;
    cin>>n>>k>>c;
    string s;
    cin>>s;
    
    vector<int> valid(n,0);
    for(int i=n-1;i>=0;i--){
        if(i<n-1){
            valid[i]=valid[i+1];
        }
        else{
            valid[i]=n+10;
        }
        if(s[i]=='o'){
            valid[i]=min(valid[i],i);
        }
    }
    
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}