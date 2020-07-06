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

void print_fun(vector<string>& a){
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<"\n";
    cout<<"\n"<<endl;
}

bool get_next(vector<string>& a){
    for(int i=0;i<3;i++)
        if(a[i][0]=='s' && ((a[i].size()>1 && a[i][1]!='.')||(a[i].size()>2 && a[i][2]!='.')))
            return false;
    for(int i=0;i<3;i++)
        for(int j=0;j<a[i].size();j++)
            if(a[i][j]!='s')
                a[i][j]=(j+2<a[i].size()?a[i][j+2]:'.');

    return true;
}

bool add_next(vector<string> curr, queue<vector<string>>& qu){
    // print_fun(curr);
    bool flag=true;
    for(int i=0;i<3;i++)
        if(curr[i][0]=='s')
            for(int j=1;j<curr[i].size();j++) if(curr[i][j]!='.') flag=false;
    if(flag) return flag;

    for(int i=0;i<3;i++){
        if(curr[i][0]=='s' && curr[i][1]=='.'){
            vector<string> a=curr,b=curr,c=curr;
            for(int j=0;j<3;j++) for(int k=0;k<curr[j].size();k++) a[j][k]=b[j][k]=c[j][k]='.';
            curr[i][1]='s';
            for(int j=0;j<3;j++) for(int k=1;k<curr[j].size();k++) a[j][k-1]=b[j][k-1]=c[j][k-1]=curr[j][k];
            if(i-1>=0 && a[i-1][0]=='.'){
                a[i][0]='.';
                a[i-1][0]='s';
                if(get_next(a)) qu.push(a);
            }
            
            if(get_next(b)) qu.push(b);

            if(i+1<3 && c[i+1][0]=='.'){
                c[i][0]='.';
                c[i+1][0]='s';
                if(get_next(c)) qu.push(c);
            }
        }
    }
    return false;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<string> initial_state(3,"");
    cin>>initial_state[0]>>initial_state[1]>>initial_state[2];
    queue<vector<string>> qu;
    qu.push(initial_state);
    bool flag=true;
    set<vector<string>> st;
    while(flag&&!qu.empty()){
        if(st.find(qu.front())==st.end()) flag=(flag&&(!add_next(qu.front(),qu)));
        st.insert(qu.front());
        qu.pop();
    }
    if(flag) cout<<"NO\n";
    else cout<<"YES\n";
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