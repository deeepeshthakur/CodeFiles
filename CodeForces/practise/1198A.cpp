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

int get_k(int k){
    int l=0;
    while((1<<l)<k) l++;
    return l;
}

void solve(){
    int n,I;
    cin>>n>>I;
    int ans=n;
    vector<int> a(n,0),b;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(full(a));
    for(int i=0;i<n;i++){
        if(i>0 && a[i]==a[i-1]){
            b[b.size()-1]++;
        }
        else{
            b.pb(1);
        }
    }

    for(int i=0;i<b.size();i++){
        if(i>0){
            b[i]+=b[i-1];
        }
    }

    for(int i=0;i<b.size();i++){
        int x=i,y=b.size()-1,mid;
        while(y-x>1){
            mid=(x+y)/2;
            if(n*get_k(mid-i+1)<=8*I){
                x=mid;
            }
            else{
                y=mid;
            }
        }
        if(n*get_k(y-i+1)<=8*I) x=y;
        ans=min(ans,(i>0?b[i-1]:0)+(b.back()-b[x]));

        // cout<<ans<<" "<<i<<" "<<x<<"\n";
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