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

void solve(){
	std::string str;
	std::cin >> str;
	int n = str.size();
	std::vector<bool> arr(26,false);

	for(int i=0;i<n;i++){
		// int rem = 0, j = i;
		// while(j<n && str[j]==str[i]){
		// 	j++;
		// }
		// if(j<n){
		// 	rem = j-i;
		// 	if(rem%2==1){
		// 		arr[int(str[i] - 'a')] = (arr[int(str[i] - 'a')] || true);
		// 	}
		// 	i = j-1;
		// }
		// else{
		// 	rem = j-i+1;
		// 	if(rem%2==1){
		// 		arr[int(str[i] - 'a')] = (arr[int(str[i] - 'a')] || true);
		// 	}
		// 	i = n;
		// }

		if(i == 0 || str[i] != str[i-1]){
			int rem = 0;
			for(int j=i;j<n && str[j]==str[i];j++)
				rem++;

			if(rem%2 == 1){
				arr[int(str[i] - 'a')] = (arr[int(str[i] - 'a')] || true);
			}
		}
	}

	// for(int i=0;i<str.size();i++){
	// 	if(i+1<n){
	// 		if(str[i]==str[i+1]){
	// 			i=i+1;
	// 		}
	// 		else{
	// 			arr[int(str[i]-'a')] = (arr[int(str[i]-'a')] || true); 
	// 		}
	// 	}
	// 	else{
	// 		if(str.size() > 1){
	// 			if(str[i] != str[i-1]){
	// 				arr[int(str[i]-'a')] = (arr[int(str[i]-'a')] || true);
	// 			}
	// 		}
	// 		else{
	// 			arr[int(str[i]-'a')] = (arr[int(str[i]-'a')] || true);
	// 		}
	// 	}
	// }

	int ans = 0;
	for(int i=0;i<26;i++)
		if(arr[i])
			std::cout << char(int('a')+i);

	std::cout << "\n";
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