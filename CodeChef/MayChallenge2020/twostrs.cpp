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

void print_vec(vector<long long>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

struct node{
    long long val;
    vector<node*> child;
};

node* get_n(){
    node *a=new node;
    a->val=0;
    a->child = vector<node*>(26,NULL);
    return a;
}

void add(node* trie, int ind, int val, string& s){
    if(ind+1<s.size()){
        int ch=(s[ind+1]-'a');
        if(trie->child[ch]==NULL) trie->child[ch]=get_n();
        add(trie->child[ch],ind+1,val,s);
    }
    else
        trie->val=val;
}

long long search(node* trie, int ind, string& s){
    if(ind+1<s.size()){
        int ch=int(s[ind+1]-'a');
        return trie->val+(trie->child[ch]?search(trie->child[ch],ind+1,s):0ll);
    }
    else{
        return trie->val;
    }
}

long long str_s(node* trie,string& s){
    if(s.size()>0) return search(trie,-1,s);
    return 0ll;
}

void solve(){
    string a,b;
    int n;
    cin>>a>>b;
    cin>>n;
    node *trie=get_n();

    vector<vector<long long>> dp(26,vector<long long>(26,0ll));
    for(int i=0;i<n;i++){
        string s;cin>>s;
        int x;cin>>x;
        set<int> st;
        for(int j=1;j<s.size();j++){
            dp[int(s[j-1]-'a')][int(s[j]-'a')]+=x;
        }
        add(trie,-1,x,s);
    }

    vector<long long> a_dp(a.size(),0ll),b_dp(b.size(),0ll);
    for(int i=0;i<a_dp.size();i++){
        if(i>0) a_dp[i]+=a_dp[i-1];
        for(int j=0;j<26 && i-j>=0;j++){
            string s;
            for(int k=i-j;k<i;k++) s.push_back(a[k]);
            a_dp[i]-=str_s(trie,s);
            s.push_back(a[i]);
            a_dp[i]+=str_s(trie,s);
        }
    }

    for(int i=b.size()-1;i>=0;i--){
        if(i+1<b.size()) b_dp[i]+=b_dp[i+1];
        string s;
        for(int k=i;k<26+i && k<b.size();k++) s.push_back(b[k]);
        b_dp[i]+=str_s(trie,s);
    }

    long long mx=0;
    for(int i=a.size()-1;i>=0;i--){
        for(int j=0;j<b.size();j++){
            if(mx<a_dp[i]+b_dp[j]+dp[int(a[i]-'a')][int(b[j]-'a')]){
                int l=max(i-24,0),r;
                long long curr=0;
                for(int k=l;k<=i;k++){
                    string s;
                    for(int x=k;x<=i;x++) s.pb(a[x]);
                    curr-=str_s(trie,s);
                    r=min(int(b_dp.size())-1,j+24-i+k);
                    for(int x=j;x<=r;x++) s.pb(b[x]);
                    curr+=str_s(trie,s);
                }
                curr+=a_dp[i]+b_dp[j];

                mx=max(mx,curr);
            }
        }
    }
    cout<<mx<<"\n";
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