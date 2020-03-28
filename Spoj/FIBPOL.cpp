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
const long long tmp_mod=1e9;
const long long MOD = tmp_mod*tmp_mod;

bool is_p(long long a){
	long long sq_rt = std::sqrt(a);
	if(sq_rt*sq_rt == a || (sq_rt + 1)*(sq_rt + 1) == a)
		return true;

	return false;
}

struct str_num{
	long long a,b;

	str_num(){
		a = 0ll;
		b = 0ll;
	}

	str_num(long long n){
		a = 0ll;
		b = n;
	}
};

str_num add(str_num a, str_num b){
	str_num ans;
	ans.b = a.b + b.b;
	ans.a = a.a + b.a + (ans.b/MOD);
	ans.b %= MOD;

	return ans;
}

str_num mul(str_num a, str_num b){
	str_num ans;
	long long x1,x2,y1,y2, ex = 1e9;

	x1 = a.b/ex;
	y1 = a.b%ex;
	x2 = b.b/ex;
	y2 = b.b%ex;

	ans.a = x1*x2 + (x1*y2 + x2*y1)/ex;
	ans.b = y1*y2 + ((x1*y2 + x2*y1)%ex)*ex;
	ans.a += ans.b/MOD;
	ans.b %=MOD;
	return ans;
}

bool eq(str_num a, str_num b){
	return (a.a == b.a) && (a.b == b.b);
}

bool smaller(str_num a, str_num b){
	return (a.a < b.a) || ((a.a == b.a) && (a.b < b.b));
}

// void print_stuct(str_num a){
// 	std::vector<int> an;
// 	long long n = a.a, m = a.b;
// 	while(m > 0){
// 		an.push_back(m%10);
// 		m /= 10;
// 	}

// 	while(an.size() < 18){
// 		an.push_back(0);
// 	}

// 	while(n > 0){
// 		an.push_back(n%10);
// 		n /= 10;
// 	}

// 	for(int i = an.size() - 1; i >= 0; i--){
// 		std::cout << an[i];
// 	}
// }

void solve(){
	long long ax;
	std::cin >> ax;
	
	if(ax == 0 || ax == 2){
		std::cout << 1 << "\n";
		return;
	}

	if(ax <= 4){
		std::cout << 0 << "\n";
		return;
	}

	long long l = 0, r = 4*ax, mid;
	str_num rt = add(mul(str_num(5*ax),str_num(ax)), str_num(2*ax + 1)), sq_rt;

	while(r - l > 1){
		mid = (r + l)/2;
		sq_rt = mul(str_num(mid),str_num(mid));
		if(smaller(sq_rt,rt)){
			l = mid;
		}
		else{
			r = mid;
		}
	}

	if(eq(mul(str_num(l),str_num(l)), rt) || eq(mul(str_num(r),str_num(r)), rt)){
		std::cout << 1 << "\n";
		return;
	}

	std::cout << 0 << "\n";
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