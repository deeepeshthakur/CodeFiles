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

bool final_check(int n,vector<pair<string,string>>& q, string& s){

}

string check_for(int n,vector<pair<string,string>>& q, vector<string>& ch, int curr, string str){
    cout<<curr<<" "<<str<<endl;
    if(curr>9){
        bool flag=final_check(n,q,str);
        if(flag) return str;
        return "";
    }
    for(int i=0;i<ch[curr].size();i++){
        bool flag=true;
        for(int j=0;j<curr;j++) if(ch[curr][i]==str[j]) { flag=false;j=100;}
        if(flag){
            string nw=str;
            nw.pb(ch[curr][i]);
            nw=check_for(n,q,ch,curr+1,nw);
            if(nw.size()>0) return nw;
        }
    }
    return "";
}

void solve(int test_case){
    int u;cin>>u;
    long long lim=1;
    while(u--) lim*=10;
    lim-=1;

    vector<pair<string,string>> qu(int(1e4));
    for(int i=0;i<qu.size();i++){
        long long x;
        cin>>x>>qu[i].second;
        if(x==-1) x=lim;
        string s;
        while(x){
            s.pb(char(x%10+'0'));
            x/=10;
        }
        for(int j=0;j<s.size();j++){
            if(s.size()-1-j>j) swap(s[j],s[s.size()-1-j]);
        }
        qu[i].first=s;
    }


    set<char> st;
    int n=int(1e4);
    for(int i=0;i<qu.size();i++){
        for(int j=0;j<qu[i].second.size();j++){
            st.insert(qu[i].second[j]);
        }
    }

    string valid_chars;
    for(auto itr=st.begin();itr!=st.end();itr++){
        valid_chars.pb(*itr);
    }

    vector<pair<int,int>> min_max(26,{0,9});
    vector<bool> confirm(10,false);
    vector<char> confirm_val(10,'a');
    vector<string> choices_for_dig(10,string(10,'1'));
    for(int i=0;i<n;i++){
        string r=qu[i].first,l=qu[i].second;
        if(r.size()==l.size()){
            if(r[0]=='1'){
                confirm[1]=true;
                confirm_val[i]=r[0];
                min_max[int(l[0]-'A')]={1,1};
                bool flag=true;
                for(int i=1;i<r.size();i++) if(r[i]!=0) flag=false;
                if(flag){
                    if(r.size()>1){
                        confirm[0]=true;
                        confirm_val[0]=r[1];
                    }
                }
            }
            else{
                min_max[int(l[0]='A')].first=max(min_max[int(l[0]='A')].first,1);
                min_max[int(l[0]='A')].second=min(int(r[0]-'0'),min_max[int(l[0]='A')].second);
            }
        }
        else{
            min_max[int(l[0]-'A')].first=max(min_max[int(l[0]-'A')].first,1);
            min_max[int(l[0]-'A')].second=min(9,min_max[int(l[0]-'A')].second);
        }
    }
    for(int i=0;i<10;i++){
        if(confirm[i]){
            min_max[int(confirm_val[i]-'A')]={i,i};
        }
    }

    cout<<"Hrer"<<endl;
    for(int i=0;i<valid_chars.size();i++){
        char xx=valid_chars[i];
        cout<<xx<<" "<<min_max[int(xx-'A')].first<<" "<<min_max[int(xx-'A')].second<<endl;
        int ctr=0;
        for(int j=min_max[int(xx-'A')].first;j<=min_max[int(xx-'A')].second;j++){
            cout<<j<<endl;
            cout<<choices_for_dig.size()<<" "<<choices_for_dig[j].size()<<endl;

            choices_for_dig[j][ctr]=xx;
            ctr++;
            cout<<j<<endl;
        }
        cout<<"here also"<<endl;
    }
    cout<<"Here"<<endl;
    for(int i=0;i<confirm.size();i++){
        if(confirm[i]){
            choices_for_dig[i].resize(1);
            choices_for_dig[i][0]=confirm_val[i];
        }
    }

    cout<<"hrer"<<endl;

    string ans=check_for(n,qu,choices_for_dig,0,"");
    vector<bool> vis(26,true);
    for(int i=0;i<ans.size();i++) if(ans.size()!='0') vis[int(ans[i]-'A')]=false;
    for(int i=0;i<ans.size();i++){
        if(ans[i]=='0'){
            for(int j=0;j<vis.size();j++)
                if(vis[j]){
                    vis[j]=false;
                    ans[i]=char('A'+j);
                    j=50;
                }
        }
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