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
const double MOD=1e9+7;

bool f1(std::vector<int>& a){
	bool flag = true;	
	for(int i = 1; i < a.size(); i++){
		flag = (flag && (a[i] >= a[i-1]));
	}
	return flag;
}

void solve(){
	int n;
	std::cin >> n;
	std::vector<int> a(n,0), b(n,0);
	for(int i = 0; i < n; i++){
		std::cin >> a[i];
		b[i] = a[i];
	}

	std::sort(full(b));

	if(f1(a)){
		std::cout << "yes\n";
		std::cout << "1 1\n";
		return;
	}

	int x,y;
	for(int i = 0; i < n; i++){
		if(a[i] != b[i]){
			x = i;
			i = n;
		}
	}

	for(int i = n - 1; i > -1; i--){
		if(a[i] != b[i]){
			y = i;
			i = -1;
		}
	}

	bool flag = true;
	for(int i = x; i <= y; i++){
		flag = (flag && (a[i] == b[y - i + x]));
	}

	if(flag){
		std::cout << "yes\n" << x + 1 << " " << y + 1 << std::endl;
	}
	else{
		std::cout << "no\n";
	}

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}