#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
const double pii=2*pi;
const double eps=1e-6;
const long long MOD=1e9+7;

bool one_f(long long p,long long q,long long r,long long a,long long b,long long c, bool f=true){
    bool ans=false;
    ans=(p==a && q==b) || (r==c && q==b) || (r==c && q==b) || ans;
    if(f){
        ans = ans || one_f(p,q,r,a,b,c,false) ||  one_f(q,r,p,b,c,a,false) || one_f(r,p,q,c,a,b,false);
    }
    long long del=a-p;
    ans = ans || ((b==q || b==q+del) && (c==r || c==r+del));
    if(p!=0 && a%p==0){
        long long m=a/p;
        ans = ans || ((b==q || b==q*m)&&(c==r || c==r*m));
    }
    if(ans){
        cout<<p<<" "<<q<<" "<<r<<" "<<a<<" "<<b<<" "<<c<<"\n";
    }
    return ans;
}

bool f1(vector<long long> x, vector<long long> y){
    long long del=y[0]-x[0];
    if(
        one_f(x[0],x[1],x[2],y[0]+del,y[1],y[2]) ||
        one_f(x[0],x[1],x[2],y[0]+del,y[1]+del,y[2]) ||
        one_f(x[0],x[1],x[2],y[0]+del,y[1],y[2]+del) ||
        one_f(x[0],x[1],x[2],y[0]+del,y[1]+del,y[2]+del)
    ) return true;

    long long m;
    if(x[0]!=0 && y[0]%x[0]==0){
        m=y[0]/x[0];
        if(
            one_f(x[0]*m,x[1],x[2],y[0],y[1],y[2]) ||
            one_f(x[0]*m,x[1]*m,x[2],y[0],y[1],y[2]) ||
            one_f(x[0]*m,x[1],x[2]*m,y[0],y[1],y[2]) ||
            one_f(x[0]*m,x[1]*m,x[2]*m,y[0],y[1],y[2])
        ) return true;
    }

    if(x[0]==x[1]) return y[0]==y[1];
    if((y[0]*x[1]-y[1]*x[0])%(x[1]-x[0])!=0) return false;
    del=(y[0]*x[1]-y[1]*x[0])/(x[1]-x[0]);
    return one_f(x[0],x[1],x[2],y[0]-del,y[1]-del,y[2]-del);

}

bool two_f(long long p,long long q,long long r,long long a,long long b,long long c){
    if(p==a || q==b || c==r) return true;
    vector<long long> x{p,q,r},y{a,b,c};
    if(f1(x,y)) return true;
    x=vector<long long>{q,p,r};
    y=vector<long long>{b,a,c};
    if(f1(x,y)) return true;
    x=vector<long long>{r,p,q};
    y=vector<long long>{c,a,b};
    if(f1(x,y)) return true;
    
    return false;
}

void solve(){
    long long a,b,c,p,q,r;
    cin>>p>>q>>r>>a>>b>>c;
    if(p==a && q==b && r==c){
        cout<<"0\n";
        return;
    }

    if(one_f(p,q,r,a,b,c,true)){
        cout<<"1\n";
        return;
    }
    if(two_f(p,q,r,a,b,c)){
        cout<<"2\n";
        return;
    }
    cout<<"3\n";
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