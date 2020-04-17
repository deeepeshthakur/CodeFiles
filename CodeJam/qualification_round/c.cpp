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

inline bool comp(const pair<int,int>& a, const pair<int,int>& b){
    return (a.first<b.first)||(a.first==b.first && a.second<=b.second);
}

inline bool comp_v(const vector<int>& a, const vector<int>& b){
    return (a[0]<b[0])||(a[0]==b[0] && a[1]<=b[1]);
}

bool is_possible(int n, vector<pair<int,int>> a){
    sort(full(a),comp);
    bool ans=true;
    priority_queue<int,vector<int>,greater<int>> qu;
    for(int i=0;i<n;i++){
        if(!qu.empty()){
            while(!qu.empty() && qu.top()<a[i].first){
                qu.pop();
            }
        }
        qu.push(a[i].second);
        if(qu.size()>2)
            ans=false;
    }
    return ans;
}

string get_ans(int n, vector<pair<int,int>>& tmp){
    // return "Valid";
    vector<int> ans(n,-1);
    vector<vector<int>> a(n,vector<int>(3,0));
    for(int i=0;i<n;i++){
        a[i][0]=tmp[i].first;
        a[i][1]=tmp[i].second;
        a[i][2]=i;
    }
    sort(full(a),comp_v);
    int ctr=0;
    pair<int,int> b{-1,-1},c{-1,-1};
    for(int i=0;i<n;i++){
        if(ctr>0 && b.first<a[i][0]){
            if(ctr==2){
                if(c.first<a[i][0]){
                    if(ans[b.second]==-1 && ans[c.second]==-1){
                        ans[b.second]=0;
                        ans[c.second]=1;
                    }
                    else{
                        if(ans[b.second]==-1){
                            ans[b.second]=1-ans[c.second];
                        }
                        else{
                            ans[c.second]=1-ans[b.second];
                        }
                    }

                    ctr=0;
                    b={-1,-1};
                    c={-1,-1};                    
                }
                else{
                    if(ans[b.second]==-1 && ans[c.second]==-1){
                        ans[b.second]=0;
                        ans[c.second]=1;
                    }
                    else{
                        if(ans[b.second]==-1){
                            ans[b.second]=1-ans[c.second];
                        }
                        else{
                            ans[c.second]=1-ans[b.second];
                        }
                    }
                    ctr=1;
                    b={c.first,c.second};
                    c={-1,-1};
                }
            }
            else{
                if(ans[b.second]==-1){
                    ans[b.second]=0;
                }
                ctr=0;
                b={-1,-1};
                c={-1,-1};
            }
        }
        
        if(ctr==0){
            ctr=1;
            b={a[i][1],a[i][2]};
        }
        else{
            ctr=2;
            c={a[i][1],a[i][2]};
        }

        if(ctr==2 && c.first<b.first){
            swap(b,c);
        }
    }

    if(ctr>0){
        if(ctr==1){
            if(ans[b.second]==-1){
                ans[b.second]=0;
            }
        }
        else{
            if(ans[b.second]==-1 && ans[c.second]==-1){
                ans[b.second]=0;
                ans[c.second]=1;
            }
            else{
                if(ans[b.second]==-1){
                    ans[b.second]=1-ans[c.second];
                }
                else{
                    ans[c.second]=1-ans[b.second];
                }
            }
        }
    }

    string ans_str(n,'J');
    for(int i=0;i<n;i++){
        if(ans[i]==1)
            ans_str[i]='C';
    }
    return ans_str;
}

void solve(int test_case){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n,{0,0});
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
        a[i].second--;
    }
    string ans="";
    if(is_possible(n,a)){
        ans=get_ans(n,a);
    }
    else{
        ans="IMPOSSIBLE";
    }   

    cout<<"Case #"<<test_case<<": "<<ans<<"\n";
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