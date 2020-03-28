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

long long pow_int(long long a, long long b){
	if(a==0)
		return 0ll;
	if(b==0)
		return 1ll;
	if(b==1)
		return a;
	long long x = pow_int(a,b/2);
	if(b%2==1)
		return x*x*a;
	return x*x;
}

long long f1(long long a,long long x){
	return (pow_int(a,x+1)-1ll)/(a-1ll);
}

void pre_calc_function(int n,vector<bool>& dp){
	vector<bool> primes(n,true);
	vector<int> abundant;
	vector<long long> sum_of_divisors(n,1ll);
	vector<vector<pair<int,int>>> factors(n);

	primes[0]=false;
	primes[1]=false;
	for(int i=2;i<n;i++){
		if(primes[i]){
			factors[i].pb({i,1});
			int j=2;
			while(1ll*j*i<1ll*n){
				primes[i*j]=false;
				int num=i*j,ctr=0;
				while(num%i==0){
					ctr++;
					num/=i;
				}
				factors[i*j].pb({i,ctr});
				j++;
			}
		}
	}

	sum_of_divisors[0]=0;
	sum_of_divisors[1]=0;
	for(int i=2;i<factors.size();i++){
		for(int j=0;j<factors[i].size();j++)
			sum_of_divisors[i]*=f1(factors[i][j].first*1ll,factors[i][j].second*1ll);
		sum_of_divisors[i]-=i*1ll;
	}

	for(int i=2;i<sum_of_divisors.size();i++)
		if(sum_of_divisors[i]>i && i>1)
			abundant.pb(i);

	for(int i=0;i<abundant.size();i++)
		for(int j=i;j<abundant.size();j++)
			if(abundant[i]+abundant[j]<dp.size())
				dp[abundant[i]+abundant[j]]=true;
}

void solve(int n,vector<bool>& dp){
	if(pre_calc){
		pre_calc=false;
		pre_calc_function(n,dp);
	}
	int t;
	cin>>t;
	if(t>28123 || dp[t])
		cout<<"YES\n";
	else
		cout<<"NO\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n=int(3e4);
	vector<bool> dp(n,false);
	int t;       
	cin >> t;
	while(t--){
		solve(n,dp);
	}
	return 0;
}