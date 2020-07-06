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

vector<char> f(int x, vector<int>& a, int l, int r){
    vector<char> ans;
    while(l<=r && (x<a[l] || x<a[r])){
        if((x<a[l] && x>=a[r]) || (x<a[l] && a[l]<a[r])){
            x=a[l];
            l++;
            ans.pb('L');
        }
        else{
            if((x<a[r] && x>=a[l])||(x<a[r] && a[r]<a[l])){
                x=a[r];
                r--;
                ans.pb('R');
            
            }
            else{
                if(x<a[l] && a[l]==a[r]){
                    vector<char> a1=f(a[l],a,l+1,r),a2=f(a[l],a,l,r-1);
                    if(a1.size()>=a2.size()){
                        ans.pb('L');
                        for(int i=0;i<a1.size();i++) ans.pb(a1[i]);
                    }
                    else{
                        ans.pb('R');
                        for(int i=0;i<a2.size();i++) ans.pb(a2[i]);
                    }
                    l=r+1;
                }
            }
        }
    }
    return ans;
}

void solve(){
    int n;cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<char> ans=f(0,a,0,n-1);
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++) cout<<ans[i];
    cout<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}