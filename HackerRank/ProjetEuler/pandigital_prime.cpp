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

bool is_pre_calc=true;

void calc_primes(int n, vector<int>& primes){
	vector<bool> tb(n+1,true);
	tb[0]=false;
	tb[1]=false;
	for(int i=2;i<=n;i++){
		if(tb[i]){
			int j=i;
			while(1ll*j*i <= 1ll*n){
				tb[i*j]=false;
				j++;
			}
			primes.pb(i);
		}
	}
}

void find_all_per(vector<int> objects, vector<vector<int>>& per){
	per.pb(objects);
	while(next_permutation(full(objects))){
		per.pb(objects);
	}
}

void pre_calc(vector<long long>& dp){
	is_pre_calc=false;
	vector<int> primes;
	calc_primes(int(1e5),primes);
	vector<vector<int>> all_per4,all_per7;
	find_all_per(vector<int>({1,2,3,4}),all_per4);
	find_all_per(vector<int>({1,2,3,4,5,6,7}),all_per7);

	vector<long long> temp_ans(all_per4.size()+all_per7.size());
	for(int i=0;i<all_per4.size()+all_per7.size();i++){
		if(i<all_per4.size()){
			int mul=1;
			for(int j=0;j<4;j++){
				temp_ans[i] += mul*all_per4[i][j];
				mul*=10;
			}
		}
		else{
			int mul=1;
			for(int j=0;j<7;j++){
				temp_ans[i] += mul*all_per7[i-all_per4.size()][j];
				mul *= 10;
			}
		}
	}

	sort(full(temp_ans));
	for(int i=0;i<temp_ans.size();i++){
		bool is_prime=true;
		for(int j=0;j<primes.size() && 1ll*primes[j]*primes[j]<temp_ans[i];j++){
			if(temp_ans[i]%primes[j]==0){
				is_prime=false;
				break;
			}
		}
		if(is_prime){
			dp.pb(temp_ans[i]);
		}
	}

}

void solve(vector<long long>& dp){
	long long n;
	cin>>n;

	if(is_pre_calc)
		pre_calc(dp);

	long long ans=-1ll;
	for(int i=0;i<dp.size();i++){
		if(dp[i]<=n)
			ans=dp[i];
	}
	cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	vector<long long> dp;
	int t;       
	cin >> t;
	while(t--){
		solve(dp);
	}
	return 0;
}