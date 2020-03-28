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

bool prime_flag=true;
vector<int> primes;

void calc_primes(int n){
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

void precalc(){
	int n=int(1e6);
	calc_primes(n);
}

long long get_val(long long lim, long long m, long long g, vector<pair<long long, int>>& red){
	if(lim==0){
		if(g==m)
			return 1ll;
		else
			return 0ll;
	}

	long long ans=(lim/g)+1;
	long long tau=lim/g;
	for(int i=0;i<red.size();i++){
		ans+=red[i].second*(tau/red[i].first + 1);
	}

	return max(0ll,ans);
}

void solve(){
	if(prime_flag){
		precalc();
		prime_flag=false;
	}
	long long a,m;
	cin>>a>>m;
	long long alpha=__gcd(a,m);
	vector<long long> pfac;
	long long tmpm=m/alpha;
	for(int i=0;i<primes.size();i++){
		if(tmpm%primes[i]==0){
			pfac.pb(primes[i]);
			while(tmpm%primes[i]==0)
				tmpm/=primes[i];
		}
	}

	if(tmpm>1){
		pfac.pb(tmpm);
	}

	vector<pair<long long,int>> red;
	for(int i=0;i<pfac.size();i++){
		vector<pair<long long, int>> tmp_red;
		tmp_red.pb({pfac[i],-1});
		for(int j=0;j<red.size();j++){
			tmp_red.pb({red[j].first*pfac[i],-1*red[j].second});
		}
		for(int j=0;j<tmp_red.size();j++){
			red.pb({tmp_red[j].first,tmp_red[j].second});
		}
	}
	long long ans=get_val(a+m-1,m,alpha,red)-get_val(a-1,m,alpha,red);
	cout<<ans<<"\n";
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