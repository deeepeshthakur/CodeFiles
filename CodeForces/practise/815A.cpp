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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    int ans=500*100*100,ind=-1;
    vector<int> h(m,0),v(n,0);
    for(int x=0;x<=grid[0][0];x++){

        for(int i=0;i<n;i++) v[i]=0;
        for(int i=0;i<m;i++) h[i]=0;

        v[0]=x;
        bool flag=true;
        for(int i=0;i<m;i++){
            h[i]=max(0,grid[0][i]-v[0]);
        }
        for(int i=1;i<n;i++){
            v[i]=max(0,grid[i][0]-h[0]);
        }
        for(int i=0;i<n && flag;i++)
            for(int j=0;j<m && flag;j++)
                if(grid[i][j]!=v[i]+h[j])
                    flag=false;

        if(flag){
            int tmp=0;
            for(int i=0;i<n;i++) tmp+=v[i];
            for(int i=0;i<m;i++) tmp+=h[i];
            if(ans>tmp){
                ans=tmp;
                ind=x;
            }
        }
    }

    if(ind!=-1){
        for(int i=0;i<n;i++) v[i]=0;
        for(int i=0;i<m;i++) h[i]=0;
        v[0]=ind;
        for(int i=0;i<m;i++){
            h[i]=grid[0][i]-v[0];
        }
        for(int i=1;i<n;i++){
            v[i]=grid[i][0]-h[0];
        }
        cout<<ans<<"\n";
        for(int i=0;i<n;i++){
            while(v[i]--){
                cout<<"row "<<i+1<<"\n";
            }
        }
        for(int i=0;i<m;i++){
            while(h[i]--){
                cout<<"col "<<i+1<<"\n";
            }
        }
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