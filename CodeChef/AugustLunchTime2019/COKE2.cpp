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
const double MOD=1e9+7;
long long mxxx = 1e11;

void make_tree(int index, int l, int r, std::vector<std::vector<long long>>& vec, std::vector<long long>& st){
	if(l > r)
		st[index] = mxxx;
	if(l == r){
		st[index] = vec[l][1];
	}
	else{
		make_tree(index*2 + 1, l, (l+r)/2, vec, st);
		make_tree(index*2 + 2, (l+r)/2 + 1, r, vec, st);
		st[index] = std::min(st[index*2 + 1], st[index*2 + 2]);
	}
}

long long search_tree(int index, int l, int r, int s, int e, std::vector<long long>& st){
	if(e < l || r < s){
		return mxxx;
	}

	if(s <= l && r <= e){
		return st[index];
	}

	return std::min(search_tree(2*index + 1, l, (l+r)/2, s, e, st), search_tree(2*index + 2, (l+r)/2 + 1, r, s, e, st));
}

void solve(){
	int n,q,k,l,r;
	std::cin >> n >> q >> k >> l >> r;
	std::vector<std::vector<long long>> vec(n,std::vector<long long>(2,0ll));
	for(int i = 0; i < n; i ++){
		std::cin >> vec[i][0] >> vec[i][1];
	}

	std::sort(vec.begin(),vec.end());
	std::vector<long long> tmp(n,0);
	for(int i = 0; i < n; i++){
		tmp[i] = vec[i][0];
	}

	std::vector<long long> st(2*n,0ll);
	make_tree(0,0,n-1,vec,st);

	int mn, mx, mxx, mnn;
	int s, e, mid;
	std::vector<long long> ans;
	for(int i = 1; i <= q; i++){
		if( k < l){
			mn = l + i;
			mx = r + i; 
		}
		else
		{
			if(k > r){
				mn = l - i;
				mx = r - i;
			}
			else{
				mn = l - i;
				mx = r + i;
			}
		}
		
		s = 0;
		e = n - 1;
		while(e - s > 1){
			mid = (s+e)/2;
			if(tmp[mid] < mn){
				s = mid;
			}
			else{
				e = mid;
			}
		}

		mnn = tmp[s] >= mn ? s : e;

		s = 0;
		e = n - 1;
		while(e - s > 1){
			mid = (s+e)/2;
			if(tmp[mid] > mx){
				e = mid;
			}
			else{
				s = mid;
			}
		}

		mxx = tmp[e] <= mx ? e : s;

		if(tmp[mxx] < mn || tmp[mnn] > mx){
			ans.push_back(-1ll);
		}
		else{
			mx = tmp[mxx];
			mn = tmp[mnn];
			if(mx >= mn && 0 <= mnn && mxx <= n - 1){
				ans.push_back(search_tree(0, 0, n - 1, mnn, mxx, st));
				// std::cout << search_tree(0, 0, n - 1, mnn, mxx, st) << std::endl;  
			}
			else{
				ans.push_back(-1ll);
			}
		}
	}

	for(int i = 0; i < q; i++){
		std::cout << ans[i];
		if(i + 1 < q)
			std::cout << " ";
		else
			std::cout << std::endl;
	}

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin >> t;
	while(t--){
		solve();
	}
	return 0;
}