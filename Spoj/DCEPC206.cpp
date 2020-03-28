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

std::vector<long long> st_val(int(1e5)*3+1,-1ll);
std::vector<bool> srt_arr(int(1e6)+1,false);

void make_tree(std::vector<long long>& st, std::vector<int> vec, int ind,int l, int r){
		// if(l > r)
		// 	return;

		// if(l == r){
		// 	st[ind] = 0ll;
		// 	return;
		// }

		// make_tree(st, vec,2*ind+1,l,(l+r)/2);
		// make_tree(st, vec,2*ind+2,(l+r)/2+1,r);

		// st[ind] = 0ll;

	for(int i = 0; i < st.size(); i++){
		st[i] = 0;
	}
}

void update_tree(std::vector<long long>& st, std::vector<int>& vec, int l, int r, int index, int value){
	if(l > r){
		return;
	}

	if(l == r){
		if(vec[l] == value){
			st[index] += value;
		}
		return;
	}

	if(vec[l] <= value && vec[r] >= value){
		update_tree(st,vec,l,(r+l)/2,2*index+1,value);
		update_tree(st,vec,(r+l)/2+1,r,2*index+2,value);
		st[index] = st[2*index+1] + st[2*index+2];
	}
}

long long search_query(std::vector<long long>& st, std::vector<int>& vec, int l, int r, int index, int value){
	if(l > r || vec[l] >= value){
		return 0ll;
	}

	if(vec[r] < value){
		return st[index];
	}

	return search_query(st,vec,l,(l+r)/2,2*index+1,value) + search_query(st,vec,(l+r)/2+1,r,2*index+2,value);
}

void solve(){
	int n;
	std::cin >> n;
	std::vector<int> arr(n,0);
	for(int i = 0; i < srt_arr.size(); i++)
		srt_arr[i] = false;
	for(int i = 0; i < n; i++){
		std::cin >> arr[i];
		srt_arr[arr[i]] = true;
	}

	std::vector<int> dis_ele;
	for(int i = 0; i < srt_arr.size(); i++){
		if(srt_arr[i])
			dis_ele.push_back(i);
	}

	// std::vector<long long> st_val(dis_ele.size()*2+1,-1ll);
	make_tree(st_val, dis_ele, 0, 0, dis_ele.size() - 1);

	long long ans_sum = 0ll;
	for(int i = 0; i < n; i++){
		ans_sum += search_query(st_val,dis_ele,0,dis_ele.size()-1,0,arr[i]);
		update_tree(st_val,dis_ele,0,dis_ele.size()-1,0,arr[i]);
	}

	std::cout << ans_sum << "\n";
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