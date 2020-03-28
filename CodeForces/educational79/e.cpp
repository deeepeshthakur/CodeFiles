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

void make_tree(int ind, int l, int r, vector<int>& a, vector<pair<int,int>>& st){
	if(l<=r){
		if(l==r){
			st[ind].first=a[l];
			st[ind].second=l;
		}
		else{
			make_tree(2*ind+1,l,(l+r)/2,a,st);
			make_tree(2*ind+2,(l+r)/2+1,r,a,st);
			int mid=(l+r)/2;
			if(l<=mid && mid+1<=r){
				if(st[2*ind+1].first>=st[2*ind+2].first){
					st[ind].first=st[2*ind+1].first;
					st[ind].second=st[2*ind+1].second;
				}
				else{
					st[ind].first=st[2*ind+2].first;
					st[ind].second=st[2*ind+2].second;
				}
			}	
			else{
				cout<<"ERROR invalid index in MAKING TREE"<<endl;
			}
		}
	}
}

void edit_tree(int ind, int l, int r, int edit_ind, vector<pair<int,int>>& st){
	if(l<=edit_ind && edit_ind<=r){
		if(l==r){
			st[ind].first=0;
		}
		else{
			edit_tree(2*ind+1,l,(l+r)/2,edit_ind,st);
			edit_tree(2*ind+2,(l+r)/2+1,r,edit_ind,st);
			int mid=(l+r)/2;
			if(l<=mid && mid+1<=r){
				if(st[2*ind+1].first>=st[2*ind+2].first){
					st[ind].first=st[2*ind+1].first;
					st[ind].second=st[2*ind+1].second;
				}
				else{
					st[ind].first=st[2*ind+2].first;
					st[ind].second=st[2*ind+2].second;
				}
			}	
			else{
				cout<<"ERROR invalid index in EDIT QUERY"<<endl;
			}
		}
	}
}

int get_val(vector<int> a, int n, int k,int l){
	vector<int> dp(n,0);
	for(int i=0;i<l;i++)
		dp[0]+=a[i];
	for(int i=1;i<n;i++){
		dp[i]=dp[i-1]-a[i-1]+(l-1+i<n?a[l-1+i]:0);
	}
	vector<pair<int,int>> st(4*n,{0,0});
	make_tree(0,0,n-1,dp,st);

	int sm=0,curr,curr_ind;
	for(int i=0;i<n;i++){
		sm+=a[i];
	}
	
	// cout << sm << "\n";
	while(k-- && st[0].first>0){
		curr=st[0].first;
		curr_ind=st[0].second;
		// cout << st[0].first << " " << st[0].second << " ---------------- \n";
		sm-=curr;
		for(int i=max(0,curr_ind-l+1);i<min(curr_ind+l,n); i++)
			edit_tree(0,0,n-1,i,st);
	}
	return (k>0?0:sm);
}

void solve(){
	int n,k,l;
	cin>>n>>k>>l;
	string s;
	cin>>s;
	vector<int> a(n,0);
	for(int i=0;i<n;i++){
		a[i]=('A'<=s[i] && s[i]<='Z' ? 1:0);
	}

	int ans=get_val(a,n,k,l);
	for(int i=0;i<n;i++){
		a[i]=1-a[i];
	}

	ans=min(ans,get_val(a,n,k,l));
	cout<<ans<<"\n";
}	

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}