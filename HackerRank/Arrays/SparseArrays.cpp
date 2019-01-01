#include <bits/stdc++.h>
#define ll int
#define pll std::pair<ll,ll>
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define per(i,a,b) for(ll i=(ll)a;i>(ll)b;i--)
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

int f101(std::string s,std::vector<int>& pn){
    int ans=0;
    rep(i,0,s.length()){
        ans+=(s[i]-'a'+1)*pn[i];
    }
    return ans;
}

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    std::vector<int> pn{723563, 723607, 723907, 723977, 724277, 724583, 725531, 725687, 726379, 726589, 727123, 727451, 728003, 728489, 728521, 729271, 730363, 730451, 730819, 731363, 731587};
    std::vector<int> ht{};
    rep(i,0,strings.size()){
        ht.pb(f101(strings[i],pn));
    }
    std::vector<int> ans(queries.size(),0);
    rep(i,0,queries.size()){
        rep(j,0,ht.size()){
            if(f101(queries[i],pn)==ht[j]&&queries[i]==strings[j]){
                ans[i]++;
            }
        }
    }
    return ans;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n,m;
    std::cin>>n;
    std::vector<std::string> st{},qu{};
    std::vector<int> an{};
    st.resize(n);
    rep(i,0,n){
        std::cin>>st[i];
    }
    std::cin>>m;
    qu.resize(m);
    rep(i,0,m){
        std::cin>>qu[i];
    }
    an=matchingStrings(st,qu);
    rep(i,0,an.size()){
        std::cout<<an[i]<<"\n";
    }
    return 0;
}