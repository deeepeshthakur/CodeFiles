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

// struct node{
// 	long long l,b;
// 	node *next;

// 	node(){
// 		l = 0;
// 		b = 0;
// 		next = NULL;
// 	}

// 	node(long long x, long long y, node *nxt){
// 		l = x;
// 		b = y;
// 		next = nxt;
// 	}

// 	long long get_area(){
// 		return l*b;
// 	}
// };

// bool f3(node *a, node *b){
// 	return a->get_area() + b->get_area() >= std::max(a->l,b->l)*std::max(a->b,b->b);
// }

// long long f2(node *head){
// 	bool flag = true;
// 	long long ans = 0;
// 	node *curr, *rn, *nx;

// 	while(flag){
// 		flag = false;
// 		long long cur_min = (1ll*int(1e6))*int(1e6), l = 0, b = 0;
// 		curr = head;
// 		while(curr){
// 			if(curr->next){
// 				if(f3(curr,curr->next)){
// 					nx = curr->next;
// 					if(cur_min > std::max(curr->l,nx->l)*std::max(curr->b,nx->b)){
// 						cur_min = std::max(curr->l,nx->l)*std::max(curr->b,nx->b);
// 						rn = curr;
// 						flag = true;
// 					}
// 				}
// 			}
// 			curr = curr->next;
// 		}

// 		if(flag){
// 			nx = rn->next;
// 			rn->l = std::max(rn->l,nx->l);
// 			rn->b = std::max(rn->b,nx->b);
// 			rn->next = nx->next;
// 		}
// 	}

// 	curr = head;
// 	while(curr){
// 		ans += curr->get_area();
// 		curr = curr->next;
// 	}

// 	return ans;
// }

bool f1(std::vector<int>& a, std::vector<int>& b){
	return ((a[1] < b[1]) || (a[1] == b[1] && a[0] < b[0]));
}

bool f0(std::vector<int>& a, std::vector<int>& b){
	return ((a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]));
}

void solve(){
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> plots(n,std::vector<int>(3,0)), plots_B(n,std::vector<int>(3,0));

	for(int i = 0; i < n; i++){
		std::cin >> plots[i][0] >> plots[i][1];
		plots[i][2] = i;

		plots_B[i][0] = plots[i][0];
		plots_B[i][1] = plots[i][1];
		plots_B[i][2] = plots[i][2];
	}

	std::sort(full(plots),f0);
	std::sort(full(plots_B),f1);

	std::vector<bool> vld(n,true);
	int x = n - 1,y = 0;
	for(;x >= 0; x--){
		int i = plots[x][2];
		if(vld[i]){
			while(y < n && plots_B[y][2] != i){
				vld[plots_B[y][2]] = false;
				y++;
			}
			y++;
		}
	}

	std::vector<std::vector<long long>> fplots;
	// node *head = new node, *curr;
	// curr = head;
	for(int i = 0; i < n; i++){
		if(vld[plots[i][2]]){
			fplots.push_back({plots[i][0]*1ll,plots[i][1]*1ll});
			// curr->next = new node;
			// curr = curr->next;
			// curr->l = plots[i][0]*1ll;
			// curr->b = plots[i][1]*1ll;
		}
	}
	// head = head->next; 	

	// std::cout << fplots.size() << std::endl;
	// for(int i = 0; i < fplots.size(); i++){
	// 	std::cout << fplots[i][0] << " " << fplots[i][1] << "\n";
	// }
	// std::cout << std::endl;

	vld.resize(fplots.size());
	for(int i = 0; i < vld.size(); i++)
		vld[i] = true;

	long long ans = 0ll, l = 0ll, b = 0ll, tmp = 0ll;
	for(int i = 0; i < fplots.size(); i++){

		if(vld[i]){
			vld[i] = false;
			l = fplots[i][0];
			b = fplots[i][1];
			tmp = l*b;
			int j = i + 1;
			bool flag = true;
			while(flag && j < fplots.size()){
				if(tmp + fplots[j][0]*fplots[j][1] >= std::max(l,fplots[j][0])*std::max(b,fplots[j][1])){
					l = std::max(l,fplots[j][0]);
					b = std::max(b,fplots[j][1]);
					tmp = l*b;
					vld[j] = false;
				}	
				else{
					flag = false;
				}
				j++;
			}
			std::cout << i << " " << j << " " << l << " " << b << std::endl;
			ans += tmp;
		}
	}

	// long long ans = f2(head);

	std::cout << ans << std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}