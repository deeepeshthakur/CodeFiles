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

int mex(vector<int>& a){
    vector<bool> v(a.size()+10,true);
    for(int i=0;i<a.size();i++) v[a[i]]=false;
    for(int i=0;i<v.size();i++) if(v[i]) return i;
    return v.size();
}

bool is_sorted(vector<int>& a){
    for(int i=1;i<a.size();i++)
        if(a[i-1]>a[i]) return false;
    return true;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n,0),ans;
    for(int i=0;i<n;i++) cin>>a[i];
    while(true){
        if(is_sorted(a)) break;
        int tmp = mex(a);
        if(tmp==n){
            int curr=-1;
            for(int i=0;i<n;i++) if(a[i]>i) curr=i;
            for(int i=0;i<n;i++)
                if(curr==a[i]){
                    ans.push_back(i);
                    a[i]=n;
                }
        }
        else{
            ans.push_back(tmp);
            a[tmp]=tmp;
        }
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++) cout<<ans[i]+1<<" ";
    cout<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}