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
    vector<int> dpx(int(1e6)+1,0),dpy(int(1e6)+1,0);
    for(int i=0;i<n;i++){
        int mnx=int(1e7),mny=int(1e7),mxx=0,mxy=0;
        for(int i=0;i<3;i++){
            int x,y;
            cin>>x>>y;
            mnx=min(mnx,x);
            mxx=max(mxx,x);
            mny=min(mny,y);
            mxy=max(mxy,y); 
        }
        if(mnx<mxx){
            dpx[mnx]++;
            dpx[mxx-1]--;
        }
        if(mny<mxy){
            dpy[mny]++;
            dpy[mxy-1]--;
        }
    }
    int tmp=0,curr=0;
    for(int i=0;i<dpx.size();i++){
        tmp=dpx[i];
        dpx[i]=curr;
        curr+=tmp;
    }
    tmp=0;curr=0;
    for(int i=0;i<dpy.size();i++){
        tmp=dpy[i];
        dpy[i]=curr;
        curr+=tmp;
    }

    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        char a,e;
        int xx;
        cin>>a>>e>>xx;
        if(a=='x'){
            cout<<dpx[xx]<<"\n";
        }
        else{
            cout<<dpy[xx]<<"\n";
        }
    }    
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}