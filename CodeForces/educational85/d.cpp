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

void add_str(int ind, int n, vector<int>& a){
    if(ind<n){
        for(int i=ind+1;i<=n;i++){
            a.pb(ind);
            a.pb(i);
        }
    }
}

void solve(){
    int n;
    cin>>n;
    long long l,r;
    cin>>l>>r;
    long long ctr=0;
    for(int i=1;i<=n;i++){
        if(l>ctr+2ll*(n-i)){
            ctr+=2ll*(n-i);
        }
        else{
            long long tmp_ctr=ctr;
            vector<int> ans_vec;
            int j=i;
            while(r>tmp_ctr && j<n){
                add_str(j,n,ans_vec);
                tmp_ctr+=2ll*(n-j);
                j++;
            }
            if(j==n){
                ans_vec.pb(1);
            }
            for(j=0;j<ans_vec.size();j++){
                if(l<=ctr+j+1 && ctr+j+1<=r){
                    cout<<ans_vec[j]<<" ";
                }
            }
            cout<<"\n";
            return;
        }
    }
    if(l==r && l==(1ll*n*n-n+1ll)){
        cout<<"1\n";
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