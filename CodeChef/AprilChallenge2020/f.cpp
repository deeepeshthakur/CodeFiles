#include<bits/stdc++.h>
using namespace std;
void get_s1(int n, int m, int k, vector<vector<int>>& sheets, int &ans, vector<int>& v, vector<bool>& one_ans){
    int tmp=-1;
    vector<int> tmp_ans(n,1);

    for(int i=0;i<n;i++){
        if(one_ans[i]){
            tmp_ans[i]=sheets[0][i];
        }
    }

    for(int k=1;k<=m;k++){
        for(int i=0;i<n;i++){
            if(!one_ans[i]){
                tmp_ans[i]=k;
            }
        }
        tmp=n;
        for(int i=0;i<k;i++){
            int curr=0;
            for(int j=0;j<n;j++){
                if(sheets[i][j]==tmp_ans[i])
                    curr++;
            }
            tmp=min(tmp,curr);
        }
        if(ans<tmp){
            tmp=ans;
            for(int i=0;i<n;i++){
                v[i]=tmp_ans[i];
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<int>> sheets(k,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                cin>>sheets[j][i];
            }
        }

        vector<bool> one_ans(n,true);
        for(int j=0;j<n;j++){
            for(int i=1;i<k;i++){
                if(sheets[i-1][j]!=sheets[i][j]){
                    one_ans[i]=false;
                }
            }
        }

        int ans=-1;
        vector<int> ans_vec(n,1);
        get_s1(n,m,k,sheets,ans,ans_vec,one_ans);
        for(int i=0;i<n;i++){
            cout<<ans_vec[i]<<(i<n-1?" ":"\n");
        }    
    }
    return 0;
}