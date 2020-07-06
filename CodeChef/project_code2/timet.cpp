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
    vector<vector<int>> gr(n,vector<int>(n,1000)), mat(n,vector<int>(n,1000));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>mat[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                mat[j][k]=min(mat[j][k],mat[j][i]+mat[i][k]);
    for(int i=0;i<n;i++)
        if(mat[i][i]<0){
            cout<<"YES\n";
            return;
        }

    cout<<"NO\n";
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