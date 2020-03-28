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
const long long mx_l = int(1e7);
const long long mul = int(1e9);
const long long max_ret_val = mx_l*mul*2ll;

long long make_tree(int ind, int l,int r, vector<long long>& st){
	if(l > r)
		return max_ret_val;
	if(l==r){
		st[ind] = mx_l*mul+l;
	}
	else{
		st[ind] = min(make_tree(2*ind+1,l,(l+r)/2,st),make_tree(2*ind+2,(l+r)/2+1,r,st));
	}
	return st[ind];
}

long long edit_query(int ind,long long val, int s, int l, int r, vector<long long>& st){
	if(l>r || s > r || s < l)
		return max_ret_val;

	if(l==r && l == s){
		st[ind] = min(st[ind],val);
		return st[ind];
	}

	st[ind] = min(edit_query(2*ind+1,val,s,l,(l+r)/2,st),edit_query(2*ind+2,val,s,(l+r)/2+1,r,st));
	return st[ind];
}

long long search(int ind, int s, int e, int l, int r, vector<long long>& st){
	if(l>r || s > r || e < l)
		return max_ret_val;

	if(s <=l  && r <= e){
		return st[ind];
	}

	return min(edit_query(2*ind+1,s,e,l,(l+r)/2,st),edit_query(2*ind+2,s,e,(l+r)/2+1,r,st));
}

void solve(){
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;

	vector<long long> st(3*n+1,mx_l);
	long long tmp = make_tree(0,0,n,st);
	edit_query(0,1ll*n,n,0,n,st);

	vector<int> path(n,-1);
	for(int i=n-1;i>=0;i--){
		if(s[i]==0){
			long long tmp = search(0,i+1,min(n,i+1+m),0,n,st);
			path[i] = (tmp%mul <= n ? int(tmp%mul) : -1ll);
			tmp = edit_query(0,(tmp/mul + 1)*mul+i,i,0,n,st);
		}
		else{
			edit_query(0,max_ret_val,i,0,n,st);
		}
	}

	vector<int> ans{0};
	while(ans[ans.size()-1]!=n || ans[ans.size()-1] != -1){
		ans.pb(path[ans.size()-1]);
	}

	if(ans[ans.size()-1]!=-1){
		for(int i=1;i<ans.size();i++)
			cout << ans[i]-ans[i-1] << (i<n-1 ? " ":"\n");
	}
	else{
		cout << "-1\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	solve();
	return 0;
}