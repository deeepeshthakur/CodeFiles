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

bool tf(long long ind, int k, vector<long long>& a){
    // long long mx=a[ind];
    int sl=0,sr=1;
    // int sz=1+(ind>0?1:0)+(ind+1<a.size()?1:0);
    // for(int i=ind-2;i>=0;i--){
    //     if(a[i]<=mx){
    //         sz+=1;
    //         if(i-1>=0){
    //             sz+=1;
    //             i--;
    //         }
    //     }
    // }
    // for(int i=ind+2;i<a.size();i++){
    //     if(a[i]<=mx){
    //         sz+=1;
    //         if(i+1<a.size()){
    //             sz+=1;
    //             i++;
    //         }
    //     }
    // }
    // cout<<<<" "<<
    // return sz>=k;

    for(int i=1;i<a.size();i++){
        if(a[i]<=ind){
            sr++;
            if(i+1<a.size()){
                i++;
                sr++;
            }
        }
    }

    for(int i=0;i<a.size();i++){
        if(a[i]<=ind){
            sl++;
            if(i+1<a.size()){
                i++;
                sl++;
            }
        }
    }
    return max(sl,sr)>=k;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<long long> a(n,0ll), b(n,0ll);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) b[i]=a[i];
    map<int,int> ht;
    for(int i=0;i<n;i++){
        if(ht.find(a[i])==ht.end()){
            ht.insert({a[i],i});
        }
    }
    sort(full(b));
    int l=0,r=n-1,mid=0;
    while(r-l>1){
        mid=(r+l)/2;
        if(tf(b[mid],k,a)) r=mid;
        else l=mid;
    }    
    if(tf(b[l],k,a)) r=l;
    cout<<b[r]<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t=1;
    while(t--){
        solve();
    }
    return 0;
}