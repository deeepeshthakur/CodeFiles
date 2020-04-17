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
    long long n,mx=1ll*int(1e6)+10;
    cin>>n;
    set<long long> st;
    vector<long long> fc,nfc;
    for(long long i=1;i<=mx;i++){
        if((n-1)%i==0){
            nfc.pb(i);
            nfc.pb((n-1)/i);
        }
        if(n%i==0){
            fc.pb(i);
            fc.pb(n/i);
        }
    }

    long long tmpn=n;
    for(int i=0;i<fc.size();i++){
        tmpn=n;
        if(fc[i]<=n && fc[i]>1){
            while(tmpn%fc[i]==0){
                tmpn/=fc[i];
            }
            if(tmpn%fc[i]==1 || tmpn==1){
                st.insert(fc[i]);
            }
        }
    }  

    for(int i=0;i<nfc.size();i++){
        if(nfc[i]<=n && n%nfc[i]==1){
            if(nfc[i]>1)
                st.insert(nfc[i]);
        }
    }
    cout<<st.size()<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}