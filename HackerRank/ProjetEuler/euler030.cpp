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

void back_track(int curr_dig,long long val, int last_dig, vector<long long>& dp){
	if(curr_dig==8){
		dp.pb(val);
		return;
	}
	for(int i=last_dig;i<10;i++){
		back_track(curr_dig+1,val*10+(1ll*i),i,dp);
	}
}

bool check_validity(long long sm,long long val){
	vector<int> dig(10,0);
	while(val>0){
		dig[int(val%10)]++;
		val/=10;
	}

	while(sm>0){
		dig[int(sm%10)]--;
		sm/=10;
	}

	for(int i=1;i<10;i++)
		if(dig[i]!=0)
			return false;
	return true;
}

long long valid_sum(long long val, vector<long long>& pw){
	long long sm=0,tmp=val;
	while(tmp>0){
		sm += pw[tmp%10];
		tmp/=10;
	}
	return (check_validity(sm,val) ? sm : 0ll);
}

void solve(){
	int n;
	cin >> n;
	vector<long long> pw(10,0ll);
	for(int i=0;i<10;i++){
		pw[i]=1;
		for(int j=0;j<n;j++){
			pw[i] *= (1ll*i);
		}
	}
	long long s=0ll;
	vector<long long> dp;
	back_track(0,0ll,0,dp);
	for(int i=0;i<dp.size();i++){
		if(dp[i]!=1){
			long long tmp = valid_sum(dp[i],pw);
			// if(tmp>0)
			// 	cout << dp[i] << " " << tmp << "\n";
			s += tmp;
		}
	}
	cout << s << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}