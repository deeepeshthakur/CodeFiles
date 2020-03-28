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

long long fact(long long a){
	return (a < 2 ? 1ll:a*fact(a-1));
}

void solve(){
	long long n;
	cin>>n;
	string s = "abcdefghijklm";
	vector<int> tb(13,1),ans(13,0);

	long long curr_sum=1,tmp=0;
	for(int i=0;i<13;i++){
		tmp=0;
		priority_queue<int,vector<int>,greater<int>> pq;
		for(int j=0;j<13;j++)
			if(tb[j]==1)
				pq.push(j);
		if(pq.size()>1){
			long long sz = pq.size(),nm1_fact=fact(sz-1);
			if(curr_sum+nm1_fact > n){
				ans[i]=pq.top();
			}
			else{
				curr_sum+=nm1_fact;
				pq.pop();
				while(pq.size()>1 && curr_sum+nm1_fact<=n){
					curr_sum+=nm1_fact;
					pq.pop();
				}
				ans[i]=pq.top();
			}
		}	
		else{
			ans[i]=pq.top();
		}
		tb[ans[i]]--;
	}

	for(int i=0;i<13;i++){
		cout << s[ans[i]];
	}
	cout<<"\n";
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