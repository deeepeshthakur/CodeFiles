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

long long g(vector<int>& a){
    long long ans=0;
    for(int i=0;i<a.size();i++){
        ans=ans*10+a[i];
    }
    return ans;
}

void solve(){
    string aa,bb;cin>>aa>>bb;
    vector<int> a,b;
    for(int i=0;i<aa.size();i++) a.pb(int(aa[i]-'0'));
    for(int i=0;i<bb.size();i++) b.pb(int(bb[i]-'0'));
    vector<int> dig(10,0);
    for(int i=0;i<a.size();i++) dig[a[i]]++;
    vector<int> ans(a.size(),0);
    for(int i=0;i<a.size();i++){
        for(int j=9;j>=0;j--){
            if(dig[j]>0){
                dig[j]--;
                ans[i]=j;
                vector<int> tmp;
                for(int k=0;k<10;k++) for(int z=0;z<dig[k];z++) tmp.pb(k);
                if(g(b)>= g(ans)+g(tmp)){
                    j=-10;
                }
                else{
                    dig[j]++;
                    ans[i]=0;
                }
            }
        }
    }
    cout<<g(ans)<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}