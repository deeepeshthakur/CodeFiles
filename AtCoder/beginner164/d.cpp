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

void print_vec(vector<int>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

void solve(){
    string s;
    cin>>s;
    vector<int> rem(2019,0);
    rem[0]=1;
    int r=0;
    long long mul=1;
    for(int i=s.size()-1;i>=0;i--){
        r=(r)+int(s[i]-'0')*mul;
        r%=2019;
        rem[r]++;
        mul=(mul*10)%2019;
    }

    // for(int i=0;i<rem.size();i++) if(rem[i]>0) cout<<i<<" "<<rem[i]<<"\n";

    long long ans=0;
    for(int i=0;i<rem.size();i++){
        ans+=(1ll*rem[i]*rem[i]-rem[i])/2;
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