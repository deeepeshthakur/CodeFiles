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

int gq(int i,int j){
    cout<<"? "<<i<<" "<<j<<endl;
    int ans=0;
    cin>>ans;
    return ans;
}

void solve(){
    int n;
    cin>>n;
    int val=-1;
    if(n*n<500){
        for(int i=1;i<=n && val==-1;i++){
            bool flag=false,is_even=false;
            for(int j=1;j<=n && !flag;j++){
                if(i!=j){
                    int qu = gq(i,j);
                    if(qu%2==0){
                        flag=true;
                        is_even=true;
                    }
                }
            }
            if(is_even){
                for(int j=1;j<=n;j++){
                    if(i!=j){
                        int qu=gq(i,j);
                        if(qu==1){
                            val=i;
                            j=n+10;
                        }
                    }
                }
            }
        }
    }
    else{
        int val=rand()%n+1;
        
    }

    vector<int> p(n,0);
    for(int i=1;i<=n;i++) if(val!=i) p[i]=gq(i,val);
    cout<<"! ";
    for(int i=0;i<n;i++) cout<<p[i]<<(i+1<n?" ":"");
    cout<<endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}