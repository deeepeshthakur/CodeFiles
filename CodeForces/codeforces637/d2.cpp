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

int get_min(string& a, string& b){
    int ans=0;
    for(int i=0;i<a.size();i++){
        if(b[i]=='0' && a[i]=='1'){
            return -1;
        }
        if(b[i]=='1' && a[i]=='0')
            ans++;
    }
    return ans;
}

void solve(){
    int n,k;cin>>n>>k;
    vector<string> a(n),b{"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> mn(n,-1);
    vector<int> dig(n,-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<9;j++){
            int tmp=get_min(a[i],b[j]);
            if(tmp!=-1){
                if(mn[i]==-1 || mn[i]>tmp){
                    mn[i]=tmp;
                    dig[i]=j;
                }
            }
        }
    }
    int sm=0;
    for(int i=0;i<n;i++){
        if(mn[i]==-1){
            cout<<"-1\n";
            return;
        }
        sm+=mn[i];
    }
    if(sm>k){
        cout<<"-1\n";
        return;
    }

    k-=sm;
    for(int i=n-1;i>=0;i--){
        k+=mn[i];
        for(int j=9;j>=0;j--){
            int tmp=get_min(a[i],b[j]);
            if(tmp!=-1 && tmp<=k){
                k-=tmp;
                dig[i]=j;
                mn[i]=tmp;
                j=-1;
            }
        }
    }
    // cout<<k<<"\n";
    // for(int i=0;i<n;i++)cout<<dig[i];cout<<"\n";
    if(k>0){
        vector<int> c={8,9,6,0,5,3,2,4,7,1};
        for(int i=0;i<n && k>0;i++){
            for(int j=0;j<=9;j++){
                int tmp=get_min(a[i],b[c[j]]);
                if(tmp>mn[i] && tmp<=k+mn[i]){
                    k+=mn[i];
                    mn[i]=tmp;
                    k-=tmp;
                    dig[i]=c[j];
                    j=11;
                }
            }
        }
    }
    if(k==0){
        for(int i=n-1;i>=0;i--){
            cout<<dig[i];
        }
        cout<<"\n";
    }
    else{
        cout<<"-1\n";
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}