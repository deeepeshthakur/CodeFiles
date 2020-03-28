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

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::string s;
	std::cin >> n;
	std::cin >> s;

	std::stack<int> qu;
	for(int i = 0; i < n ; i++){
		if(s[i] == '('){
			qu.push(1);
		}

		if(s[i] == ')'){
			if(!qu.empty() && qu.top() == 1){
				qu.pop();
			}
			else{
				qu.push(-1);
			}
		}
	}

	if(qu.size() == 0 || qu.size() == 2){
		if(qu.size() == 0)
			std::cout << "Yes" << std::endl;
		else{
			int a = qu.top();
			qu.pop();
			int b = qu.top();
			qu.pop();

			if(a == 1 && b == -1){
				std::cout << "Yes" << std::endl;
			}
			else{
				std::cout << "No" << std::endl;
			}
		}
	}
	else
		std::cout << "No" << std::endl;
	return 0;
}