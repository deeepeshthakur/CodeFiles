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

// void print_vec(std::vector<std::pair<long long, long long>>& vec){
// 	for(int i = 0; i < vec.size(); i++){
// 		std::cout << vec[i].F << " " << vec[i].S << "    ";
// 	}
// 	std::cout << "\n";
// }

// void print_vec(std::vector<long long>& vec){
// 	for(int i =0 ; i < vec.size(); i++){
// 		std::cout << vec[i] << " ";
// 	}
// 	std::cout << "\n";
// }

long long bin_s(std::vector<std::pair<long long, long long>>& vec, long long val){
	int l = 0, r = vec.size() - 1, mid;
	long long ans = 0;

	while(r - l > 1){
		mid = (l+r)/2;
		if(val > vec[mid].F){
			l = mid;
		}
		else{
			r = mid;
		}
	}

	if(vec[r].F == val || vec[l].F == val){
		ans = (vec[r].F == val ? vec[r].S : vec[l].S);
	}

	return ans;
}

void solve(){
	int n;
	std::cin >> n;
	std::vector<long long> arr(n,0ll);
	for(int i = 0; i < n; i++)
		std::cin >> arr[i];

	std::vector<std::pair<long long, long long>> val_sum, val_mul;

	if(true){
		std::vector<std::pair<long long, long long>> sum_pairs, pairs;
		std::vector<long long> tmp;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				tmp.push_back(arr[i]+arr[j]);
			}
		}

		std::sort(full(tmp));
		sum_pairs.push_back({tmp[0],1ll});
		int x = 0;
		for(int j = 1; j < tmp.size(); j++){
			if(tmp[j] == sum_pairs[x].F){
				sum_pairs[x].S++;
			}
			else{
				x++;
				sum_pairs.push_back({tmp[j],1ll});	
			}
		}

		for(int i = 0; i < sum_pairs.size(); i++){
			for(int j = 0; j < arr.size(); j++){
				if(arr[j] != 0){
					pairs.push_back({sum_pairs[i].F*arr[j],sum_pairs[i].S});
				}
			}
		}
		
		std::sort(full(pairs));
		val_sum.push_back({pairs[0].F,pairs[0].S});
		x = 0;
		for(int i = 1; i < pairs.size(); i++){
			if(pairs[i].F == val_sum[x].F){
				val_sum[x].S += pairs[i].S;
			}
			else{
				x++;
				val_sum.push_back({pairs[i].F,pairs[i].S});
			}
		}
	}

	if(true){
		std::vector<long long> tmp;
		std::vector<std::pair<long long, long long>> mul_pairs, pairs;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				tmp.push_back(arr[i]*arr[j]);
			}
		}

		std::sort(full(tmp));
		int x = 0;
		mul_pairs.push_back({tmp[0],1ll});
		for(int i = 1; i < tmp.size(); i++){
			if(mul_pairs[x].F == tmp[i]){
				mul_pairs[x].S++;
			}
			else{
				x++;
				mul_pairs.push_back({tmp[i],1ll});
			}
		}

		for(int i = 0; i < mul_pairs.size(); i++){
			for(int j = 0; j < n; j++){
				pairs.push_back({mul_pairs[i].F+arr[j],mul_pairs[i].S});
			}
		}

		std::sort(full(pairs));
		x = 0;
		val_mul.push_back({pairs[0].F,pairs[0].S});
		for(int i = 1; i < pairs.size(); i++){
			if(pairs[i].F == val_mul[x].F){
				val_mul[x].S += pairs[i].S;
			}
			else{
				x++;
				val_mul.push_back({pairs[i].F,pairs[i].S});
			}
		}
	}

	// print_vec(val_sum);
	// print_vec(val_mul);

	long long ans = 0;
	for(int i = 0; i < val_sum.size(); i++){
		ans += val_sum[i].S*bin_s(val_mul,val_sum[i].F);
	}
	std::cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// int t;
	// std::cin >> t;
	// while(t--){
	// 	solve();
	// }

	solve();
	return 0;
}
