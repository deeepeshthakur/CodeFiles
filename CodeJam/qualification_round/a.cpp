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

void solve(int test_case){
    int n,sm;
    cin>>n;
    sm=(n*n+n)/2;
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>dp[i][j];
    
    int k=0,r=0,c=0;
    for(int i=0;i<n;i++)
        k+=dp[i][i];
    
    for(int i=0;i<n;i++){
        int tmp=0;
        set<int> st;
        for(int j=0;j<n;j++){
            tmp+=dp[i][j];
            st.insert(dp[i][j]);
        }
        if(tmp!=sm || st.size()!=n)
            r++;
    }

    for(int i=0;i<n;i++){
        int tmp=0;
        set<int> st;
        for(int j=0;j<n;j++){
            tmp+=dp[j][i];
            st.insert(dp[j][i]);
        }
        if(tmp!=sm || st.size()!=n)
            c++;
    }

    cout<<"Case #"<<test_case<<": "<<k<<" "<<r<<" "<<c<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}