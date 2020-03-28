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

void print_vec(vector<int>& a){
	int n=a.size();
	for(int i=0;i<a.size();i++)
		cout << a[i] << (i<n-1 ? " ":"\n");
}

void print_vec(vector<long long>& a){
	int n=a.size();
	for(int i=0;i<a.size();i++)
		cout << a[i] << (i<n-1 ? " ":"\n");
}

int get_num(vector<int> num, int i, int j){
	num[i]=j;
	return num[0]*1000+num[1]*100+num[2]*10+num[3];
}

bool sear(vector<int>& pin, vector<int> num, int ind, int dig){
	num[ind]=dig;
	int n = get_num(num,ind,dig);
	for(int i=0;i<pin.size();i++){
		if(pin[i]==n)
			return true;
	}
	return false;
}

void change_pin(int ind, vector<int>& pin){
	vector<int> num{pin[ind]/1000,(pin[ind]/100)%10, (pin[ind]/10)%10,pin[ind]%10};
	for(int i=0;i<4;i++){
		for(int j=0;j<10;j++){
			if(!sear(pin,num,i,j)){
				pin[ind] = get_num(num,i,j);
				return;
			}
		}
	}
}

void solve(){
	int n;
	cin>>n;
	vector<int> pin(n,0);
	for(int i=0;i<n;i++){
		cin>>pin[i];
	}
	int ans=0;
	// print_vec(pin);
	// bool flag=false;
	// for(int i=1;i<n;i++){
	// 	if(pin[i]==pin[i-1]){
	// 		flag=true;
	// 	}
	// }

	// while(flag){
	// 	sort(full(pin));
	// 	// print_vec(pin);
	// 	int i=1;
	// 	while(i<n && pin[i]!=pin[i-1]){
	// 		i++;
	// 	}

	// 	if(i<n){
	// 		ans++;
	// 		change_pin(i,pin);
	// 	}
	// 	else{
	// 		flag=false;
	// 	}
	// }

	// int ans = 0;
	vector<pair<int,int>> dp;
	vector<vector<int>> dp2;
	for(int i=0;i<n;i++){
		bool flag=true;
		for(int j=0;j<dp.size();j++){
			if(pin[i]==dp[j].F){
				dp[j].S+=1;
				dp2[j].pb(i);
				flag=false;
			}
		}

		if(flag){
			dp.pb({pin[i],1});
			dp2.pb(vector<int>{i});
		}
	}
	vector<int> fin_ans(n,0);
	for(int i=0;i<dp.size();i++){
		ans+=dp[i].S-1;
		for(int j=0;j<dp[i].S;j++){
			fin_ans[dp2[i][j]] = (dp[i].F - (dp[i].F%10) + ((dp[i].F%10)+j)%10);
		}
	}
	cout <<ans<<"\n";
	for(int i=0;i<n;i++){
		cout << char((fin_ans[i]/1000)+'0') << char(((fin_ans[i]/100)%10)+'0') << char(((fin_ans[i]/10)%10)+'0') << char((fin_ans[i]%10)+'0') << "\n";
 	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;       
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}