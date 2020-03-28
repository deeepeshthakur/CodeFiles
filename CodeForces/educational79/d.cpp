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
const long long MOD=998244353ll;

long long pow_mod(long long a, long long b){
	if(a == 0)
		return 0ll;
	if(b == 0)
		return 1ll;
	if(b == 1)
		return a%MOD;
	long long x = pow_mod(a,b/2);
	x = (x*x)%MOD;
	if(b%2==1)
		return (x*a)%MOD;
	return x;
}

void get_sum(pair<long long,long long>& a, long long num, long long den){
	long long t1=a.first,t2=a.second;
	t1=(((t1*den)%MOD)+((t2*num)%MOD))%MOD;
	t2=(t2*den)%MOD;
	a.first=t1;
	a.second=t2;
}

pair<long long,long long> get_prob(vector<int>& a){
	long long num=0,den=1;
	for(int i=0;i<a.size();i++){
		den=(den*a[i])%MOD;
	}

	for(int i=0;i<a.size();i++){
		num+=(den*pow_mod(1ll*a[i],MOD-2))%MOD;
		num%=MOD;
	}
	return pair<long long,long long>({num,den});
}

void solve(){
	int n;
	cin>>n;
	vector<vector<int>> child(n);
	int k=0;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x;
		for(int j=0;j<x;j++){
			cin>>y;
			k=max(k,y);
			child[i].pb(y-1);
		}
	}

	vector<vector<int>> k_prob(k);
	for(int i=0;i<n;i++){
		for(int j=0;j<child[i].size();j++){
			k_prob[child[i][j]].pb(child[i].size());
		}
	}
	vector<pair<long long,long long>> pk(k);
	for(int i=0;i<k;i++){
		pk[i]=get_prob(k_prob[i]);
	}

	pair<long long,long long> tmp;
	tmp.first=0;
	tmp.second=1;
	for(int i=0;i<k;i++){
		get_sum(tmp,(pk[i].first*k_prob[i].size())%MOD,pk[i].second);
	}
	long long ans_num=tmp.first,ans_den=(tmp.second*((1ll*n*n)%MOD))%MOD;
	long long ans=(ans_num*pow_mod(ans_den,MOD-2))%MOD;
	cout<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}