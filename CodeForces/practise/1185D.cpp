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
    int n;cin>>n;
    vector<pair<long long,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i+1;
    }

    sort(full(a));
    if(n<4){
        cout<<1<<"\n";
        return;
    }

    bool flag=true;
    long long d=0;
    d=a[2].first-a[1].first;
    for(int i=1;i+1<n&&flag;i++){
        if(a[i].first+d!=a[i+1].first) flag=false;
    }
    if(flag){
        cout<<a[0].second<<"\n";
        return;
    }

    flag=true;
    d=a[2].first-a[0].first;
    for(int i=2;i+1<n && flag;i++)
        if(a[i].first+d!=a[i+1].first) flag=false;
    
    if(flag){
        cout<<a[1].second<<"\n";
        return;
    }

    flag=true;
    d=a[1].first-a[0].first;
    set<int> st;
    int ctr=0;
    for(int i=0;i<n;i++){
        if(a[i].first==a[0].first+ctr*d){
            ctr++;
        }
        else{
            st.insert(i);
        }
    }
    if(st.size()==1){
        int itr=*(st.begin());
        cout<<a[itr].second<<"\n";
        return;
    }
    cout<<"-1\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}