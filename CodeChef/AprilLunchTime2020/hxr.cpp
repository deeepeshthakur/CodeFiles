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

vector<bitset<510>> mul(int n,vector<bitset<510>>& num, vector<bitset<510>>& rel){
    vector<bitset<510>> ans(n,bitset<510>(0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(rel[i][j]==1){
                ans[i]^=num[j];
            }
        }
    }
    return ans;
}

void solve(){
    int n;cin>>n;
    int k;cin>>k;
    vector<long long> a(n,0ll);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<bitset<510>> lin(n,bitset<510>(0)),sq(n,bitset<510>(0)),num(n,bitset<510>(0));
    vector<vector<bitset<510>>> mtpl;

    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        x--;y--;
        for(int j=x;j<=y;j++) lin[i][j]=1;
    }
    for(int i=0;i<n;i++) num[i][i]=1;
    mtpl.pb(num);
    mtpl.pb(lin);
    int ctr=2;
    while(ctr<=k){
        sq=mtpl.back();
        sq=mul(n,sq,sq);
        mtpl.pb(sq);
        ctr*=2;
    }

    vector<bitset<510>> ans=num;
    k--;
    while(k>0){
        int ind=1,m=1;
        while(m*2<=k){
            ind++;
            m*=2;
        }
        k-=m;
        ans=mul(n,ans,mtpl[ind]);
    }

    vector<long long> av(n,0ll);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ans[i][j]) av[i]=(av[i]^a[j]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<av[i]<<" ";
    }
    cout<<"\n";
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