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
    vector<int> a(n,0),colp(n,-1);
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    vector<int> f{2,3,5,7,11,13,17,19,23,29,31};
    vector<int> col(f.size(),0);
    for(int i=0;i<n;i++){
        for(int j=0;j<11;j++){
            if(a[i]%f[j]==0){
                col[j]=1;
                colp[i]=j;
                j=20;
            }
        }
    }

    int ans=0;
    for(int i=0;i<11;i++){
        if(col[i]>0){
            ans++;
            col[i]=ans;
        }
    }

    cout<<ans<<"\n";
    for(int i=0;i<n;i++){
        cout<<col[colp[i]]<<(i<n-1?" ":"\n");
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