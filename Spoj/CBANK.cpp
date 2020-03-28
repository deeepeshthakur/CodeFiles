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

// void solve(){
// 	std::vector<int> cnt(101,0);
// 	std::vector<std::vector<int>> cnt1(5);

// 	for(int a1 = 0; a1 <= 100; a1++){
// 		for(int a2 = 0; a2 <= 100/2; a2++){
// 			for(int a3 = 0; a3 <= 100/4; a3++){
// 				for(int a4 = 0; a4 <= 100/8; a4++){
// 					if(a1+a2*2+a3*4+a4*8<=100){
// 						cnt[a1+a2*2+a3*4+a4*8]++;
// 					}
// 				}
// 			}
// 		}
// 	}

// 	// for(int i = 0; i < cnt.size(); i++){
// 	// 	std::cout << i << " " << cnt[i] << "\n";
// 	// }

// 	for(int i = 0; i < cnt.size(); i++){
// 		cnt1[0].push_back(cnt[i]);
// 	}

// 	for(int j = 1;j < 5; j++){
// 		for(int i = 0; i < cnt1[j-1].size(); i++){
// 			if(i == 0){
// 				cnt1[j].push_back(cnt1[j-1][i]);
// 			}
// 			else{
// 				if(cnt1[j-1][i] - cnt1[j-1][i-1] > 0){
// 					cnt1[j].push_back(cnt1[j-1][i] - cnt1[j-1][i-1]);
// 				}
// 			}
// 		}
// 	}

// 	for(int i = 0; i < cnt1.size(); i++){
// 		for(int j = 0; j < cnt1[i].size(); j++){
// 			std::cout << j << " " << max(cnt1[i][j],0) << "      ";
// 			// std::cout << max(cnt1[i][j],0) << " ";
// 		}
// 		std::cout << "\n";
// 	}
// }


long long f2(long long a){
	return ((a%MOD)*((a+1)%MOD))%MOD;
}

long long f3(long long a){
	return (((a+1)%MOD)*((a+1)%MOD))%MOD;
}

long long f1(long long a, long long b, long long c){
	return (a*((b*c)%MOD))%MOD;
}

long long f0(long long a, long long b, long long c){
	if(a%3 == 0ll)
		a /= 3;

	if(b%3 == 0ll)
		b /= 3;

	if(c%3 == 0ll)
		c /= 3;
	return f1(a%MOD,b%MOD,(c+MOD)%MOD);
}

long long solve(){
	long long n;
	std::cin >> n;
	n=4*n;
	long long k = (n - 3)/8 + 1;
	if(n == 0 || n == 1){
		return 1ll;
	}

	if(n == 2 || n == 3){
		return 2ll;
	}

	long long ans = f0(k,k+1,4*k-1)%MOD;
	int rem = (n-3)%8;

	if(rem == 1 ||rem == 2)
		ans += f2(k);

	if(rem == 3 ||rem == 4)
		ans += (2*f2(k))%MOD;

	if(rem == 5 ||rem == 6)
		ans += (2*f2(k) + f3(k))%MOD;

	if(rem == 7)
		ans += (2*f2(k) + 2*f3(k))%MOD;

	return ans%MOD;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;
	std::cin >> t;
	while(t--){
		std::cout << solve() << "\n";
	}

	// 	solve();
	return 0;
}