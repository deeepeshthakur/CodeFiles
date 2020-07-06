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

void print_vec(vector<long long>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

string rev(string s){
    for(int i=0;i*2<int(s.size())-1;i++) {
        swap(s[i],s[s.size()-1-i]);
    }
    return s;
}

bool check_hash(int l, int rind, vector<vector<long long>>& ht, vector<vector<long long>>& rht, vector<vector<long long>>& p){
    // cout<<l<<" "<<rind<<endl;
    vector<long long> a,b;
    for(int i=0;i<3;i++) a.push_back((ht[i][l-1]*(rind>0?p[i][rind-1]:1ll))%MOD);
    for(int i=0;i<3;i++) b.push_back((MOD + rht[i][rind+l-1]-(rind>0?rht[i][rind-1]:0ll))%MOD);
    // print_vec(a);print_vec(b);cout<<"\n";
    for(int i=0;i<3;i++) if(a[i]!=b[i]) return false;
    return true;
}

bool tf(int len, string& s, string& r, vector<vector<long long>>& ht, vector<vector<long long>>& rht, vector<vector<long long>>& p){
    bool flag=false;
    if(len%2==0){
        int l1=s.size()-len;
        flag=check_hash(len/2,l1,ht,rht,p);
    }
    else{
        int l1=s.size()-len;
        flag=check_hash((len+1)/2,l1,ht,rht,p);
    }

    if(flag){
        for(int i=0;i*2<len-1;i++) if(s[i]!=s[len-i-1]) return false;
        return true;
    }
    return false;
}

string f1(string s){
    int n=s.size();
    vector<vector<long long>> hast_t(3,vector<long long>(n,1ll)),ht(3,vector<long long>(n,0)),rht(3,vector<long long>(n,0));
    hast_t[0][0]=31;
    hast_t[1][0]=37;
    hast_t[2][0]=41;
    for(int i=0;i<3;i++) for(int j=1;j<n;j++) hast_t[i][j]=(hast_t[i][0]*hast_t[i][j-1])%MOD;
    for(int i=0;i<3;i++) for(int j=0;j<n;j++) ht[i][j]=(hast_t[i][j]*int(s[j]-'a'+1)+(j>0?ht[i][j-1]:0ll))%MOD;
    string r=rev(s);
    for(int i=0;i<3;i++) for(int j=0;j<n;j++) rht[i][j]=(hast_t[i][j]*int(r[j]-'a'+1)+(j>0?rht[i][j-1]:0ll))%MOD;
    int l=0;
    // cout<<s<<" "<<r<<"\n";
    for(int i=s.size();i>0;i--) if(tf(i,s,r,ht,rht,hast_t)){
        l=i;
        i=-1;
    }
    string ans;
    for(int i=0;i<l;i++) ans.pb(s[i]);
    // cout<<ans<<"\n";
    return ans;
}

string f(string t){
    if(t.size()<=1) return t;
    string a=f1(t),b=rev(f1(rev(t)));
    if(a.size()<b.size()) return b;
    return a;
}

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    int i=-1;
    while(i+1<n-i-2 && s[i+1]==s[n-1-i-1]) i++;
    string tmp;
    for(int j=i+1;j<n-i-1;j++) tmp.pb(s[j]);
    tmp=f(tmp);
    string ans;
    for(int j=0;j<=i;j++) ans.pb(s[j]);
    // cout<<ans<<"\n";
    for(int j=0;j<tmp.size();j++) ans.pb(tmp[j]);
    // cout<<ans<<"\n";
    for(int j=n-i-1;j<n;j++) ans.pb(s[j]);
    cout<<ans<<"\n";
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