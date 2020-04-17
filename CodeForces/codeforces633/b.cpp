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
    int n;
    cin>>n;
    vector<long long> a(n,0ll);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(full(a));
    int i=0,j=n-1,k=0;
    vector<long long> b(n,0ll);
    while(i<=j){
        if(k<n){
            b[k]=a[j];
            k++;
            j--;
        }
        if(k<n && i<=j){
            b[k]=a[i];
            k++;
            i++;;
        }
    }
    for(int i=n-1;i>=0;i--){
        cout<<b[i]<<" ";
    }
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