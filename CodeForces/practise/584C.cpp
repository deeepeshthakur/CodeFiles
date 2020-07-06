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
    int n,t;cin>>n>>t;
    string x,y;
    cin>>x>>y;
    int ctr=0;
    for(int i=0;i<n;i++) if(x[i]!=y[i]) ctr++;
    if(t>ctr){
        t-=ctr;
        string ans=x;
        for(int i=0;i<n;i++){
            if(x[i]!=y[i]){
                char xx='a';
                while(xx==x[i] || xx==y[i]) xx++;
                ans[i]=xx;
            }
            else{
                if(t>0){
                    char xx='a';
                    while(xx==x[i]) xx++;
                    ans[i]=xx;
                    t--;
                }
                else{
                    ans[i]=x[i];
                }
            }
        }
        cout<<ans<<"\n";
        return;
    }
    else{
        int a=0;
        for(a=0;a<ctr;a++){
            if(2*a<=ctr && ctr-a==t){
                break;
            }
        }
        if(!(2*a<=ctr && ctr-a==t)){
            cout<<"-1\n";
            return;
        }
        a*=2;
        string ans=x;
        for(int i=0;i<n;i++){
            if(x[i]==y[i]) ans[i]=x[i];
            else{
                if(a>0){
                    if(a%2==0){
                        ans[i]=x[i];
                        a--;
                    }
                    else{
                        ans[i]=y[i];
                        a--;
                    }
                }
                else{
                    char xx='a';
                    while(x[i]==xx || y[i]==xx) xx++;
                    ans[i]=xx;
                }
            }
        }
        cout<<ans<<"\n";
        return;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}