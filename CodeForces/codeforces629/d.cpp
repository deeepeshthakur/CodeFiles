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

void solve(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(true){
        bool flag=true;
        for(int i=0;i<n;i++){
            if(a[i]!=a[(i+1)%n])
                flag=false;
        }
        if(flag){
            cout<<"1\n";
            for(int i=0;i<n;i++){
                cout<<"1 ";
            }
            cout<<"\n";
            return;
        }
    }

    if(true){
        vector<int> b(n,0);
        for(int i=0;i<n;i++){
            if(i==0){
                b[i]=0;
            }
            else{
                if(a[i]!=a[i-1] && b[i-1]!=2){
                    b[i]=1-b[i-1];
                }
                else{
                    b[i]=2;
                }
            }
        }
        
        if(a[0]==a[n-1] || b[n-1]==2 || b[0]!=b[n-1]){
            cout<<"2\n";
            if(n%2==0 || a[0]==a[n-1]){
                for(int i=0;i<n;i++)
                    cout<<(i%2)+1<<" ";
                cout<<"\n";
                return;
            }
            else{
                bool flag=true;
                for(int i=0;i<n;i++){
                    if(i>0 && a[i]==a[i-1])
                        flag=false;
                    if(flag){
                        cout<<(i%2)+1<<" ";
                    }
                    else{
                        cout<<2-(i%2)<<" ";
                    }
                }
                cout<<"\n";
                return;
            }

        }       
    }
    cout<<"3\n";
    for(int i=1;i<n;i++){
        cout<<(i%3)+1<<" ";
    }
    if(n%3==1){
        cout<<"3\n";
    }
    else{
        cout<<(n%3)+1<<"\n";
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