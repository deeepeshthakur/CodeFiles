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

void f(stack<pair<int,int>>& q, pair<int,int> a){
    while(!q.empty() && a.first<q.top().first && q.top().second<a.second) q.pop();
    if(!q.empty() && q.top().second+1==a.first){
        q.top().second=a.second;
    }
    else q.push(a);
}

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    stack<pair<int,int>> q;
    stack<int> st;
    for(int i=0;i<n;i++)
        if(s[i]=='('){
            st.push(i);
        }
        else
            if(!st.empty()){
                f(q,{st.top(),i});
                st.pop();
                }
    int mx=0,cnt=1;
    while(!q.empty()){
        auto a=q.top();q.pop();
        if(a.second-a.first+1>mx){
            mx=a.second-a.first+1;
            cnt=1;
        }
        else{
            if(a.second-a.first+1==mx) cnt++;
        }
    }
    cout<<mx<<" "<<cnt<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}