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

int max_size = int(1e5)+1;
bool pre_calc=true;
vector<bool> primes(max_size,true);
vector<long long> sum_of_divisors(max_size,1ll);
vector<bool> valid_pair(max_size,false);
vector<int> dp(max_size,0);
vector<vector<pair<int,int>>> factors(max_size);

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

void pre_calc_function(){
	int n=max_size;
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

	for(int i=2;i<sum_of_divisors.size();i++){
		if(sum_of_divisors[i]<sum_of_divisors.size() && i*1ll!=sum_of_divisors[i] && sum_of_divisors[int(sum_of_divisors[i])]==1ll*i){
			valid_pair[i]=true;
		}
	}

	for(int i=0;i<dp.size();i++)
		dp[i]=(valid_pair[i]?(i):0)+(i>0?dp[i-1]:0);
}

void solve(){
	if(pre_calc){
		pre_calc=false;
		pre_calc_function();
	}
	int t;
	cin>>t;
	cout<<dp[t-1]<<"\n";
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