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

bool cmp(const pair<int,int>& a,const pair<int,int>& b){
    return a.first<b.first || (a.first==b.first && a.second>b.second);
}

void solve(){
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin>>s[i];

    int tot=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<s[i].size();j++) tot+=(s[i][j]=='('?1:-1);
    }
    if(tot==0){
        vector<pair<int,int>> sm(n,{0,0});
        for(int i=0;i<n;i++){
            int x=0,y=0;
            for(int j=0;j<s[i].size();j++){
                x+=(s[i][j]=='('?1:-1);
                y=min(x,y);
            }
            sm[i]={abs(y),x};
        }
        sort(full(sm),cmp);
        tot=0;
        bool flag=true;
        for(int i=0;i<n;i++){
            if(sm[i].first>tot) flag=false;
            tot+=sm[i].second;
        }
        flag=(flag&&(tot==0));
        if(flag){
            cout<<"Yes\n";
            return;
        }
    }

    cout<<"No\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}