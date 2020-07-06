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

int rec(int n,int m, int len, int curr,vector<int> seq, vector<vector<int>>& q){
    if(len==n){
        int ret=0;
        for(int i=0;i<q.size();i++){
            if(q[i][2]==seq[q[i][1]-1]-seq[q[i][0]-1]) ret+=q[i][3];
        }
        return ret;
    }
    if(len<n && curr>m) return 0;
    vector<int> a=seq;
    a.pb(curr);
    return max(rec(n,m,a.size(),curr,a,q),rec(n,m,seq.size(),curr+1,seq,q));
}

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> qu(q,vector<int>(4,0));
    for(int i=0;i<qu.size();i++){
        for(int j=0;j<4;j++) cin>>qu[i][j];
    }
    int ans=rec(n,m,0,1,vector<int>{},qu);
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}