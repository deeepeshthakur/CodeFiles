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
	int n=str.size();
	std::vector<int> even,odd,num(n,0);
	for(int i=0;i<n;i++){
		int dig = int(str[i] - '0');
		if(dig%2 == 1){
			odd.pb(dig);
		}
		else{
			even.pb(dig);
		}
	}

	for(int i=0,j=0,k=0;i<n;i++){
		if(j < odd.size() && k < even.size()){
			if(odd[j] < even[k]){
				num[i] = odd[j];
				j++;
			}
			else{
				num[i] = even[k];
				k++;
			}
		}
		else{
			if(k < even.size() || j < odd.size()){
				if(k < even.size()){
					num[i] = even[k];
					k++;
				}
				else{
					num[i] = odd[j];
					j++;
				}
			}
		}
	}

	for(int i=0;i<n;i++)
		std::cout << num[i];
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