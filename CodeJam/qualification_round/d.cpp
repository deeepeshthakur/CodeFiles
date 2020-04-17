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

int query(int i){
    cout<<i+1<<endl;
    cin>>i;
    return i;
}

void p1(int n, vector<int>& a){
    for(int i=0;i<n;i++){
        if(a[i]!=-1){
            a[i]=1-a[i];
        }
    }
}

void p2(int n, vector<int>& a){
    for(int i=0;i<n;i++){
        if(i<n-1-i){
            swap(a[i],a[n-i-1]);
        }
    }
}

void solve(int test_case, int b_input){
    vector<int> ans(b_input,-1);
    int a=0,b=0,c=0,d=0;
    pair<int,int> zz,zo,oz,oo;
    queue<pair<int,int>> unknown;
    for(int i=0;i<b_input;i++){
        if(i<b_input-1-i){
            unknown.push({i,b_input-1-i});
        }
    }

    for(int i=0;i<150;){
        if(a>0 || b>0 || c>0 || d>0){
            if((a>0 || d>0) && (b>0 || c>0)){
                if(a>0){
                    if(b>0){
                        int l=query(zz.first),r=query(zo.first);
                        if(l==0 && r==1){
                            p2(b_input,ans);
                        }
                        if(l==1 && r==0){
                            p1(b_input,ans);
                            p2(b_input,ans);
                        }
                        if(l==1 && r==1){
                            p1(b_input,ans);
                        }
                    }
                    else{
                        int l=query(zz.first),r=query(oz.first);
                        if(l==0 && r==0){
                            p2(b_input,ans);
                        }
                        if(l==1 && r==0){
                            p1(b_input,ans);
                        }
                        if(l==1 && r==1){
                            p1(b_input,ans);
                            p2(b_input,ans);
                        }

                    }
                }
                else{
                    if(b>0){
                        int l=query(oo.first),r=query(zo.first);
                        if(l==0 && r==0){
                            p1(b_input,ans);
                            p2(b_input,ans);
                        }

                        if(l==0 && r==1){
                            p1(b_input,ans);
                        }

                        if(l==1 && r==1){
                            p2(b_input,ans);
                        }
                    }
                    else{
                        int l=query(oo.first),r=query(oz.first);
                        if(l==0 && r==0){
                            p1(b_input,ans);
                        }

                        if(l==0 && r==1){
                            p1(b_input,ans);
                            p2(b_input,ans);
                        }

                        if(l==1 && r==0){
                            p2(b_input,ans);
                        }
                    }
                }
            }
            else{
                if(a>0 || d>0){
                    if(a>0){
                        int l=query(zz.first),r=query(zz.second);
                        if(l==1 && r==1){
                            p1(b_input,ans);
                        }
                    }
                    else{
                        int l=query(oo.first),r=query(oo.second);
                        if(l==0 && r==0){
                            p1(b_input,ans);
                        }
                    }
                }
                else{
                    if(b>0){
                        int l=query(zo.first),r=query(zo.second);
                        if(l==1 && r==0){
                            p1(b_input,ans);
                        }
                    }
                    else{
                        int l=query(oz.first),r=query(oz.second);
                        if(l==0 && r==1){
                            p1(b_input,ans);
                        }
                    }
                }
            }
            i+=2;
        }
        while(!unknown.empty() && (i==0 || i%10!=0)){
            int l=unknown.front().first,r=unknown.front().second,x=query(l),y=query(r);
            i+=2;
            ans[l]=x;
            ans[r]=y;
            unknown.pop();
        }

        if(unknown.empty()){
            break;
        }
        a=0;b=0;c=0;d=0;
        zz={-1,-1};zo={-1,-1};oz={-1,-1},oo={-1,-1};
        for(int i=0;i<b_input-1-i;i++){
            if(ans[i]==0 && ans[b_input-i-1]==0 && a==0){
                a=1;
                zz={i,b_input-i-1};
            }

            if(ans[i]==0 && ans[b_input-i-1]==1 && b==0){
                b=1;
                zo={i,b_input-i-1};
            }

            if(ans[i]==1 && ans[b_input-i-1]==0 && c==0){
                c=1;
                oz={i,b_input-i-1};
            }

            if(ans[i]==1 && ans[b_input-i-1]==1 && d==0){
                d=1;
                oo={i,b_input-i-1};
            }
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    cout<<endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t,b;
    cin >> t >> b;
    for(int i=1;i<=t;i++){
        solve(i,b);
        char x;
        cin>>x;
        if(x!='Y'){
            return 0;
        }
    }
    return 0;
}