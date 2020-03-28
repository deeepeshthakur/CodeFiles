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
const long long MOD=1e9;

void get_parts(std::vector<long long>& a, std::vector<long long>& b, int l, int r){
	a.resize(r - l + 1,0ll);
	for(int i = l; i <= r; i++){
		a[i-l] = b[i];
	}
}

long long get_long_num(std::string& a, int l, int r){
	long long ans = 0, mul = 1;
	for(int i = r; i >= l; i--){
		ans += (int(a[i]-'0'))*mul;
		mul *= 10;
	}
	return ans;
}

void make_num(std::vector<long long>& a, std::string& b){
	int l = b.size();
	for(int i = l - 1; i > -1; i -= 9){
		a.push_back(get_long_num(b,std::max(0,i - 8), i));
	}
}

void get_input(std::vector<long long>& a, std::vector<long long>& b){
	std::string c,d;
	std::cin >> c >> d;
	make_num(a,c);
	make_num(b,d);
}

void carry_over(std::vector<long long>& a){
	for(int i = 0; i < a.size() - 1; i++){
		a[i+1] += a[i]/MOD;
		a[i] %= MOD;
	}
	long long tmp = a[a.size() - 1]/MOD;
	if(tmp > 0){
		a[a.size() - 1] %= MOD;
		a.push_back(tmp);
	}
}

std::vector<long long> plus(std::vector<long long>& a, std::vector<long long>& b){
	std::vector<long long> ans(std::max(a.size(),b.size()),0ll);
	for(int i = 0; i < ans.size(); i++){
		ans[i] = (i < a.size() ? a[i] : 0ll) + (i < b.size() ? b[i] : 0ll); 
	}

	carry_over(ans);
	return ans;
}

std::vector<long long> minus(std::vector<long long>& a, std::vector<long long>& b){
	std::vector<long long> ans(std::max(a.size(),b.size()),0ll);
	for(int i = 0; i < ans.size(); i++){
		if(i == 0)
			ans[i] = (i < a.size() ? (a[i] + MOD - 1) : 0ll) - (i < b.size() ? b[i] : 0ll);
		if(i == a.size() - 1)
			ans[i] = (i < a.size() ? (a[i] - 1) : 0ll) - (i < b.size() ? b[i] : 0ll);
		if(i > 0 && i < a.size() - 1)
			ans[i] = (i < a.size() ? a[i] : 0ll) - (i < b.size() ? b[i] : 0ll);
			
	}

	carry_over(ans);
	return ans;
}


std::vector<long long> mul(std::vector<long long>& a, std::vector<long long>& b){
	std::vector<long long> ans(a.size()+b.size(),0ll);
	if(std::min(a.size(),b.size()) == 1){
		for(int i = 0; i < a.size(); i++){
			for(int j = 0; j < b.size(); j++){
				ans[i+j] = a[i]*b[j];
			}
		}
		carry_over(ans);
		return ans;
	}

	std::vector<long long> aa,bb,cc,dd;
	get_parts(aa,a,0,(a.size()-1)/2);
	get_parts(bb,a,(a.size()-1)/2 + 1,a.size()-1);
	get_parts(cc,b,0,(b.size()-1)/2);
	get_parts(dd,b,(b.size()-1)/2 + 1,b.size()-1);

	std::vector<long long> ac = mul(aa,cc), bd = mul(bb,dd), apb = plus(a,b), cpd = plus(c,d);
	std::vector<long long> acpbd = plus(ac,bd), abcd = mul(apb,cpd);
	std::vector<long long> mid_term = minus(abcd,acpbd);

	for(int i = 0; i < bd.size(); i++){
		ans[i] += bd[i];
	}

	for(int i = 0; i < ac.size(); i++){
		ans[i] += bd[i];
	}

	for(int i = 0; i < bd.size(); i++){
		ans[i] += bd[i];
	}
	carry_over(ans);
	return ans;
}

void solve(){
	std::vector<long long> a, b;
	get_input(a,b);

	std::vector<long long> ans = mul(a,b);
	bool flag = false;
	for(int i = 0; i < ans.size(); i++){
		if(!flag && ans[ans.size() - 1 - i] != 0){
			flag = true;
		}

		if(flag){
			std::cout << ans[ans.size() - 1 - 1];
		}
	}
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