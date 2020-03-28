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
using namespace std::chrono;

const double pi=acos(-1.0);
const double pii=2*pi;
const double eps=1e-6;
const long long MOD=1e9+7;

std::vector<long long> sum_sq(5000,0ll);
std::vector<std::vector<long long>> dp_remsq(5000,std::vector<long long>(100,0ll));

long long get_squares(int a, int b){
	if(a > b)
		return 0ll;
	if(a == 1)
		return sum_sq[b-1];

	return sum_sq[b-1] - sum_sq[a-2];
}

void initial_fun(){
	for(int i  = 1; i <= 5000; i++){
		if(i > 1)
			sum_sq[i-1] = sum_sq[i-2];
		sum_sq[i-1] += 1ll*i*i;
	}

	for(int i = 1; i <= 5000; i++){
		long long summ = 0ll;
		for(int j = 0; j < 100; j++){
			for(int p = j*50 + 1; p <= (j+1)*50; p++){
				summ += (p > i) ? (1ll*p*p)%i : 0ll;
			}
			dp_remsq[i-1][j] = summ;
		}
	}
}

long long solve_coor(long long a, long long b, long long bmax){
	long long ans = 0;
	if(a <= b && b >= bmax)
		return 0ll;

	if(a < (bmax*bmax)/b){
		long long ab = std::sqrt(a*b*1.0);
		ans = solve_coor(a,b,ab)%MOD  + (std::max(0ll,bmax - std::max(b,ab))*std::max(0ll,a-b))%MOD;
		return ans%MOD;
	}

	int index = bmax/50 - 1;
	if(index >= 0){
		ans	= get_squares(int(b),(index+1)*50) - dp_remsq[int(b-1)][index];
		ans = (ans/b)%MOD;
	}

	for(int i = (bmax/50)*50 + 1; i <= bmax; i++){
		if(i >= b){
			ans += ((1ll*i*i)/b)%MOD;
			ans	%= MOD;
		}
	}

	return (ans - (b*std::max(0ll,bmax - b + 1))%MOD + MOD)%MOD;

}

long long solve_i(long long a, long long ind, long long b, long long c){
	return (a < ind || c < ind) ? 0ll : (solve_coor(a,ind,b)%MOD + solve_coor(c,ind,b)%MOD + (b-ind+1+MOD)%MOD)%MOD;
}

long long solve_b5000(long long a, long long b, long long c){
	long long ans = 0ll;
	for(int i = 1; i <= b; i++){
		ans += solve_i(a,i*1ll,b,c)%MOD;
		ans %= MOD;
	}
	return ((((a*c)%MOD)*b)%MOD - (ans%MOD) + MOD)%MOD;
}

long long solve_b100(long long a, long long b, long long c){
	if(a*c - b*b <= 0 || a*c <= 0)
		return 0ll;
	long long tmp = std::min(std::min(b+1,a+1),c+1), bsq = b*b;
	long long ans = 0;
	for(long long i = 1; i < tmp ; i++){
		ans += (std::max(0ll, std::min(bsq/i,a) - i) + std::max(std::min(bsq/i,c) - i,0ll) + 1)%MOD;
	}
	return ((a*c)%MOD - ans%MOD + MOD)%MOD;
}

void solve(int i, std::vector<std::vector<long long>>& inp){
	long long a = inp[i][0] - 1, b = inp[i][1], c = inp[i][2] - 1;
	long long ans = 0;

	if(b <= 1)
		for(long long i = 1; i <= b; i++)
			ans += solve_b100(a,i,c)%MOD;
	else
		ans = solve_b5000(a*1ll,b*1ll,c*1ll)%MOD;

	std::cout << ans%MOD << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;
	std::cin >> t;
	std::vector<std::vector<long long>> inp(t,std::vector<long long>(3,0ll));
	for(int i = 0; i < t; i++){
		std::cin >> inp[i][0] >> inp[i][1] >> inp[i][2];
	}
	
	initial_fun();

	for(int i = 0; i < t; i++){
		solve(i,inp);
	}
	return 0;
}