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

inline int val(int x, int a, int b){
	return x*x + a*x + b;
}

int get_mx(int a, int b, vector<int>& p){
	int ans=0,x=0;
	while(binary_search(full(p),val(x,a,b))){
		ans++;
		x++;
	}
	return ans;
}

void solve(){
	int n=0;
	vector<int> primes;
	calc_primes(int(1e6),primes);
	// print_vec(primes,100);
	cin>>n;
	int mx=0,mx_a,mx_b,tmp;
	for(int a=-abs(n);a<=abs(n);a++){
		if(binary_search(full(primes),a))
		for(int b=-abs(n);b<=abs(n);b++){
			if((tmp=get_mx(b,a,primes))>mx){
				mx=tmp;
				mx_a=b;
				mx_b=a;
			}
		}
	}
	cout<<mx<<" "<<mx_a<<" "<<mx_b<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}