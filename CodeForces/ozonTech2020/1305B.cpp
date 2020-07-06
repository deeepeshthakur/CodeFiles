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
    cin>>s;
    n=s.size();
    queue<int> q1,q2;
    for(int i=0;i<n;i++) if(s[i]=='(') q1.push(i+1);
    for(int i=n-1;i>=0;i--) if(s[i]==')') q2.push(i+1);
    vector<vector<int>> v;
    bool flag=true;
    while(flag){
        flag=false;
        vector<int> tmp;
        while(!q1.empty() && !q2.empty() && q1.front()<q2.front()){
            tmp.push_back(q1.front());
            tmp.push_back(q2.front());
            q1.pop();
            q2.pop();
        }
        if(tmp.size()>0){
            flag=true;
            v.push_back(tmp);
        }
    }
    cout<<v.size()<<"\n";
    for(int i=0;i<v.size();i++){
        cout<<v[i].size()<<"\n";
        sort(full(v[i]));
        for(int j=0;j<v[i].size();j++) cout<< v[i][j] << " ";cout<<"\n";
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}