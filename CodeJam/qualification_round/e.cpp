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

int is_possible(int s, int n,int k){
    for(int i=1;i<=n;i++){
        if(s-i>=1 && s-i<=n && i!=s-i && i!=k && s-i!=k)
            return i;
    }
    return 0;
}

void solve(int test_case){
    int n,k;
    cin>>n>>k;
    bool flag=false;
    vector<vector<int>> ans(n,vector<int>(n,0));
    if(n<4){
        if(n==2){
            if(k==2){
                flag=true;
                ans[0][0]=1;
                ans[0][1]=2;
                ans[1][0]=2;
                ans[1][1]=1;
            }

            if(k==4){
                flag=true;
                ans[0][0]=2;
                ans[0][1]=1;
                ans[1][0]=1;
                ans[1][1]=2;
            }
        }
        else{
            if(k==3){
                flag=true;
                ans={{1,2,3},{3,1,2},{2,3,1}};
            }
            if(k==6){
                flag=true;
                ans={{2,3,1},{1,2,3},{3,1,2}};
            }
            if(k==9){
                flag=true;
                ans={{3,2,1},{1,3,2},{2,1,3}};
            }
        }
    }
    else
        if(k!=n+1 || k!=n*n-1 || (n%2==1 && (k!=n+2 || k!=n*n-2))){
            if(n%2==0 && (k==n+2 || k==n*n-2)){
                flag=true;
                vector<int> tmp(n,0);
                if(k==n+2){
                    tmp[0]=1;
                    tmp[n/2]=2;
                    int ctr=3;
                    for(int i=0;i<n;i++){
                        if(tmp[i]==0){
                            tmp[i]=ctr;
                            ctr++;
                        }
                    }
                }
                else{
                    tmp[0]=n;
                    tmp[n/2]=n-1;
                    int ctr=1;
                    for(int i=0;i<n;i++){
                        if(tmp[i]==0){
                            tmp[i]=ctr;
                            ctr++;
                        }
                    }
                }

                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        ans[i][(i+j)%n]=tmp[j];
                    }
                }
                for(int j=0;j<n;j++){
                    swap(ans[0][j],ans[n/2][j]);
                }
            }
            else{
                for(int i=1;i<=n && !flag;i++){
                    if(k%n==0){
                        flag=true;
                        ans[0][0]=k/n;
                        int ctr=1;
                        for(int j=1;j<n;j++){
                            if(ctr==k/n){
                                ctr++;
                            }
                            if(ans[0][j]==0){
                                ans[0][j]=ctr;
                                ctr++;
                            }
                        }
                        for(int k=1;k<n;k++){
                            for(int j=0;j<n;j++){
                                ans[k][(k+j)%n]=ans[0][j];
                            }
                        }

                    }
                    else{
                        if(k-n*i+2*i>0 && is_possible(k-n*i+2*i,n,i)!=0){
                            int a=is_possible(k-n*i+2*i,n,i),b=k-n*i+2*i-a;
                            flag=true;
                            ans[0][0]=i;
                            ans[0][1]=a;
                            ans[0][n-1]=b;
                            int ctr=1;
                            for(int j=2;j<n-1;j++){
                                while(ctr==i || ctr==a ||ctr==b){
                                    ctr++;
                                }
                                if(ans[0][j]==0){
                                    ans[0][j]=ctr;
                                    ctr++;
                                }
                            }
                            for(int k=1;k<n;k++){
                                for(int j=0;j<n;j++){
                                    ans[k][(k+j)%n]=ans[0][j];
                                }
                            }

                            for(int j=0;j<n;j++){
                                swap(ans[0][j],ans[1][j]);
                            }
                        }
                    }

                }
            }
        }
    if(flag){
        cout<<"Case #"<<test_case<<": POSSIBLE\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    else{
        cout<<"Case #"<<test_case<<": IMPOSSIBLE\n";
    }
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