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

vector<int> mul(vector<int> a,vector<int> b){
	vector<int> ans(a.size()+b.size(),0);
	for(int i=0;i<a.size();i++){
		for(int j=0;j<b.size();j++){
			ans[i+j]+=(a[i]*b[j]);
		}
	}
	for(int i=0;i<ans.size();i++){
		if(i+1<ans.size()){
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
		else{
			if(ans[i]>9){
				int tmp=ans[i]/10;
				ans[i]%=10;
				ans.pb(tmp);
			}
		}
	}
	return ans;
}

vector<int> sq_vec(vector<int> a){
	return mul(a,a);
}

void solve(){
	int n;
	cin>>n;
	vector<int> ans{1};
	for(int i=2;i<=n;i++)
		ans=mul(ans,vector<int>{i});
	int sm=0;
	for(int i=0;i<ans.size();i++)
		sm+=ans[i];
	cout<<sm<<"\n";
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