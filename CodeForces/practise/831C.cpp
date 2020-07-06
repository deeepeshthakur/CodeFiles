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

bool f(vector<long long>& a, vector<long long>& b, long long x, int ind){
    vector<long long> a_temp(a.size(),0);
    for(int i=0;i<a.size();i++) a_temp[i]=(x+=a[i]);
    sort(full(a_temp));
    for(int i=0;i<b.size();i++)
        if(!binary_search(full(a_temp),b[i])) return  false;
    return true;
}

void solve(){
    int n,k;
    cin>>k>>n;
    vector<long long> a(k,0),b(n,0),pref(k,0);
    for(int i=0;i<k;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<k;i++) pref[i]=a[i]+(i>0?pref[i-1]:0);
    set<long long> st;
    for(int i=0;i<k;i++){
        if(f(a,b,b[0]-pref[i],i)) st.insert(b[0]-pref[i]);
    }
    cout<<st.size()<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}