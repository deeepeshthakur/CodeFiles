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

void solve(vector<int>& primes){
	int n;
	cin>>n;
	int a,b,c,ntmp=n;
	vector<int> fact,ctr;
	for(int i=0;primes[i]<=int(1e5);i++){
		if(n%primes[i]==0){
			int x=0;
			while(n%primes[i]==0){
				x++;
				n/=primes[i];
			}
			fact.pb(primes[i]);
			ctr.pb(x);
		}
	}
	if(n>1){
		fact.pb(n);
		ctr.pb(1);
	}
	if(fact.size()>=3){
		a=fact[0];
		b=fact[1];
		c=ntmp/(a*b);
		cout<<"YES\n";
		cout<<a<<" "<<b<<" "<<c<<"\n";
	}
	else{
		if(fact.size()==2&&ctr[0]+ctr[1]>=4){
			a=fact[0];
			b=fact[1];
			c=ntmp/(a*b);
			cout<<"YES\n";
			cout<<a<<" "<<b<<" "<<c<<"\n";
		}
		else{
			if(fact.size()==1&&ctr[0]>=6){
				a=fact[0];
				b=a*a;
				c=ntmp/(a*b);
				cout<<"YES\n";
				cout<<a<<" "<<b<<" "<<c<<"\n";
			}
			else{
				cout<<"NO\n";
			}
		}
	}

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	vector<int> primes;
	calc_primes(int(1e6),primes);
	int t;       
	cin >> t;
	while(t--){
		solve(primes);
	}
	return 0;
}



