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

void f1(vector<string>& ss, string &s, int ind){
    int n=s.size();
    string t(n,'a');
    for(int i=0;i<n;i++) t[i]=s[(ind+i)%n];
    ss.pb(t);
}

void solve(){
    int l;
    cin>>l;
    string s;
    cin>>s;
    if(l==1){
        string t="";
        for(int i=0;i<s.size();i++) t.pb(s[i]);
        for(int i=0;i<s.size();i++) t.pb(s[i]);
        vector<int> f(t.size(),-1);
        int k=0;
        for(int j=1;j<t.size();j++){
            char sj=s[j];
            int i=f[j-1-k];
            while(i!=-1 && sj!=s[k+i+1]){
                if(sj<s[k+i+1])
                    k=j-i-1;
                i=f[i];
            }
            if(sj!=s[k+1+i]){
                if(sj<s[k]){
                    k=l;
                }
                f[j-k]=-1;
            }
            else{
                f[j-k]=i+1;
            }
        }
        string ans(s.size(),'a'),ans1(s.size(),'a');
        for(int i=0;i<s.size();i++) {
            ans[i]=t[i+k];
            ans1[i]=t[s.size()+i-k];
        }
        cout<<ans<<" "<<ans1<<"\n";
        ans=min(ans,ans1);
        cout<<ans<<"\n";
        // vector<string> ss;
        // for(int i=0;i<s.size();i++) f1(ss,s,i);
        // sort(full(ss));
        // cout<<ss[0]<<"\n";

    }
    else{
        sort(full(s));
        cout<<s<<"\n";
    }

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