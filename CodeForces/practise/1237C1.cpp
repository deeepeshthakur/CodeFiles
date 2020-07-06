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

vector<pair<int,int>> ans;

bool cmp1(const vector<long long>& a,const vector<long long>& b){
    return (a[0]<b[0]) || (a[0]==b[0] && a[1]<b[1]) || (a[0]==b[0] && a[1]==b[1] && a[2]<=b[2]);
}

bool cmp2(const vector<long long>& a,const vector<long long>& b){
    return (a[1]<b[1]) || (a[1]==b[1] && a[0]<b[0]) || (a[1]==b[1] && a[0]==b[0] && a[2]<=b[2]);
}

bool cmp3(const vector<long long>& a,const vector<long long>& b){
    return (a[2]<b[2]) || (a[2]==b[2] && a[0]<b[0]) || (a[2]==b[2] && a[1]==b[0] && a[1]<=b[1]);
}

vector<long long> rec(int n,vector<vector<long long>>& a, int ptr,long long p, long long x, long long q, long long y, long long r, long long z){

    if(n==0) return vector<long long>{};
    if(n==1) return a[0];
    if(n==2){
        ans.pb({a[0][3],a[1][3]});
        return vector<long long>{};
    }

    vector<vector<long long>> c,d;    
    vector<long long> ans1,ans2;
    x=p=a[0][0]; q=y=a[0][1]; r=z=a[0][2];
    for(int i=0;i<n;i++){
        p=min(a[i][0],p);
        x=max(x,a[i][0]);
        q=min(a[i][1],q);
        y=max(y,a[i][1]);
        r=min(a[i][2],r);
        z=max(z,a[i][2]);
    }
    if((x==p && r==z)||(x==p && q==y)||(q==y && r==z)){
        sort(full(a),cmp1);
        for(int i=0;i+1<n;i+=2){
            ans.pb({a[i][3],a[i+1][3]});
        }
        if(n%2==1){
            vector<vector<long long>> atmp(1,a[n-1]);
            a=atmp;
            n=a.size();
        }
        else{
            a.resize(0);n=a.size();
        }
    }

    if(ptr==0){
        long long mid=(p+x)/2;
        for(int i=0;i<n;i++){
            if(p<=a[i][0] && a[i][0]<=mid) c.pb(a[i]);
            else d.pb(a[i]);
        }
        ans1=rec(c.size(),c,1,p,mid,q,y,r,z);ans2=rec(d.size(),d,1,mid+1,x,q,y,r,z);
    }
    if(ptr==1){

        long long mid=(q+y)/2;
        for(int i=0;i<n;i++){
            if(q<=a[i][1] && a[i][1]<=mid) c.pb(a[i]);
            else d.pb(a[i]);
        }
        ans1=rec(c.size(),c,2,p,x,q,mid,r,z);ans2=rec(d.size(),d,2,p,x,mid+1,y,r,z);
    }

    if(ptr==2){
        long long mid=(r+z)/2;
        for(int i=0;i<n;i++){
            if(r<=a[i][2] && a[i][2]<=mid) c.pb(a[i]);
            else d.pb(a[i]);
        }
        ans1=rec(c.size(),c,0,p,x,q,y,r,mid);ans2=rec(d.size(),d,0,p,x,q,y,mid+1,z);
    }
    if(ans1.size()==4 && ans2.size()==4){
        ans.pb({ans1[3],ans2[3]});
        return vector<long long>{};
    }
    if(ans1.size()==4) return ans1;
    return ans2;
}

void solve(){
    int n;cin>>n;
    vector<vector<long long>> pts(n,vector<long long>(4,0ll));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>pts[i][j];
        }
        // pts[i][1]=-1*i;
        // pts[i][2]=-999;
        pts[i][3]=i;
    }
    rec(n,pts,0,-1*int(1e8),int(1e8),-1*int(1e8),int(1e8),-1*int(1e8),int(1e8));
    for(int i=0;i<ans.size();i++) cout<<ans[i].first+1<<" "<<ans[i].second+1<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}