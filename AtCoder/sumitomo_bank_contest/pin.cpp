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
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<bool> one_array(10,false),two_array(100,false),three_array(1000,false);
	for(int i=n-1;i>=0;i--){
		int dig = int(s[i]-'0');
		for(int j=0;j<100;j++){
			if(two_array[j]){
				three_array[dig*100+j]=true;
			}
		}

		for(int j=0;j<10;j++){
			if(one_array[j]){
				two_array[dig*10+j]=true;
			}
		}
		one_array[dig]=true;
	}

	int ans=0;
	for(int i=0;i<three_array.size();i++)
		ans += (three_array[i] ? 1 : 0);
	cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	solve();
	
	return 0;
}