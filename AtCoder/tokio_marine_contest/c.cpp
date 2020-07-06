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
    int ctr=0,steps=0;
    vector<int> curr(n,0),next(n,0),tran(n,0);
    for(int i=0;i<n;i++){
        cin>>curr[i];
        ctr+=(curr[i]<n?1:0);
    }

    while(steps<k && (ctr>0)){
        ctr=0;
        int start=0,tmp=0;
        for(int i=0;i<n;i++){
            if(i-curr[i]-1>=0){
                next[i-curr[i]-1]++;
            }
            else{
                start++;
            }

            if(i+curr[i]<n) next[i+curr[i]]--;
        }
        for(int i=0;i<n;i++){
            ctr+=((curr[i]=start)<n?1:0);
            start+=next[i];
            next[i]=0;
        }
        steps++;
    }
    
    for(int i=0;i<n;i++) cout<<curr[i]<<(i+1<n?" ":"\n");
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}