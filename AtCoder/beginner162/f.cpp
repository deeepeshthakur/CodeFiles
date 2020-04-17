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
long long neg_inf=0;

void fill_dp(int x, int y, map<pair<int,int>,long long>& ht, int n, vector<long long>& a){
    if(x>n){
        ht.insert({{x,y},neg_inf});
        return;
    }

    if(y>1){
        if(x<2*y-1){
            ht.insert({{x,y},neg_inf});
            return;
        }
        long long tmp=neg_inf;
        for(int i=x;i>0 && i>=2*y-1;i--){
            if(ht.find({i-2,y-1})!=ht.end()){
                tmp=max(tmp,ht.find({i-2,y-1})->second + a[i-1]);
            }
        }
        ht.insert({{x,y},tmp});
    }
    else{
        long long tmp=0;
        for(int i=0;i<x;i++){
            tmp=max(tmp,a[i]);
        }
    
        ht.insert({{x,y},tmp});
    }
}

void f1(int x,int y,map<pair<int,int>,long long>& ht, int n, vector<long long>& a){
    fill_dp(x,y,ht,n,a);
}

void solve(){
    int n;
    cin>>n;
    vector<long long> a(n,0ll);
    long long min_sm=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        neg_inf-=abs(a[i]);
        if(i%2==1){
            min_sm+=a[i];
        }
    }
    neg_inf=neg_inf*2-100-MOD;
    int m=n/2;
    map<pair<int,int>,long long> ht;
    for(int i=1;i<=m;i++){
        f1(2*i-1,i,ht,n,a);
        f1(2*i,i,ht,n,a);
        f1(2*i+1,i,ht,n,a);
        f1(2*i+2,i,ht,n,a);
    }
    long long ans=neg_inf;
    for(int i=n;i>0 && i>=2*m-1;i--){
        if(ht.find({i,m})!=ht.end()){
            ans=max(ans,ht.find({i,m})->second);
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