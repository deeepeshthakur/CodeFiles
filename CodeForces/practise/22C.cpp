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
    int n,m,v;cin>>n>>m>>v;
    vector<vector<int>> gr(n);
    gr[0].pb(1);
    m--;
    for(int i=2;i<n;i++) {gr[1].pb(i);m--;}
    for(int i=2;i<n && m>0;i++){
        for(int j=i+1;j<n && m>0;j++){
            gr[i].pb(j);
            m--;
        }
    }
    if(m==0){
        for(int i=0;i<n;i++){
            for(int j=0;j<gr[i].size();j++){
                int x=i+1,y=gr[i][j]+1;
                if(x==2 || x==v){
                    if(x==2){
                        x=v;
                    }
                    else{
                        x=2;
                    }
                }
                if(y==2 || y==v){
                    if(y==2){
                        y=v;
                    }
                    else{
                        y=2;
                    }
                }
                cout<<x<<" "<<y<<"\n";
            }
        }
    }
    else{
        cout<<-1<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}