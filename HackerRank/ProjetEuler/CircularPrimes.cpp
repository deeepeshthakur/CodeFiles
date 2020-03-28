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

vector<bool> primes(int(1e6)+1,true);
vector<int> circular_primes(primes.size(),-1);

void get_primes(int ind, vector<int>& a){
	int n=ind;
	vector<int> tmp;
	while(n){
		tmp.pb(n%10);
		n/=10;
	}

	for(int i=0;i<tmp.size();i++){
		int val=0,mul=1;
		for(int j=0;j<tmp.size();j++){
			val+=mul*tmp[(i+j)%tmp.size()];
			mul*=10;
		}
		a.pb(val);
	}
}

void seive(){
	int n=primes.size();
	primes[0]=false;
	primes[1]=false;
	for(int i=2;i<n;i++){
		if(primes[i]){
			int j=i;
			while(j<n && 1ll*i*j<1ll*n){
				primes[i*j]=false;
				j++;
			}
		}
	}
	circular_primes[0]=0;
	circular_primes[1]=0;
	for(int i=2;i<n;i++){
		if(circular_primes[i]==-1){
			if(primes[i]){
				vector<int> cp;
				get_primes(i,cp);
				bool flag=true;
				for(int j=0;j<cp.size();j++)
					if(!primes[cp[j]])
						flag=false;
				
				for(int j=0;j<cp.size();j++)
					if(circular_primes[cp[j]]==-1)
						circular_primes[cp[j]]=(flag ? 1:0);
			}
			else{
				circular_primes[i]=0;
			}
		}
	}
}

void solve(){
	seive();
	int n;
	cin>>n;
	long long sm=0;
	for(int i=0;i<n;i++){
		sm += (circular_primes[i]==1 ? i:0);
	}
	cout << sm <<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	solve();
	
	return 0;
}