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

void solve(){
	int n;
	cin>>n;
	vector<int> sum_vec(100,0);
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int sz=s.size();
		for(int j=0;j<sz;j++){
			sum_vec[j]+=(s[sz-1-j]-'0');
		}
	}

	for(int i=0;i<sum_vec.size();i++){
		if(i<sum_vec.size()-1){
			sum_vec[i+1]+=sum_vec[i]/10;
			sum_vec[i]%=10;
		}
		else{
			int tmp=sum_vec[i]/10;
			sum_vec[i]%=10;
			while(tmp){
				sum_vec.pb(tmp%10);
				tmp/=10;
			}
		}
	}
	long long ans=0ll,val=((long long)(1e5))*((long long)(1e5));
	for(int i=sum_vec.size()-1;i>0;i--){
		if(ans*10ll+sum_vec[i]<val){
			ans=ans*10ll+sum_vec[i];
		}
	}
	cout<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}