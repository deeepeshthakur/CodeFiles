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
int get_next(int v, vector<int>& next){
    if(next[v]==v)
        return v;
    return next[v]=get_next(next[v],next);
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> next(n+1,0),parent(n,-1);
    for(int i=0;i<next.size();i++){
        next[i]=i;
    }

    for(int i=0;i<m;i++){
        int l,r,x;
        cin>>l>>r>>x;
        l--;r--;x--;
        if(parent[l]!=-1){
            l=get_next(l,next);
        }
        while(l<=r){
            if(l!=x){
                parent[l]=x;
                if(l<=x){
                    next[l]=x;
                }
                else{
                    next[l]=r+1;
                }
            }
            l=get_next(l+1,next);
        }
    }
    for(int i=0;i<n;i++){
        cout<<parent[i]+1<<" ";
    }
    cout<<"\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}