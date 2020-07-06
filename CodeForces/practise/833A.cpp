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

vector<vector<int>> pf(int(1e6)+10);
void pre_calc(){
    vector<bool> is_prime(int(1e6)+10,true);is_prime[0]=is_prime[1]=false;
    for(int i=0;i<is_prime.size();i++){
        if(is_prime[i]){
            pf[i].pb(i);
            int j=2;
            while(1ll*i*j<is_prime.size()){
                is_prime[i*j]=false;
                pf[i*j].pb(i);
                j++;
            }
        }
    }
}

long long gm(long long a){
    long long l=1,r=int(1e6),mid;
    while(r-l>1){
        mid=(l+r)/2;
        if(mid*mid*mid>a){
            r=mid;
        }
        else{
            l=mid;        
        }
    }
    if(l*l*l==a) return l;
    if(r*r*r==a) return r;
    return -1;
}

void solve(){
    long long a,b;
    cin>>a>>b;
    long long ab=a*b,kk=gm(ab);
    if(kk!=-1){
        if(kk==1){
            cout<<"Yes\n";
            return;
        }
        bool flag=true;
        for(int i=0;i<pf[kk].size();i++){
            int x=0,y=0;
            while(a%pf[kk][i]==0){
                x++;
                a/=pf[kk][i];
            }
            while(b%pf[kk][i]==0){
                y++;
                b/=pf[kk][i];
            }
            if(!(2*x-y>=0 && 2*y-x>=0 && (2*x-y)%3==0 && (2*y-x)%3==0)){
                flag=false;
            }
        }

        if(flag){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    pre_calc();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}