#include<bits/stdc++.h>
#define iint int
#define pll std::pair<iint,iint>
#define rep(i,a,b) for(iint i=(iint)a;i<(iint)b;i++)
#define per(i,a,b) for(iint i=(iint)a;i>(iint)b;i--)
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

std::vector<int> st(int(3e5)+1,0);
void print_vec(std::vector<int>& a){
	for(int i=0;i<a.size() && i < 20;i++){
		std::cout << a[i] << ((i<a.size()-1 && i <29) ? " ":"\n");
	}
}

int edit_query(int ind, int l, int r, int val){
	if(l > r)
		return 0;

	if(val < l || r < val || (l==r && val != l)){
		return 0;
	}

	if(l==r && val == l){
		st[ind]++;
	}
	else{
		st[ind] = edit_query(2*ind+1,l,(l+r)/2, val)+edit_query(2*ind+2,(l+r)/2+1,r,val);
	}
	// std::cout << val << " " << l << " " << r << " " << st[ind] << "\n";
	return st[ind];
}

int search_query(int ind, int l, int r, int s, int e){
	if(l>r || e < l || r < s){
		return 0;
	}

	if(s<=l && r<=e){
		return st[ind];
	}
	int tmp = search_query(2*ind+1,l,(l+r)/2,s,e)+search_query(2*ind+2,(l+r)/2+1,r,s,e);
	// std::cout << s << " " << e << " " << l << " " << r << " " << tmp << "\n";
	return tmp;
}

void solve(int test_c){
	int n;
	std::cin >> n;
	std::vector<int> a(n,0);
	int max_cit = 0;
	for(int i=0;i<n;i++){
		std::cin >> a[i];
		max_cit = std::max(max_cit,a[i]);
	}

	int st_l = max_cit+3;
	// cout << st_l << "\n";
	for(int i=0;i<2*(st_l)+10;i++){
		st[i]=0;
	}

	int curr_max = 0;
	std::vector<int> ans(n,0);
	for(int i=0;i<n;i++){
		curr_max = std::max(curr_max,std::max(i+1,a[i]));
		edit_query(0,0,st_l-1,a[i]);
		int l = 1, r = curr_max, mid;
		while(r-l>1){
			mid = (l+r)/2;
			if(mid <= search_query(0,0,st_l-1,mid,curr_max)){
				l = mid;
			}
			else{
				r = mid;
			}
		}
		// cout << i+1 << " " <<  l << " " << r << "\n";
		// print_vec(st);
		// std::cout << "\n";
		ans[i] = (r <= search_query(0,0,st_l-1,r,curr_max)) ? r : l;
	}

	std::cout << "Case #" << test_c << ": ";
	for(int i=0;i<n;i++){
		std::cout << ans[i] << (i < n-1 ? " ": "\n");
	}


}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;
	std::cin >> t;
	for(int i=0;i<t;i++){
			solve(i+1);
	}

	// 	solve();
	return 0;
}