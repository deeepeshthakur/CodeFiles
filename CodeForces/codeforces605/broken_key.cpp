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
	int n, k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<bool> possible(n,false); vector<char> valid(k,'a');
	for(int i=0;i<k;i++)
		cin>>valid[i];

	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			if(s[i]==valid[j]){
				possible[i]=true;
			}
		}
	}

	vector<int> tmp;
	for(int i=0;i<n;i++){
		if(possible[i]){
			int ctr = 0;
			for(int j=i;j<n && possible[j];j++){
				ctr++;
				possible[j]=false;
			}
			tmp.pb(ctr);
		}
	}

	long long ans=0;
	for(int i=0;i<tmp.size();i++){
		ans += (1ll*tmp[i]*(tmp[i]+1))/2;
	}
	cout << ans << "\n";

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}