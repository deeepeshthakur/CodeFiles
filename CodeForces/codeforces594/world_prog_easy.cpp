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

void print_vec(std::vector<int>& a){
	for(int i = 0; i < a.size(); i++){
		std::cout << (a[i] == 1 ? "(" : ")") << (i < a.size() - 1 ? " " : "\n");
	}
}

void get_input(std::vector<int>& a){
	int n = a.size();
	std::string str;
	std::cin >> str;
	for(int i = 0; i < n; i++){
		if(str[i] == '('){
			a[i] = 1;
		}
		else{
			a[i] = -1;
		}
	}
}

// int get_beauty(int n, std::vector<int>& vec, std::vector<int>& str_i, std::vector<int>& i_end){
int get_beauty(int n, std::vector<int>& vec){//, std::vector<int>& str_i, std::vector<int>& i_end){
	// for(int i = 0; i < n; i++){
	// 	str_i[i] = 0;
	// 	i_end[i] = 0;
	// }

	int mins = 5000, maxs = -5000, val = 0, ans = 0;
	for(int i = 0; i < n; i++){
		val += vec[i];
		mins = (mins > val) ? val : mins;
		maxs  =(maxs < val) ? val : maxs;
	}

	if(val == 0 && mins > -1){
		ans++;
		// std::cout << 1 << " ";
	}

	for(int i = 1; i < n; i++){
		int j = i - 1;
		// val += (vec[i] - vec[i]);
		// maxs = std::max(maxs,maxs - vec[j]);
		maxs = maxs - vec[j];
		mins = mins - vec[j];

		mins = (mins > val) ? val : mins;
		maxs  =(maxs < val) ? val : maxs;
		if(val == 0 && mins > -1)
			ans++;
		// std::cout << i + 1 << " ";
	}

	return ans;

}

void solve(){
	int n;
	std::cin >> n;
	std::vector<int> vec(n,0);
	get_input(vec);
	std::vector<int> str_i(n,0), i_end(n,0);

	int ans = 0, l = 0, r = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			int tmp = vec[i];
			vec[i] = vec[j];
			vec[j] = tmp;
			// std::cout << i << " " << j << "     ";
			// print_vec(vec);
			int tmp_ans = get_beauty(n,vec);
			if(tmp_ans > ans){
				ans = tmp_ans;
				l = i;
				r = j;
			}
			// ans = std::max(ans,get_beauty(n,vec,str_i,i_end));
			
			tmp = vec[i];
			vec[i] = vec[j];
			vec[j] = tmp;
			// print_vec(vec);
			// std::cout  	<< "\n";
		}
	}

	std::cout << ans << "\n" << l+1 << " " << r+1 << "\n";
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