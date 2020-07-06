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

bool cmp(const pair<int,int>& a, const pair<int,int>& b){
    return a.second<b.second || (a.second==b.second && a.first<b.first);
}

bool tf(int n, vector<vector<int>>& gr, vector<pair<int,int>>& a){
    vector<int> curr(n,1);
    vector<bool> v(n,true);
    for(int i=0;i<n;i++){
        if(curr[a[i].first]!=a[i].second) return false;
        v[a[i].first]=false;
        for(int j=0;j<gr[a[i].first].size();j++){
            if(v[gr[a[i].first][j]])
                curr[gr[a[i].first][j]]=curr[a[i].first]+1;
        }
    }
    return true;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> gr(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        gr[x-1].pb(y-1);
        gr[y-1].pb(x-1);
    }
    vector<pair<int,int>> ord(n,{0,0});
    for(int i=0;i<n;i++){
        cin>>ord[i].second;
        ord[i].first=i;
    }
    sort(full(ord),cmp);
    if(tf(n,gr,ord)){
        for(int i=0;i<n;i++) cout<<ord[i].first+1<<(i+1<n?" ":"\n");
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