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

void print_vec(vector<int>& a,int n=-1){
    n = (n==-1 ? a.size():n);
    for(int i=0;i<n;i++)
        cout << a[i] << (i<n-1 ? " ":"\n");
}

void print_vec(vector<long long>& a,int n=-1){
    n=(n==-1 ? a.size():n);
    for(int i=0;i<n;i++)
        cout << a[i] << (i<n-1 ? " ":"\n");
}

void print_vec(vector<string>& a,int n=-1){
    n=(n==-1 ? a.size():n);
    for(int i=0;i<n;i++)
        cout << a[i] << (i<n-1 ? " ":"\n");
}

long long get_sc(int x, int y, int s, int e, int ind_0, int ind_last, vector<string>& a){
	if(x>y){
		s=ind_0;
		e=ind_last;
	}
	long long ans=0;
	for(int i=0;i<a[s].size() && i<a[e].size() && a[s][i]==a[e][i];i++)
		ans++;
	return ans;
}

void solve(int test_case){
	int n,k;
	cin>>n>>k;
	vector<string> inp(n);
	for(int i=0;i<n;i++)
		cin>>inp[i];
	sort(full(inp));
	vector<vector<int>> a(26);
	for(int i=0;i<n;i++){
		a[int(inp[i][0]-'A')].pb(i);
	}

	long long ans=0;
	int x,y;
	for(int i=0;i<26;i++){
		long long tmp_sc=0,ind_sc=0;
		if(a[i].size()>=k){
			int t=a[i].size()/k,x=0,y=a[i].size()-1,tmp_sc=get_sc(x,y,a[i][x],a[i][y],a[i][x],a[i][y],inp);
			ans+= t*tmp_sc;
			// int l=0;
			// for(;l<inp[a[i][0]].size() && l<inp[a[i][y]].size() && inp[a[i][0]][l]==inp[a[i][y]][l];l++);
			vector<long long> dp(a[i].size(),0ll);

			for(int j=dp.size()-1;j>=0;j--){
				if(j+k-1<dp.size()){
					dp[j]=get_sc(j,j+k-1,a[i][j],a[i][j+k-1],a[i][0],a[i][a[i].size()-1],inp)-tmp_sc;
				}
				long long tmp_mx=0;
				for(int z=0;z<k;z++){
					if(j+k+z<dp.size())
						tmp_mx=max(tmp_mx,dp[j+k+z]);
				}
				dp[j]+=tmp_mx;
			}
			
			ind_sc=0;
			for(int j=0;j<k;j++){
				ind_sc=max(dp[i],ind_sc);
			}
			ans+=ind_sc;
		}
	}
	cout<<"Case #"<<test_case<<": "<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int test_cases;
	cin >> test_cases;
	for(int i=1;i<=test_cases;i++){
		solve(i);
	}
	return 0;
}