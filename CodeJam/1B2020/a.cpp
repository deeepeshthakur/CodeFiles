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

struct tp{
    long long a;
    string s;
    long long x,y;
};

struct comp{
    bool operator()(tp const& a, tp const & b){
        return a.a>b.a;
    }
};

bool bfs(tp a, long long x, long long y, set<pair<long long,long long>>& st, priority_queue<tp,vector<tp>,comp> & pq){
    int st_size=st.size();
    st.insert({a.x,a.y});
    if(st_size<st.size()){
        long long ad=1;
        if((abs(a.y) + abs(a.x))%2==1){
            tp tmp;
            tmp.s.resize(a.s.size()+1);
            for(int i=0;i<a.s.size();i++){
                tmp.s[i]=a.s[i];
            }
            tmp.a=a.a+1;
            if(abs(a.x)%2==1 && abs(a.y)%2==0){
                tmp.x=(a.x-ad)/2;tmp.y=a.y/2;tmp.s[tmp.s.size()-1]='E';pq.push(tmp);
                tmp.x=(a.x+ad)/2;tmp.y=a.y/2;tmp.s[tmp.s.size()-1]='W';pq.push(tmp);
            }
            else{
                tmp.x=a.x/2;tmp.y=(a.y+ad)/2;tmp.s[tmp.s.size()-1]='S';pq.push(tmp);
                tmp.x=a.x/2;tmp.y=(a.y-ad)/2;tmp.s[tmp.s.size()-1]='N';pq.push(tmp);
            }
        }

    }
} 

void solve(int test_case){
    long long x,y;cin>>x>>y;
    set<pair<long long,long long>> vis;
    priority_queue<tp,vector<tp>,comp> pq;
    tp a;
    a.a=0;a.s="";a.x=x;a.y=y;
    pq.push(a);
    vector<pair<long long,long long>> ans;
    while(!pq.empty()){
        a=pq.top();
        pq.pop();
        if(a.x==0 && a.y==0){
            cout<<"Case #"<<test_case<<": "<<a.s<<"\n";
            return;
        }
        else{
            bfs(a,x,y,vis,pq);
        }
    }
    cout<<"Case #"<<test_case<<": "<<"IMPOSSIBLE\n";
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