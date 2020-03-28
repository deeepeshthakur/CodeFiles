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
vector<long long> dp;
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

void pre_calc_function(){
	for(int i=1;i<10;i++){
		long long tmp=0;
		for(int j=0;j<15;j++){
			tmp=tmp*10ll+i;
			dp.pb(tmp);
		}
	}
	sort(full(dp));
	// print_vec(dp);
}

void solve(){
	if(pre_calc){
		pre_calc=false;
		pre_calc_function();
	}
	long long n;
	cin>>n;
	int ctr=0;
	for(int i=0;i<dp.size()&&n>=dp[i];i++)
		ctr++;
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