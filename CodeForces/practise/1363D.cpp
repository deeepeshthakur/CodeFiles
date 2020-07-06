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

int query(vector<int> tmp){
    cout<<"? "<<tmp.size();
    for(int i=0;i<tmp.size();i++) cout<<" "<<tmp[i];
    cout<<endl;
    int ans;
    cin>>ans;
    return ans;
}

pair<int,int> f(int l,int r, vector<vector<int>>& s, int mx){
    if(mx==-1){
        vector<int> tmp;
        for(int i=l;i<=r;i++) 
            for(int j=0;j<s[i].size();j++) tmp.pb(s[i][j]);
        mx=query(tmp);
        return f(l,r,s,mx);
    }

    if(l==r){
        return pair<int,int>({l,mx});
    }

    int mid=(l+r)/2;
    vector<int> tmp;
    for(int i=l;i<=mid;i++) 
        for(int j=0;j<s[i].size();j++) tmp.pb(s[i][j]);
    int curr_mx=query(tmp);
    if(curr_mx==mx) return f(l,mid,s,mx);
    return f(mid+1,r,s,mx);
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> s(k);
    for(int i=0;i<k;i++){
        int c;
        cin>>c;
        for(int j=0;j<c;j++){
            int x;
            cin>>x;
            s[i].pb(x);
        }
    }
    vector<bool> v(n+1,true);
    for(int i=0;i<k;i++){
        for(int j=0;j<s[i].size();j++){
            v[s[i][j]]=false;
        }
    }
    vector<int> tmp;
    for(int i=1;i<=n;i++) if(v[i]) tmp.pb(i);
    if(tmp.size()>0) s.pb(tmp);
    pair<int,int> ans=f(0,s.size()-1,s,-1);
    tmp.resize(0);
    for(int i=0;i<=n;i++) v[i]=true;
    for(int i=0;i<s[ans.first].size();i++) v[s[ans.first][i]]=false;
    for(int i=1;i<=n;i++) if(v[i]) tmp.pb(i);
    int sec=query(tmp);
    vector<int> vec_ans(k,0);
    for(int i=0;i<k;i++){
        if(i==ans.first){
            vec_ans[i]=sec;
        }
        else vec_ans[i]=ans.second;
    }
    cout<<"!";
    for(int i=0;i<k;i++) cout<<" "<<vec_ans[i];
    cout<<endl;
    string ccc;
    cin>>ccc;
    return;
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