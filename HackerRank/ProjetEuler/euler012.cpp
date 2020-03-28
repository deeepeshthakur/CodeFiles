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
vector<long long> nth_term(max_size,0);
vector<long long> final_dp(max_size,0ll);
vector<vector<pair<int,int>>> factors(max_size);

long long total_factors(vector<pair<int,int>>& a, vector<pair<int,int>>& b){
	int x=0,y=0;
	long long total=1;
	while(x<a.size()||y<b.size()){
		if(x<a.size()&&y<b.size()){
			if(a[x].first==b[y].first){
				total *= (1ll+a[x].second+b[y].second);
				x++;
				y++;
			}
			else
				if(a[x].first>b[y].first){
					total*=(1ll+b[y].second);
					y++;
				}
				else{
					total*=(1ll+a[x].second);
					x++;
				}
		}
		else
			if(x<a.size()){
				total*=(1ll+a[x].second);
				x++;
			}
			else{
				total*=(1ll+b[y].second);
				y++;
			}
	}

	return total;
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

	for(int i=1;i<n-1;i++)
		nth_term[i]=((i%2==0)?total_factors(factors[i/2],factors[i+1]):total_factors(factors[i],factors[(i+1)/2]));
	final_dp[0]=1ll;
	for(int i=1,j=2;i<1500&&j+1<nth_term.size();i++){
		while(j<nth_term.size()-2 && i>=nth_term[j]){
			j++;
		}
		if(i<nth_term[j]){
			final_dp[i]=(j*(j+1))/2;
		}
	}
}

void solve(){
	if(pre_calc){
		pre_calc=false;
		pre_calc_function();
	}
	int t;
	cin>>t;
	cout<<final_dp[t]<<"\n";
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