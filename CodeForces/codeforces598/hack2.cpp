#include <bits/stdc++.h>
#define inp_out_work ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCase    int T; cin>>T; while(T--)
#define fr(i,n) for(int i=0;i<n;i++)
#define fro(i,s,e) for(int i=s;i<=e;i++)
#define endl '\n'
#define debug(P) cout<<#P<<" = "<<P<<endl;
#define pb push_back
 
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type)) 

using namespace std;
 
typedef long long ll;
 
const int MAXN = 200001;
 
int main(){
    inp_out_work
    int n, m, d;
    cin>>n>>m>>d;
    int c[m];
    fr(i,m)cin>>c[i];
 
    int ans[n];
    fill(ans, ans + n , 0);
 
   int pos = -1;
   int ptr = 0;
 
   int rem = accumulate(c, c+m, 0); // remaining plank
 
   while(pos < n && ptr < m){
            int start =  pos + d;
            if(n-start < rem){
                start = n - rem;
            }
            for(int i = start; i < start + c[ptr]; i++)ans[i] = ptr+1;
            pos = start+c[ptr]-1;
            rem -= c[ptr];
            ptr++;
   }
//debug(pos); debug(ptr);
//fr(i,n)cout<<ans[i]<<' '; debug(pos);
 
    if(pos + d < n)cout<<"NO\n";
    else {
        cout<<"YES\n";
        // fr(i,n)cout<<ans[i]<<' ';
    }
 
}