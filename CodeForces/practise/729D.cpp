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

struct node{
    int start,len,del,n;
};

node gn(){
    node a;
    a.len=a.start=a.del=a.n=0;
    return a;
}

struct cmp{
    bool operator()(const node& a, const node& b){
        return a.del>b.del;
    }
};

void solve(){
    int n,a,b,k;
    cin>>n>>a>>b>>k;
    string s;
    cin>>s;
    priority_queue<node,vector<node>,cmp> pq;
    int ctr=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            int j=i;
            for(;s[j+1]=='0' && j<n;j++);
            node tmp=gn();
            tmp.start=i+1;
            tmp.len=j-i+1;
            tmp.n=tmp.len/b;
            tmp.del=tmp.len-tmp.n*b;
            ctr+=tmp.n;
            if(tmp.n>0) pq.push(tmp);
            i=j;
        }
    }
    vector<int> ans;
    while(ctr>=a&&!pq.empty()){
        node x=pq.top(),y,z;
        ctr-=x.n;
        pq.pop();
        if(x.len>b){
            z.len=x.len-b;
            z.start=x.start+b;
            z.n=z.len/b;
            z.del=z.len-z.n*b;
            if(z.n>0){
                ctr+=z.n;
                pq.push(z);
            }
        }
        ans.pb(x.start+b-1);
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<(i+1<ans.size()?" ":"\n");
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}