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

int calc_fun(int l,int r,vector<int>& a,vector<int>& b){
	int bit_c=0,prev=0,ctr=0,swap_tmp;
	for(int i=l;i<=r;i++){
		bit_c+=b[i];
	}
	while(bit_c>0){
		// cout<<ctr<<"\n";
		// print_vec(a);
		// print_vec(b);
		// cout<<"\n";
		ctr++;
		prev=0;
		bit_c=0;
		for(int i=l;i<=r;i++){
			swap_tmp=prev;
			prev=(a[i]&b[i]);
			a[i]=(a[i]^b[i]);
			b[i]=swap_tmp;
			bit_c+=b[i];
		}
	}
	return ctr;
}

void solve(){
	string a,b;
	cin>>a>>b;
	int sa=a.length(),sb=b.length(),n=max(sa,sb)+1;
	vector<int> avec(n,0),bvec(n,0);
	for(int i=0;i<n;i++){
		avec[i]=(i<sa && a[sa-1-i]=='1'?1:0);
		bvec[i]=(i<sb && b[sb-1-i]=='1'?1:0);
	}
	int ctr = calc_fun(0,n-1,avec,bvec);
	cout<<ctr<<"\n";
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