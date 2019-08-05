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

bool f1(std::vector<long long>& b, int i, long long mid, int n, long long I){
	mid += b[i];
	int st = 0, en = b.size()-1, m;
	while(en - st > 1){
		m = (en+st)/2;
		if(b[m] > mid){
			en = m - 1;
		}
		else{
			st = m;
		}
	}

	int tmp;
	if(b[en] <= mid){
		tmp = en;
	}
	else{
		tmp = st;
	}
	tmp -= (i - 1);
	int k = 0;
	while(tmp > (1 << k)){
		k++;
	}

	return 8*I >= n*k; 
}

int f2(std::vector<long long>& b, long long l, long long r, int n){
	int left = 0, right = b.size() - 1, mid;
	while(right - left > 1){
		mid = (left + right)/2;
		if(b[mid] > l){
			right = mid - 1;
		}
		else{
			left = mid;
		}
	}

	int ans;
	if(b[left] == l){
		ans = -left;
	}
	else{
		ans = -right;
	}
	

	left = 0; right =  b.size() - 1;
	while(right - left > 1){
		mid = (left + right)/2;
		if(b[mid] < r){
			left = mid + 1;
		}
		else{
			right = mid;
		}
	}

	if(b[right] == r){
		ans += right + 1;
	}
	else{
		ans += left + 1;
	}
	
	ans = n - ans;
	return ans;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	long long n, I;
	std::cin >> n >> I;
	std::vector<long long> a(n, 0ll), b;
	for(int i = 0; i < n; i++){
		std::cin >> a[i];
	}
	std::sort(full(a));
	for(int i = 1; i < n; i++){
		if(a[i] != a[i-1]){
			b.push_back(a[i]);
		}
	}

	long long ans = 2e9;
	for(int i = 0; i < b.size(); i++){
		long long st = b[i];
		long long l = 0, r = b[b.size() - 1] - b[i], mid;
		while(r - l > 1){
			mid = (l+r)/2;
			if(f1(b, i, mid, n , I)){
				l = mid;
			}
			else{
				r = mid;
			}
		}
		long long tmp;
		if(f1(b, i, l, n, I)){
			tmp = l + st;
		}
		else{
			tmp = r + st;
		}
		tmp = f2(b, st, tmp, n);
		ans = ans > tmp ? tmp : ans;
	}
	std::cout << ans << std::endl;
	return 0;
}