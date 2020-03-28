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

void edit_query(int ind, int l,int r, int ind_to_be_changed, int val, vector<int>& st){
	if(l<=r && l<= ind_to_be_changed && ind_to_be_changed<= r){
		if(l==r && l==ind_to_be_changed){
			st[ind]=val;
		}
		else{
			int mid=(l+r)/2;
			edit_query(2*ind+1,l,mid,ind_to_be_changed,val,st);
			edit_query(2*ind+2,mid+1,r,ind_to_be_changed,val,st);
			st[ind]=(l<=mid ? st[2*ind+1]:0) + (mid+1<=r? st[2*ind+2]:0);
		}
	}
}

int search_query(int ind, int l, int r, int no_of_elements, vector<int>& st){
	if(l > r || st[ind]<no_of_elements)
		return -1;
	if(l==r)
		return l;
	int mid=(l+r)/2;
	if(st[2*ind+1]>=no_of_elements)
		return search_query(2*ind+1,l,mid,no_of_elements,st);
	return search_query(2*ind+2,mid+1,r,no_of_elements-st[2*ind+1],st);
}

void solve(){
	int t,q;
	cin>>t>>q;
	vector<pair<int,int>> t_sort(t,{0,0}), cost_sort(t,{0,0});
	vector<vector<int>> queries(q,vector<int>(3,0));
	for(int i=0;i<t;i++){
		cin>> t_sort[i].second;
		t_sort[i].first=i;
		cost_sort[i].first=t_sort[i].second;
		cost_sort[i].second=t_sort[i].first;
	}

	sort(full(cost_sort),[](pair<int,int> const& a,pair<int,int> const& b){ return a.first > b.first;});
	for(int i=0;i<q;i++){
		queries[i][2]=i;
		cin>>queries[i][0]>>queries[i][1];
	}

	sort(full(queries),[](vector<int> const& a, vector<int> const& b) {return a[0]>b[0];});
	vector<int> st(4*t,0), ans(q,-1);
	int cost_ind=0,m,n;
	for(int i=0;i<q;i++){
		m=queries[i][0];
		n=queries[i][1];
		while(cost_ind<t && cost_sort[cost_ind].first>=m){
			edit_query(0,0,t-1,cost_sort[cost_ind].second,1,st);
			cost_ind++;
		}
		if(st[0]>=n){
			int ind=search_query(0,0,t-1,n,st);
			if(ind>=0)
				ans[queries[i][2]]=t_sort[ind].second;
		}
	}
	for(int i=0;i<q;i++)
		cout<<ans[i]<<"\n";

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}