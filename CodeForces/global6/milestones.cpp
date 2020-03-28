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
const long long MOD=100ll*int(1e8);

void make_tree(int ind, int l, int r, vector<long long>& a, vector<long long>& st){
	if(l>r)
		return;
	if(l==r){
		st[ind]=a[l];
		return;
	}
	int mid=(l+r)/2;
	make_tree(2*ind+1,l,mid,a,st);
	make_tree(2*ind+2,mid+1,r,a,st);
	st[ind] = (l<=mid?st[2*ind+1]:0ll)+(mid<=r?st[2*ind+2]:0ll);
}

void edit_query(int ind,int edit_ind, int l, int r, long long val,vector<long long>& st){
	if(l>r || edit_ind<l || r<edit_ind)
		return;
	if(l==r && r==edit_ind){
		st[ind]+=val;
		return;
	}
	if(l<=edit_ind && edit_ind<=r){
		int mid=(l+r)/2;
		edit_query(2*ind+1,edit_ind,l,mid,val,st);
		edit_query(2*ind+2,edit_ind,mid+1,r,val,st);
		st[ind]=(l<=mid?st[2*ind+1]:0ll)+(mid<=r?st[2*ind+2]:0ll);
	}
}

long long search_query(int ind, int range_s, int range_e, int l, int r, vector<long long>& st){
	if(l>r || range_e<l || range_s>r)
		return 0ll;
	if(range_s<=l && r<=range_e)
		return st[ind];
	if((l<=range_s && range_s<=r) || (l<=range_e && range_e<=r)){
		int mid=(l+r)/2;
		return search_query(2*ind+1,range_s,range_e,l,mid,st)+search_query(2*ind+2,range_s,range_e,mid+1,r,st);
	}
}

void solve(){
	int n;
	cin>>n;
	vector<long long> a(n,0ll);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<long long> st(4*n+100,0ll);
	make_tree(0,0,n-1,a,st);
	int q;
	cin>>q;
	unordered_map<long long,int> ht;
	for(int i=0;i<q;i++){
		int s,u;
		long long t;
		cin>>s>>t>>u;
		long long key=s*MOD+t;
		auto itr=ht.find(key);
		if(itr!=ht.end() && itr->second==1){
				itr->second=0;
				edit_query(0,u-1,0,n-1,1ll,st);
		}
		else{
			if(u!=0){
				if(itr!=ht.end()){
					ht.insert({key,1});
				}
				else{
					itr->second=1;
				}
				edit_query(0,u-1,0,n-1,-1ll,st);
			}
		}
		cout<<search_query(0,0,n-1,0,n-1,st)<<"\n";
	}

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}