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
	int n,m;
	cin>>n>>m;
	vector<int> a(n,0);
	for(int i=0;i<n;i++)
		cin>>a[i];
	vector<int> h(n,0);
	for(int i=0;i<n;i++){
		h[a[i]-1]=n-i;
	}

	vector<int> b(m,0);
	for(int i=0;i<m;i++)
		cin>>b[i];

	vector<pair<int,int>> arrange(m,{0,0});
	for(int i=0;i<m;i++){
		arrange[i].first=h[b[i]-1];
		arrange[i].second=i;
	}

	sort(full(arrange));
	stack<pair<int,int>> st;
	vector<bool> is_in_stack(m,true);
	for(int i=0;i<m;i++){
		st.push({arrange[i].first,arrange[i].second});
	}

	int curr_height=n, ith_height;
	long long ans=0;
	for(int i=0;i<m;i++){
		if(is_in_stack[i]){
			while(!st.empty() && st.top().second!=i){
				is_in_stack[st.top().second]=false;
				st.pop();
			}
			ith_height=st.top().first;
			ans+=(max(0,curr_height-ith_height)*2ll+1);
			is_in_stack[i]=false;
			st.pop();
		}
		else{
			ans++;
		}
		curr_height--;
	}
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