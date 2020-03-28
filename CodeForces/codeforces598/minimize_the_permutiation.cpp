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

void print_vec(std::vector<int>& arr){
	int n = arr.size();
	for(int i=0;i<n;i++)
		std::cout << arr[i] << (i < n - 1 ? " ":"\n");

}

int f1(std::vector<bool>& chk, std::vector<int>& arr, int ind){
	int n=arr.size(),min_ind = ind, minm=arr[ind];
	for(int i=ind;i<n;i++){
		if(arr[i] < minm){
			minm = arr[i];
			min_ind = i;
		}
	}

	int j = min_ind;
	while(j>ind){
		std::swap(arr[j-1],arr[j]);
		j--;
	}
	return std::max(ind,min_ind - 1);
}

void solve(){
	int n;
	std::cin >> n;
	std::vector<int> arr(n,0);
	
	for(int i=0;i<n;i++){
		std::cin >> arr[i];
		arr[i]--;
	}


	std::vector<bool> chk(n,true);
	int mimn = 0;
	if(n > 1){
		// for(int i=0;i<n;i++){
		// 	if(arr[i] != mimn){
		// 		int j;
		// 		for(j=i;j<n;j++){
		// 			if(arr[j] == mimn)
		// 				break;
		// 		}

		// 		while(i < j){
		// 			std::swap(arr[i],arr[i+1]);
		// 			i++;
		// 		}

		// 		for(int k=0;k<j;k++){
		// 			chk[arr[k]] = false;
		// 		}

		// 		for(int k=0;k<n;k++){
		// 			if(chk[k]){
		// 				mimn = k;
		// 				break;
		// 			}
		// 		}
		// 		i = j;
		// 	}
		// 	else{
		// 		chk[arr[i]]=false;
		// 		for(int j=0;j<n;j++){
		// 			if(chk[j]){
		// 				mimn = j;
		// 				break; 
		// 			}
		// 		}
		// 	}
		// }

		for(int i=0;i<n;i++){
			i = f1(chk,arr,i);
			// std::cout << i << "     ";
			// print_vec(arr);
		}

	}

	for(int i=0;i<n;i++)
		std::cout << arr[i] + 1 << (i < n - 1 ? " ":"\n");


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