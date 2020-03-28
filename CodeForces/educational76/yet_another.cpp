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
 
int get_index(int val, std::vector<std::pair<long long, long long>>& arr){
	int l=0,r=arr.size()-1,mid;
	if(val <= arr[0].F)
		return 0;
 
	while(r - l > 1){
		mid = (l+r)/2;
		if(val > arr[mid].F)
			l = mid;
		else
			r = mid;
	}
 
	return (val <= arr[l].F ? l : r);
}
 
void solve(){
	int n,m;
	std::cin >> n;
	std::vector<long long> monster(n,0ll);
	for(int i=0;i<n;i++)
		std::cin >> monster[i];
	std::cin >> m;
	std::vector<std::pair<long long, long long>> hero(m,{0ll,0ll});
	for(int i=0;i<m;i++)
		std::cin >> hero[i].F >> hero[i].S;
 
	std::sort(full(hero));
	std::vector<long long> max_end(m,0ll);
	
	long long curr_max = 0;
	for(int i=m-1;i>=0;i--){
		curr_max = std::max(curr_max,hero[i].S);
		max_end[i] = curr_max;
	}
 
	int curr_day = 0, curr_mon = 0, tot_mon = 0;
	long long curr_max_st = 0;
 
	while(tot_mon < n){
		curr_max_st = std::max(curr_max_st,monster[tot_mon]);
		if(curr_max_st > hero[m-1].F){
			std::cout << "-1\n";
			return;
		}
 
		long long end = max_end[get_index(curr_max_st,hero)];
		if(end >= curr_mon+1){
			curr_mon++;
			tot_mon++;
			if(tot_mon == n)
				curr_day++;
		}
		else{
			curr_day++;
			curr_mon = 0;
			curr_max_st = 0;
		}
	}
	std::cout << curr_day << "\n";
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
 
	// 	solve();
	return 0;
}