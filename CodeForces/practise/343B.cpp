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
    string s;
    cin>>s;n=s.size();
    stack<int> st;
    for(int i=0;i<n;i++){
        char x=s[i];
        if(x=='+') st.push(1);
        else st.push(0);

        if(st.size()>=2){
            int l=st.top();
            st.pop();
            if(l==st.top()){
                st.pop();
            }
            else{
                st.push(l);
            }
        }
    }
    if(st.size()>0) cout<<"No\n";
    else cout<<"Yes\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}