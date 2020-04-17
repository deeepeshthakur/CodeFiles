#include<bits/stdc++.h>

using namespace std;
const long long MOD=998244353ll;

long long powern(long long a, long long b){
    if(a==0)
        return 0ll;
    if(b==0)
        return 1ll;
    if(b==1)
        return a;
    long long x=powern(a,b/2);
    x=(x*x)%MOD;
    if(b%2==1){
        return (x*a)%MOD;
    }
    return x;
}

class frac_mod {
    long long n,d;
    public:
        // frac_mod(){n=0ll;d=1ll;}
        frac_mod(long long ni=0, long long di=1){n=ni;d=di;}
        frac_mod(const frac_mod &i){n=i.n;d=i.d;}
        void print_f(){
            cout<<(n*powern(d,MOD-2))%MOD;
        }
    friend frac_mod operator + (frac_mod const &, frac_mod const &);
    friend frac_mod operator * (frac_mod const &, frac_mod const &);
};

frac_mod operator + (frac_mod const &a, frac_mod const &b){
    return frac_mod(((a.n*b.d)%MOD+(b.n*a.d)%MOD)%MOD,(a.d*b.d)%MOD);
}

frac_mod operator * (frac_mod const &a, frac_mod const &b){
    return frac_mod((a.n*b.n)%MOD,(a.d*b.d)%MOD);
}

int eval_rec(vector<frac_mod>& a, int n, int l, string& s){
    if(s[l]=='('){
        vector<frac_mod> e(4),f(4);
        char oper;
        int r=eval_rec(e,n,l+1,s);
        oper=s[r];
        r=eval_rec(f,n,r+1,s);
        if(oper=='&'){
            a[0]=(e[0]*(f[0]+f[1]+f[2]+f[3]))+(f[0]*(e[1]+e[2]+e[3]))+(e[2]*f[3])+(e[3]*f[2]);
            a[1]=e[1]*f[1];
            a[2]=(e[1]*f[2])+(e[2]*f[1])+(e[2]*f[2]);
            a[3]=(e[1]*f[3])+(e[3]*f[1])+(e[3]*f[3]);
        }

        if(oper=='|'){
            a[0]=e[0]*f[0];
            a[1]=(e[1]*(f[0]+f[1]+f[2]+f[3]))+(f[1]*(e[0]+e[2]+e[3]))+(e[2]*f[3])+(e[3]*f[2]);
            a[2]=(e[0]*f[2])+(e[2]*f[0])+(e[2]*f[2]);
            a[3]=(e[0]*f[3])+(e[3]*f[0])+(e[3]*f[3]);
        }

        if(oper=='^'){
            a[0]=(e[0]*f[0])+(e[1]*f[1])+(e[2]*f[2])+(e[3]*f[3]);
            a[1]=(e[0]*f[1])+(e[1]*f[0])+(e[2]*f[3])+(e[3]*f[2]);
            a[2]=(e[0]*f[2])+(f[0]*e[2])+(e[1]*f[3])+(f[1]*e[3]);
            a[3]=(e[0]*f[3])+(f[0]*e[3])+(e[1]*f[2])+(f[1]*e[2]);
        }

        if(s[r]==')')
            r++;
        return r;
    }
    else{
        a.resize(4);
        for(int i=0;i<4;i++){
            a[i]=frac_mod(1ll,4ll);
        }        
        return l+1;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin>>s;
        vector<frac_mod> ans(4,{0ll,1ll});
        eval_rec(ans,s.size(),0,s);
        for(int i=0;i<ans.size();i++){
            ans[i].print_f();
            if(i<ans.size()-1)
                cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}