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

inline int win_lose(int a, int b){
	return ((b==0 && a==1) || (b==1 && a==2) || (b==2 && a==0));
}

long long get_max(int n, vector<int>& t, long long r, long long p, long long s){
	// print_vec(t);
	vector<vector<long long>> dp(n,vector<long long>(3,0ll));
	vector<long long> sc{r,p,s};
	dp[0][0]=sc[0]*win_lose(0,t[0]);
	dp[0][1]=sc[1]*win_lose(1,t[0]);
	dp[0][2]=sc[2]*win_lose(2,t[0]);
	long long tmp=0;
	for(int i=1;i<n;i++){
		for(int j=0;j<3;j++){
			tmp=0;
			for(int k=0;k<3;k++)
				if(j!=k)
					tmp=max(tmp,dp[i-1][k]);
			dp[i][j]=(sc[j]*win_lose(j,t[i]))+tmp;
		}
	}
	// for(int i=0;i<n;i++){
	// 	print_vec(dp[i]);
	// }
	return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
}

void solve(){	
	int n,k;
	long long r,s,p;
	string t;
	cin>>n>>k;
	cin>>r>>s>>p;
	cin>>t;
	long long ans=0;
	for(int i=0;i<k;i++){
		vector<int> curr_s;
		for(int j=0;j*k+i<n;j++){
			if(t[j*k+i]=='r')
				curr_s.pb(0);
			if(t[j*k+i]=='p')
				curr_s.pb(1);
			if(t[j*k+i]=='s')
				curr_s.pb(2);
		}
		ans+=get_max(curr_s.size(),curr_s,r,p,s);
	}
	cout<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}