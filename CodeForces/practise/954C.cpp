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
    vector<long long> a(n,0ll);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) a[i]--;
    long long x=0,y=-1;
    for(int i=1;i<n;i++) if(abs(a[i]-a[i-1])>1) {y=abs(a[i]-a[i-1]);break;}
    if(y==-1) y=1;
    for(int i=0;i<n;i++){
        x=max(x,a[i]/y);
    }
    x++;
    // cout<<x<<" "<<y<<"\n";
    long long cx=a[0]/y,cy=a[0]%y,nx,ny;
    bool flag=true;
    for(int i=1;i<n && flag;i++){
        nx=a[i]/y;ny=a[i]%y;
        if(nx>=0 && nx<x && ny>=0 && ny<y && ((abs(cx-nx)==0 && abs(ny-cy)==1)||(abs(cx-nx)==1 && abs(ny-cy)==0))){
            cx=nx;
            cy=ny;
        }
        else flag=false;
    }
    if(flag) cout<<"YES\n"<<x<<" "<<y<<"\n";
    else cout<<"NO\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}