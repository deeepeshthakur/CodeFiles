#include<bits/stdc++.h>
using namespace std;

void print_vec(vector<int>& a, int n=-1){
    n=(n==-1?a.size():n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<(i<n-1?" ":"\n");
}

int main(){
    std::ios::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> a(n,0),p(n,0);
        for(int i=0;i<n;i++){
            int x;cin>>x;
            p[x-1]=i;
            a[i]=x-1;
        }
        vector<vector<int>> ans;
        set<pair<int,int>> roads;
        for(int i=0;i<n;i++){
            if(a[i]!=i){
                int x,y,z;
                x=a[i];
                if(a[x]==i){
                    roads.insert({min(i,a[i]),max(i,a[i])});
                }
                else{
                    y=a[x];
                    z=p[i];
                    //   i                  x                              z
                    //   a[i]==x           a[x]==y                        a[z]==i
                    //   i                 x                               y
                    a[i]=i;a[x]=x;a[z]=y;
                    p[i]=i;p[x]=x;p[y]=z;
                    ans.push_back(vector<int>{i,x,z});
                }
            }
        }
        // cout<<roads.size()<<" "<<ans.size()<<endl;
        if(roads.size()%2==0){
            vector<pair<int,int>> vec;
            for(auto itr=roads.begin();itr!=roads.end();++itr) vec.push_back(*itr);
            for(int i=0;i+1<vec.size();i+=2){
                int l=vec[i].first,m=vec[i].second,o=vec[i+1].first,q=vec[i+1].second;
                ans.push_back(vector<int>{l,o,m});
                ans.push_back(vector<int>{m,q,o});
            }
            if(ans.size()<=k){
                cout<<ans.size()<<"\n";
                for(int i=0;i<ans.size();i++){
                    for(int j=0;j<ans[i].size();j++){
                        cout<<ans[i][j]+1<<" ";
                    }
                    cout<<"\n";
                }
            }
            else{
                cout<<"-1\n";
            }
        }
        else
            cout<<"-1\n";
    }
    return 0;
}