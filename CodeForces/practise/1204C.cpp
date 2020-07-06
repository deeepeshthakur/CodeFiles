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
    vector<vector<int>> adj(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<n;j++) adj[i][j]=(s[j]=='1'?1:100000);
    }
    int m;
    cin>>m;
    stack<int> st;
    for(int i=0;i<m;i++){
        int x;cin>>x;st.push(x-1);
    }
    vector<int> ans;
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++) 
            for(int j=0;j<n;j++) 
                if(i!=j && j!=k && i!=k && adj[i][k]+adj[k][j]<adj[i][j]) adj[i][j]=adj[i][k]+adj[k][j];
    ans.pb(st.top());
    st.pop();
    while(st.size()>=2){
        int tp=st.top();
        st.pop();
        if(st.top()==ans.back() || adj[st.top()][tp]+adj[tp][ans.back()]>adj[st.top()][ans.back()]) ans.pb(tp);
    }
    while(!st.empty()) {ans.pb(st.top());st.pop();}
    cout<<ans.size()<<"\n";
    for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]+1<<" ";
    cout<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}