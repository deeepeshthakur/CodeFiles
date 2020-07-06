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
    int n;
    cin>>n;
    vector<int> a(int(1e6)+10,0);
    vector<bool> b(a.size(),true);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    for(int i=1;i<b.size();i++){
        if(a[i]>0){
            int j=2;
            while(1ll*j*i<b.size()){
                b[i*j]=false;
                j++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<a.size();i++){
        if(a[i]==1 && b[i]){
            ans++;
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