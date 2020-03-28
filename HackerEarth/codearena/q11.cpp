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

vector<bool> primes(2*int(1e6)+10,true);
void calc_primes(){
	int n = primes.size();
	primes[0]=false;
	primes[1]=false;
	for(int i=2;i<n;i++){
		if(primes[i]){
			int j=i;
			while(j<n && (1ll*j*i)<(1ll*n)){
				primes[i*j]=false;
				j++;
			}
		}
	}
}

inline bool is_prime_fun(int n){
	return primes[n];
}

int make_tree(int ind, int l, int r, vector<int>& st, vector<int>& is_prime){
	if(l > r)
		return 0;
	if(l==r){
		st[ind] = is_prime[l];
	}
	else{
		st[ind] = make_tree(2*ind+1,l,(l+r)/2,st,is_prime) + make_tree(2*ind+2,(l+r)/2+1,r,st,is_prime);
	}
	return st[ind];
}

int edit_query(int ind, int l, int r, int val, vector<int>& st, int is_prime){
	if(l > r)
		return 0;

	if(l==r && l==val){
		st[ind]=is_prime;
	}
	else{
		if(l != r && l <= val && val <= r){
			st[ind]=edit_query(2*ind+1,l,(l+r)/2,val,st,is_prime)+edit_query(2*ind+2,(l+r)/2+1,r,val,st,is_prime);
		}
	}
	return st[ind];
}

int search_query(int ind, int s, int e, int l, int r, vector<int>& st){

	if(l>r || e < l || r < s)
		return 0;

	if(s<=l && r<=e)
		return st[ind];

	return search_query(2*ind+1,s,e,l,(l+r)/2,st) + search_query(2*ind+2,s,e,(l+r)/2+1,r,st);
}

void solve(){
	int n;
	cin>>n;
	vector<int> arr(n,0);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	vector<int> is_prime(n,0);
	for(int i=0;i<n;i++)
		if(is_prime_fun(arr[i])){
			is_prime[i]=1;
		}

	vector<int> st(4*n+10,-1);

	int tmp = make_tree(0,0,n-1,st,is_prime);
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		char a;
		int b,c;
		cin >> a >> b >> c;
		if(a == 'C'){
			if(is_prime_fun(c)){
				is_prime[b-1]=1;
				tmp = edit_query(0,0,n-1,b-1,st,1);
			}
			else{
				is_prime[b-1]=0;
				tmp = edit_query(0,0,n-1,b-1,st,0);
			}
		}
		else{
			cout << search_query(0,b-1,c-1,0,n-1,st) << "\n";
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	calc_primes();
	int t;       
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}