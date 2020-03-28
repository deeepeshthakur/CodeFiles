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

void print_vec(std::vector<long long>& a){
	for(int i=0;i<a.size();i++)
		std::cout << a[i] << (i<a.size()-1? " ":"\n");
}

void print_vec(std::vector<int>& a){
	for(int i=0;i<a.size();i++)
		std::cout << a[i] << (i<a.size()-1? " ":"\n");
}


bool f1(int i){
	std::vector<int> ans;
	while(i){
		ans.pb(i%10);
		i/=10;
	}
	std::sort(full(ans));
	return (ans[0]==1) && (ans[1]==6) && (ans[2]==8) && (ans[3]==9) && (ans.size() == 4);
}

void rem_calc(std::vector<std::vector<int>>& a){
	std::vector<bool> chk(7,true);
	for(int i=1000;i<9999;i++){
		if(f1(i)){
			int rem = i%7;
			if(chk[rem]){
				a[rem][3] = (i/1000)%10;
				a[rem][2] = (i/100)%10;
				a[rem][1] = (i/10)%10;
				a[rem][0] = i%10;
				chk[rem] = false;
			}
		}
	}
}

void solve(){
	std::vector<std::vector<int>> ans(7,std::vector<int>(4,0));
	rem_calc(ans);

	std::string str;
	std::cin >> str;
	std::vector<int> digits(10,0);

	for(int i=0;i<str.size();i++){
		digits[int(str[i]-'0')]++;
	}

	digits[1]--;
	digits[6]--;
	digits[8]--;
	digits[9]--;

	std::vector<int> num(str.size()-digits[0],0);
	int k=num.size()-1;
	for(int i=1;i<10;i++){
		while(digits[i]>0 && k>-1){
			num[k]=i;
			digits[i]--;
			k--;
		}
	}

	int mul=1,ans_rem=0;
	for(int i=0;i<num.size();i++){
		ans_rem = (ans_rem + (num[i]*mul)%7)%7;
		mul = (mul*10)%7;
	}

	ans_rem = (7-ans_rem)%7;
	// k = digits[0];
	num[0] = ans[ans_rem][0];
	num[1] = ans[ans_rem][1];
	num[2] = ans[ans_rem][2];
	num[3] = ans[ans_rem][3];

	for(int i=num.size()-1;i>-1;i--){
		std::cout << num[i];
	}
	for(int i=0;i<digits[0];i++)
		std::cout << 0;
	std::cout << "\n";
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