#include<bits/stdc++.h>
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
	int n=5;
	cout<<n<<"\n";
	while(n--){
		int a=100000;
		while(a--){
			cout<<rand()%2;
		}
		cout<<"\n";
		a=100000;
		while(a--){
			cout<<(rand()%4==0?0:1);
		}
		cout<<"\n";
			
	}

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	// auto start = chrono::high_resolution_clock::now();
	srand(time(0));
	solve();
	// auto stop = chrono::high_resolution_clock::now();
	return 0;
}