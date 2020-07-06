#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
const double pii=2*pi;
const double eps=1e-6;
const long long MOD=1e9+7;

bool tf(long long a,long long b){
    return (abs(a)%abs(b)==0);
}

bool f(vector<long long> x, vector<long long> y){
    long long del=y[0]-x[0];
    bool flag=true;
    for(int i=0;i<3;i++) flag=flag&&(x[i]==y[i] || x[i]+del==y[i]);
    if(flag) return flag;
    if(x[0]==0 || x[0]*0==y[0]){
        flag=false;
        for(int i=0;i<3;i++) flag=flag&&(x[i]==y[i] || x[i]*0==y[i]);
    }
    else{
        flag=false;
        if(tf(y[0],x[0])){
            long long m=y[0]/x[0];
            for(int i=0;i<3;i++) flag=flag&&(x[i]==y[i] || x[i]*m==y[i]);
        }
    }
    return flag;
}

bool one_f(vector<long long> x, vector<long long> y){
    for(int i=0;i<3;i++) for(int j=i+1;j<3;j++) if(x[i]==y[i] && x[j]==y[j]) return true;
    bool flag=false;
    for(int i=0;i<3;i++){
        vector<long long> a,b;
        for(int j=i;j<i+3;j++){
            a.push_back(x[j%3]);
            b.push_back(y[j%3]);
        }
        flag=(flag||f(a,b));
    }
    return flag;
}

bool f1(vector<long long> x, vector<long long> y){
    // Addition
    long long del=y[0]-x[0];
    bool flag=one_f(vector<long long>{x[0]+del,x[1],x[2]},y) ||
              one_f(vector<long long>{x[0]+del,x[1]+del,x[2]},y) ||
              one_f(vector<long long>{x[0]+del,x[1],x[2]+del},y) ||
              one_f(vector<long long>{x[0]+del,x[1]+del,x[2]+del},y) ||
              one_f(x,vector<long long>{y[0]-del,y[1]-del,y[2]}) ||
              one_f(x,vector<long long>{y[0]-del,y[1],y[2]-del}) ||
              one_f(x,vector<long long>{y[0]-del,y[1]-del,y[2]-del});

    if(flag) return flag;

    // Multiplication
    if(x[0]==0 || x[0]*0==y[0]){
        flag=false;
        flag=one_f(vector<long long>{x[0]*0,x[1],x[2]},y) ||
             one_f(vector<long long>{x[0]*0,x[1]*0,x[2]},y) ||
             one_f(vector<long long>{x[0]*0,x[1],x[2]*0},y) ||
             one_f(vector<long long>{x[0]*0,x[1]*0,x[2]*0},y);
    }
    else{
        flag=false;
        if(tf(y[0],x[0])){
            long long m=y[0]/x[0];
            flag=one_f(vector<long long>{x[0]*m,x[1],x[2]},y) ||
                one_f(vector<long long>{x[0]*m,x[1]*m,x[2]},y) ||
                one_f(vector<long long>{x[0]*m,x[1],x[2]*m},y) ||
                one_f(vector<long long>{x[0]*m,x[1]*m,x[2]*m},y);
        }
    }
    if(flag) return flag;

    // Multiplication && Addition
    if(x[0]==x[1]) return y[0]==y[1];
    if(!tf(y[0]-y[1],x[0]-x[1])) return false;
    long long m=(y[0]-y[1])/(x[0]-x[1]);
    return one_f(vector<long long>{x[0]*m,x[1]*m,x[2]*m},y);
}


bool two_f(vector<long long> x, vector<long long> y){
    for(int i=0;i<3;i++) if(x[i]==y[i]) return true;
    bool flag=false;
    for(int i=0;i<3;i++){
        vector<long long> a,b;
        for(int j=i;j<i+3;j++){
            a.push_back(x[j%3]);
            b.push_back(y[j%3]);
        }
        flag=(flag||f1(a,b));
    }
    return flag;
}

void solve(){
    long long a,b,c,p,q,r;
    cin>>p>>q>>r>>a>>b>>c;
    if(p==a && q==b && r==c){
        cout<<"0\n";
        return;
    }
    vector<long long> x{p,q,r},y{a,b,c};
    if(one_f(x,y)){
        cout<<"1\n";
        return;
    }
    if(two_f(x,y)){
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