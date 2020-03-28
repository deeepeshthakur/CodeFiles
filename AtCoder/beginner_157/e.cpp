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

void edit_query(int ind, int l, int r, int index, int val1, int val2, vector<vector<int>>& st){
	if(l>r || index>r || index<l)
		return;
	if(l==r && r==index){
		st[ind][val1]++;
		if(val2!=-1){
			st[ind][val2]--;
		}
		return;
	}

	edit_query(2*ind+1,l,(l+r)/2,index,val1,val2,st);
	edit_query(2*ind+2,(l+r)/2+1,r,index,val1,val2,st);
	int mid=(l+r)/2;
	for(int j=0;j<26;j++){
		st[ind][j]=(l<=mid?st[2*ind+1][j]:0)+(mid+1<=r?st[2*ind+2][j]:0);
	}
}

void search_query(int ind, int l, int r, int s, int e, vector<vector<int>>& st, vector<int>& ans){
	if(l>r || e<l || s>r){
		return;
	}
	if(s<=l && r<=e){
		for(int i=0;i<26;i++)
			ans[i]+=st[ind][i];
		return;
	}

	search_query(2*ind+1,l,(l+r)/2,s,e,st,ans);
	search_query(2*ind+2,(l+r)/2+1,r,s,e,st,ans);
}

void solve(){
	int n,q;
	string s;
	cin>>n>>s>>q;
	vector<vector<int>> st(4*n,vector<int>(26,0));
	for(int i=0;i<n;i++){
		edit_query(0,0,n-1,i,int(s[i]-'a'),-1,st);
	}

	vector<int> ans(26,0);
	int tp, ind, l,r,out;
	char c;
	for(int iquer=0;iquer<q;iquer++){
		cin>>tp;
		if(tp==1){
			cin>>ind>>c;
			edit_query(0,0,n-1,ind-1,int(c-'a'),int(s[ind-1]-'a'),st);
			s[ind-1]=c;
		}
		else{
			cin>>l>>r;
			l--;
			r--;
			search_query(0,0,n-1,l,r,st,ans);
			out=0;
			for(int i=0;i<26;i++){
				out+=(ans[i]>0?1:0);
				ans[i]=0;
			}
			cout<<out<<"\n";
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}