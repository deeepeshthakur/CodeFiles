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
    int n,k;
    cin>>n>>k;
    long long ans=1;
    vector<long long> a(n,0);
    priority_queue<long long> pos,neg;
    for(int i=0;i<n;i++){
        cin>>a[i];long long x=a[i];
        if(x>=0) pos.push(x);
        else neg.push(abs(x));
    }
    if(k==n){
        for(int i=0;i<n;i++){
            ans*=(MOD+a[i])%MOD;
            ans%=MOD;
        }
        cout<<ans<<"\n";
        return;
    }
    if(k%2==1 && pos.empty()){
        sort(rfull(a));
        for(int i=0;i<k;i++){
            ans*=(MOD+a[i])%MOD;
            ans%=MOD;
        }
    }
    else{
        if(k%2==1){
            ans*=pos.top();pos.pop();k--;
            ans%=MOD;
        }
        while(k>0){
            if(pos.size()>=2 && neg.size()>=2){
                long long p1=pos.top(),n1=neg.top();  pos.pop();neg.pop();
                long long p2=pos.top(),n2=neg.top();  pos.pop();neg.pop();
                if(p1*p2>=n1*n2){
                    ans*=((p1*p2)%MOD); ans%=MOD; k-=2;
                    neg.push(n2);
                    neg.push(n1);
                }
                else{
                    ans*=((n1*n2)%MOD);ans%=MOD; k-=2;
                    pos.push(p1);
                    pos.push(p2);
                }
            }
            else{
                if(neg.size()<2){
                    while(k>0){
                        k--;
                        ans*=pos.top();
                        ans%=MOD;
                        pos.pop();
                    }
                }
                else{
                    while(k>0){
                        k--;
                        ans*=neg.top();
                        ans%=MOD;
                        neg.pop();
                    }
                }
            }
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