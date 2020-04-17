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
    long long u,v;
    cin>>u>>v;
    if(v==0 && v==0){
        cout<<0<<"\n";
        return;
    }
    if(u<=v && (v-u)%2==0){
        if(v==u){
            cout<<"1\n"<<v<<"\n";
        }
        else{
            long long del=v-u;
            bool flag=true;
            long long l=0;
            while((1ll<<l)<=del){
                if((del&(1ll<<l))&&(u&(1ll<<(l-1)))){
                    flag=false;
                }
                l++;
            }
            if(flag){
                cout<<2<<"\n";
                l=0;
                long long tmp=u;
                while((1ll<<l)<=del){
                    if((1ll<<l)&del){
                        tmp+=(1ll<<(l-1));
                    }
                    l++;
                }
                cout<<tmp<<" "<<tmp-u<<"\n";
            }
            else{
                cout<<3<<"\n"<<u<<" "<<(v-u)/2<<" "<<(v-u)/2<<"\n";
            }
            return;
        }
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