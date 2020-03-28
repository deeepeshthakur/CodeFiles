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

void revf(int n,vector<int>& left){
	// vector<int> tmp(n,0);
	// for(int i=0;i<n;i++)
	// 	tmp[i]=left[n-1]-(i<n-1?left[n-2-i]:0);
	// for(int i=0;i<n;i++)
	// 	left[i]=tmp[i];
	if(n>1){
		for(int i=0;i<n-1;i++){
			if(i<n-2-i){
				swap(left[i],left[n-2-i]);
			}
			left[i]=left[n-1]-left[i];
		}
	}
}

int min_l(int n, vector<int>& left, vector<int>& right, bool rev=false){
	if(rev){
		revf(n,left);
		revf(n,right);
	}

	vector<int> ht(2*n+1,int(1e6));
	for(int i=0;i<=n;i++)
		if(i>0)
			ht[right[n-1]-right[i-1]+n]=min(i,ht[right[n-1]-right[i-1]+n]);
		else
			ht[right[n-1]+n]=min(0,ht[right[n-1]+n]);
	int ans = 2*n;
	for(int i=0;i<=n;i++)
		if(i<n)
			ans=min(ans,i+ht[-1*left[n-1-i]+n]);	
		else
			ans=min(ans,n+ht[n]);
	return ans;
}


void solve(){
	int n;
	cin>>n;
	vector<int> left(n,0),right(n,0);
	for(int i=0;i<n;i++){
		cin>>left[i];
		left[i]=(left[i]==1?-1:1);
		if(i>0){
			left[i]+=left[i-1];
		}
	}

	for(int i=0;i<n;i++){
		cin>>right[i];
		right[i]=(right[i]==1?-1:1);
		if(i>0){
			right[i]+=right[i-1];
		}
	}

	int ans = min_l(n,left,right,false);
	ans=min(ans,min_l(n,right,left,true));
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