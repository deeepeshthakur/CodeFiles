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
    int v;
    cin>>v;
    vector<int> a(9,0),b(9,0);
    for(int i=0;i<9;i++){
        cin>>a[i];
    }
    priority_queue<int> pq;
    int dig=-1,mx=a[0],del=0;
    for(int i=0;i<9;i++){
        if(v>=a[i] && mx>=a[i]){
            mx=a[i];
            dig=i;
            del=v%a[i];
        }
    }

    if(dig>-1){
        while(v>=mx){
            pq.push(dig);
            v-=mx;
        }
        vector<int> ans;
        while(pq.size()>=2){
            int x,y;
            x=pq.top();pq.pop();
            y=pq.top();pq.pop();
            bool flag=true;
            // cout<<x<<" "<<y<<" "<<del<<" ";
            for(int i=8;i>x&&flag;i--){
                int min_m=a[0],min_dig=0;
                for(int j=0;j<9;j++){
                    if(a[j]<=min_m){
                        min_m=a[j];
                        min_dig=j;
                    }
                }
                if(a[i]+min_m<=a[x]+a[y]+del){
                    flag=false;
                    del+=(a[x]+a[y]-a[i]-min_m);
                    x=i;y=min_dig;
                }
            }
            // cout<<x<<" "<<y<<" "<<del<<"\n";
            ans.pb(x+1);
            pq.push(y);
        }
        while(!pq.empty()){
            ans.pb(pq.top()+1);
            pq.pop();
        }
        sort(rfull(ans));
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
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