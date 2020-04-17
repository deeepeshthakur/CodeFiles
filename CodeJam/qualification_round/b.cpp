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

void solve(int test_case){
    string s;
    cin>>s;
    vector<int> a(s.size(),0);
    vector<pair<int,int>> br(a.size(),{0,0});
    for(int i=0;i<s.size();i++)
        a[i]=int(s[i]-'0');
    
    int n=a.size();
    for(int x=9;x>=1;x--){
        for(int i=0;i<n;i++){
            if(a[i]==x){
                int j=i;
                while(j+1<n && a[i]==a[j+1]){
                    j++;
                }
                br[i].first++;
                br[j].second++;
                for(int k=i;k<=j;k++){
                    a[k]--;
                }
                i=j;
            }
        }
    }
	cout<<"Case #"<<test_case<<": ";
	for(int i=0;i<n;i++){
		for(int j=0;j<br[i].first;j++){
			cout<<"(";
		}
		cout<<s[i];
		for(int j=0;j<br[i].second;j++){
			cout<<")";
		}
	}
	cout<<"\n";
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