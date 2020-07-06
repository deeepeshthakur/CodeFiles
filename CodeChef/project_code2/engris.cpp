#include<bits/stdc++.h>
using namespace std;

void get_all(int ind,std::string s, std::unordered_map<std::string,int>& ht){
    for(int i=0;i<s.size();i++){
        std::string t(s.size(),'a'),t1="";
        for(int j=0;j<s.size();j++) if(i!=j) t1.push_back(s[j]); ht.insert({t1,ind});
        // for(int j=0;j<s.size();j++) t[j]=s[j];
        // for(char ch='a';ch<='z';ch++)
        //     if(ch!=s[i]){
        //         t[i]=ch;
        //         ht.insert({t,ind});
        //     }
    }
}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<string> dic(n),inp(q);
    for(int i=0;i<n;i++) cin>>dic[i];
    for(int i=0;i<q;i++) cin>>inp[i];
    std::unordered_map<std::string,int> ht;
    for(int i=0;i<n;i++){
        get_all(i,dic[i],ht);
    }
    for(int i=0;i<q;i++){
        bool flag=true;
        for(int j=0;j<n && flag;j++)
            if(dic[j]==inp[i]){
                flag=false;
                cout<<inp[i]<<"\n";
            }
        if(flag)
            if(ht.find(inp[i])==ht.end()){
                for(int j=0;j<inp[i].size();j++){
                    string sr="";
                    for(int k=0;k<inp[i].size();k++) if(k!=j) sr.push_back(inp[i][k]);
                    if(ht.find(sr)!=ht.end()){
                        cout<<dic[ht[sr]]<<"\n";
                        j=inp.size()+100;
                    }
                }
            }
            else cout<<dic[ht[inp[i]]]<<"\n";
    }
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