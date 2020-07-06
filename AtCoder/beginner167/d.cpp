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
    long long k;
    cin>>n>>k;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) {cin>>a[i];a[i]--;}
    queue<int> qu;
    int curr=a[0];
    set<int> st;curr=0;
    while(st.find(curr)==st.end()){
        st.insert(curr);
        curr=a[curr];
    }
    qu.push(curr);curr=a[curr];
    while(curr!=qu.front()){
        qu.push(curr);
        curr=a[curr];
    }
    curr=0;
    while(curr!=qu.front() && k>0){
        k--;
        curr=a[curr];
    }
    if(k==0){
        cout<<curr+1<<"\n";
        return;
    }
    k=(k%qu.size());
    while(k--) qu.pop();
    cout<<qu.front()+1<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}