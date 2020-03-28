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
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        int x,y,z,w;
        cin>>w>>x>>y>>z;
    }
    if(n==1 && m==1){
        cout<<"1\nD\n";
        return;
    }

    if(n==1 || m==1){
        if(n==1){
            cout<<2*m<<"\n";
            for(int i=0;i<m;i++){
                cout<<"L";
            }
            for(int i=0;i<m;i++){
                cout<<"R";
            }
            cout<<"\n";            
        }
        else{
            cout<<2*n<<"\n";
            for(int i=0;i<n;i++){
                cout<<"D";
            }
            for(int i=0;i<n;i++){
                cout<<"U";
            }
            cout<<"\n";        
        }
        return;
    }

    vector<char> steps;
    for(int i=0;i<n-1;i++){
        steps.pb('U');
    }
    for(int i=0;i<m-1;i++){
        steps.pb('L');
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i%2==0){
                steps.pb('R');
            }
            else{
                steps.pb('L');
            }
        }
        steps.pb('D');
    }
    cout<<steps.size()<<"\n";
    for(int i=0;i<steps.size();i++)
        cout<<steps[i];
    cout<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}