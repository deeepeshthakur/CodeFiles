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
const long long MOD=1e9;

bool cmp_f(const pair<long long, int>& a,const pair<long long, int>& b){
	return a.first<b.first || (a.first==b.first && a.second<b.second);
}

long long get_ll(int a, int b){
	return MOD*a+1ll*b;
}

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<vector<int>> dp(n,vector<int>(2,5*int(1e5)));
	for(int i=0;i<n;i++){
		if(i>0){
			for(int j=0;j<2;j++){
				dp[i][j]=dp[i-1][j];
			}
		}

		if(s[i]=='L'){
			dp[i][0]--;
		}
		if(s[i]=='R'){
			dp[i][0]++;
		}
		if(s[i]=='U'){
			dp[i][1]++;
		}
		if(s[i]=='D'){
			dp[i][1]--;
		}
	}

	unordered_map<long long,int> pts;
	int l=int(1e6),a=0,b=0;
	pts[get_ll(5*int(1e5),5*int(1e5))]=0;
	int x=0,y=0;
	for(int i=0;i<n;i++){
		x=dp[i][0];
		y=dp[i][1];
		if(pts.find(get_ll(x,y))!=pts.end()){
			auto itr=pts.find(get_ll(x,y));
			if(l>(i+1-(itr->second))){
				l=i+1-(itr->second);
				a=(itr->second)+1;
				b=i+1;
			}
			itr->second=i+1;
		}
		else{
			pts[get_ll(x,y)]=i+1;
		}
	}

	if(l>n+10){
		cout<<"-1\n";
	}
	else{
		cout<<a<<" "<<b<<"\n";
	}
	// set<long long> ls;
	// vector<long long> pts(n,0ll);
	// for(int i=0;i<n;i++){
	// 	pts[i]=1ll*dp[i][0]*MOD+1ll*dp[i][1];
	// 	ls.insert(pts[i]);
	// }

	// if(ls.size()==n){
	// 	if(dp[n-1][0]==5*int(1e5)&&dp[n-1][1]==5*int(1e5)){
	// 		cout<<1<<" "<<n<<"\n";
	// 	}
	// 	else
	// 		cout<<"-1\n";
	// }
	// else{
	// 	int l=n,a=0,b=0;
	// 	vector<pair<long long,int>> srt_lst;
	// 	for(int i=0;i<n;i++){
	// 		srt_lst.pb({pts[i],i+1});
	// 	}
	// 	sort(full(srt_lst),cmp_f);
	// 	for(int i=1;i<n;i++){
	// 		if(srt_lst[i].first==srt_lst[i-1].first){
	// 			if(srt_lst[i].second - srt_lst[i-1].second<l){
	// 				l=srt_lst[i].second - srt_lst[i-1].second;
	// 				a=srt_lst[i-1].second+1;
	// 				b=srt_lst[i].second;
	// 			}
	// 		}
	// 	}
	// 	cout<<a<<" "<<b<<"\n";
	// }
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