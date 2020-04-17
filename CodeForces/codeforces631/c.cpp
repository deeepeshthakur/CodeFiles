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
    int n,m;
    cin>>n>>m;
    vector<int> l(m,0);
    vector<long long> psum(m,0ll);
    for(int i=0;i<m;i++)
        cin>>l[i];
    for(int i=m-1;i>-1;i--){
        if(i<m-1){
            psum[i]=l[i]+psum[i+1];
        }
        else{
            psum[i]=l[i];
        }
    }
    if(psum[0]>=n){
        bool flag=true;
        for(int i=0;i<m;i++){
            if(l[i]>n-i){
                flag=false;
            }
        }
        if(flag){
            vector<int> ans(m,0);
            for(int i=0;i<m;i++){
                if(psum[i]>n-i){
                    ans[i]=i;
                }
                else{
                    ans[i]=n-psum[i];
                }
            }
            for(int i=0;i<m;i++){
                cout<<ans[i]+1<<" ";
            }
            cout<<"\n";
            return;
        }
    }
    cout<<"-1\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}