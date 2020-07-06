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

void print_vec(vector<int>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

void print_vec(vector<bool>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}


void solve(){
    int n;
    cin>>n;
    vector<int> c(n,0);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) a[i]--;

    vector<bool> vis(n,true);
    vector<int> parent(n,-1);
    for(int i=0;i<n;i++){
        if(vis[i]){
            vector<int> ctr;
            int curr=i;
            while(vis[curr]){
                vis[curr]=false;
                ctr.pb(curr);
                curr=a[curr];
            }
            if(parent[curr]==-1){
                for(int j=0;j<ctr.size();j++) parent[ctr[j]]=curr;
            }
            else{
                for(int j=0;j<ctr.size();j++) parent[ctr[j]]=parent[curr];
            }
        }
    }

    for(int i=0;i<n;i++) vis[i]=true;
    long long ans=0;
    for(int i=0;i<n;i++){
        if(vis[i]){
            if(vis[parent[i]]){
                int pr=parent[i];
                if(a[pr]==pr){
                    ans+=c[pr];
                    vis[pr]=false;
                }
                else{
                    set<int> st;
                    vector<int> p;
                    int curr=pr,set_size=0;
                    st.insert(curr);
                    while(st.size()>set_size){
                        p.pb(curr);
                        curr=a[curr];
                        set_size=st.size();
                        st.insert(curr);
                    }
                    curr=c[p[0]];
                    for(int j=0;j<p.size();j++) curr=min(curr,c[p[j]]);
                    ans+=curr;
                    vis[pr]=false;
                }
            }
            vis[i]=false;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}