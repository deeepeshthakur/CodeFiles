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
    vector<vector<int>> gr(n);
    vector<bool> kingdom(n,true),daughters(n,true);
    for(int i=0;i<n;i++){
        int k,tmp;
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>tmp;
            gr[i].pb(tmp-1);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<gr[i].size();j++){
            if(kingdom[gr[i][j]]){
                daughters[i]=false;
                kingdom[gr[i][j]]=false;
                j=gr[i].size()+10;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(daughters[i]){
            for(int j=0;j<n;j++){
                if(kingdom[j]){
                    cout<<"IMPROVE\n";
                    cout<<i+1<<" "<<j+1<<"\n";
                    return;
                }
            }
        }
    }

    cout<<"OPTIMAL\n";
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