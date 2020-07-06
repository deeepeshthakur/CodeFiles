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
    int n,a,b;
    cin>>n>>a>>b;
    vector<vector<int>> gr(n,vector<int>(n,0));
    if(a==1 || b==1){
        bool flag=false;
        if(a==1 && b==1){
            if(n!=2 && n!=3){
                flag=true;
                for(int i=0;i<n;i++)
                if(i+1<n){
                    gr[i][i+1]=1;
                    gr[i+1][i]=1;
                }
            }
        }
        else{
            flag=true;
            if(a==1){
                for(int i=b-1;i<n;i++)
                    if(i+1<n){
                        gr[i][i+1]=1;
                        gr[i+1][i]=1;
                    }
                for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i!=j) gr[i][j]=1-gr[i][j];
            }
            else{
                for(int i=a-1;i<n;i++)
                    if(i+1<n){
                        gr[i][i+1]=1;
                        gr[i+1][i]=1;
                    }
            }
        }
        if(flag){
            cout<<"YES\n";
            for(int i=0;i<n;i++) for(int j=0;j<n;j++) cout<<gr[i][j]<<(j+1<n?"":"\n");
            return;
        }
    }
    
    cout<<"NO\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}