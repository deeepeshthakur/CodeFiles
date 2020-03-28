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

bool check_fin(int a, int b, int c, int n){
	set<int> tmp;
	int ctr=0;
	while(a){
		tmp.insert(a%10);
		ctr++;
		a/=10;
	}
	a=b;
	while(a){
		tmp.insert(a%10);
		ctr++;
		a/=10;
	}
	a=c;
	while(a){
		tmp.insert(a%10);
		ctr++;
		a/=10;
	}

	return (ctr==n) && (tmp.size()==n);
}

bool check_fun_diff_dig(int i,int n){
	set<int> dig;
	int ctr=0;
	while(i){
		if(i%10>n)
			return false;
		dig.insert(i%10);
		ctr++;
		i/=10;
	}
	return (ctr==dig.size());
}

void solve(){
	int n;
	cin>>n;
	vector<int> all;
	for(int i=1;i<int(1e6);i++){
		if(check_fun_diff_dig(i,n))
			all.pb(i);
	}

	vector<bool> all_bool(all[all.size()-1]+1,false);
	for(int i=0;i<all.size();i++)
		all_bool[all[i]]=true;

	vector<bool> fin_ans(all_bool.size(),false);
	for(int i=0;i<all.size();i++){
		for(int j=i;j<all.size();j++){
			if(1ll*all[i]*all[j] < 1ll*all_bool.size() && all_bool[all[i]*all[j]]){
				fin_ans[all[i]*all[j]] = (fin_ans[all[i]*all[j]] || check_fin(all[i],all[j],all[i]*all[j],n)); 
			}
		}
	}

	long long ans=0;
	for(int i=0;i<fin_ans.size();i++){
		if(fin_ans[i])
			ans+=i;
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