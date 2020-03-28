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
bool pre_calc=true;
int max_size=int(1e4)+5;
vector<int> ans(max_size,0);

int get_rec_seq(int a){
	bool flag=true;
	int set_size=1;
	set<int> rem{10};
	vector<int> rem_list{10};
	int curr=10;
	while(flag){
		curr = (curr%a)*10;
		set_size++;
		rem.insert(curr);
		if(set_size>rem.size() || curr==0)
			flag=false;
		else
			rem_list.pb(curr);
	}
	if(curr==0)
		return 0;
	int ans=0;
	for(int i=0;i<rem_list.size();i++){
		if(rem_list[i]==curr){
			ans=rem_list.size()-i;
			break;
		}
	}
	return ans;
}

void pre_calc_function(int n,vector<int>& dp){
	vector<int> rec_seq(n,0);
	rec_seq[1]=0;
	for(int i=2;i<n;i++){
		rec_seq[i]=get_rec_seq(i);
	}
	dp[0]=0;dp[1]=0;dp[2]=0;dp[3]=3;
	for(int i=4;i<n;i++)
		if(rec_seq[dp[i-1]]>=rec_seq[i])
			dp[i]=dp[i-1];
		else
			dp[i]=i;
}

void solve(){
	if(pre_calc){
		pre_calc=false;
		pre_calc_function(max_size,ans);
	}

	int n;
	cin>>n;
	cout<<ans[n-1]<<"\n";
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