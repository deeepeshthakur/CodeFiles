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
	int n,a=0,b=0;
	cin>>n;
	bool flag1=false,flag2=false;
	vector<pair<string,int>> s;
	unordered_map<string,int> ht;
	vector<bool> valid(n,true);
	vector<int> direction(n,0);
	for(int i=0;i<n;i++){
		string x;
		cin>>x;

		if(x[0]=='0' && x[x.size()-1]=='0'){
			flag1=true;
			valid[i]=false;
		}

		if(x[0]=='1' && x[x.size()-1]=='1'){
			flag2=true;
			valid[i]=false;
		}

		if(x[0]!=x[x.size()-1]){
			if(x[0]=='0'){
				for(int j=0;j<=(x.size()-1-j);j++){
					swap(x[j],x[x.size()-1-j]);
				}
				s.pb({x,-i});
				direction[i]=-1;
				b++;
			}
			else{
				s.pb({x,i});
				direction[i]=1;
				a++;
			}
			auto itr=ht.find(x);
			if(itr!=ht.end()){
				valid[i]=false;
				valid[itr->second]=false;
			}
			else{
				ht.insert({x,i});
			}
		}
	}

	if(flag1&&flag2&&a==0&&b==0){
		cout<<-1<<"\n";
		return;
	}

	if(abs(a-b)<2){
		cout<<"0\n\n";
		return;
	}
	// cout<<a<<" "<<b<<endl;


	vector<int> ans;
	// cout<<a<<" "<<b<<endl;
	if(a<b){
		for(int i=0;i<n;i++){
			if(b-a>1 && direction[i]==-1 && valid[i]){
				ans.pb(i);
				b--;
				a++;
			}
		}
	}
	else{
		for(int i=0;i<n;i++){
			if(a-b>1 && direction[i]==1 && valid[i]){
				ans.pb(i);
				a--;
				b++;
			}
		}
	}

	if(abs(a-b)<2){
		cout<<ans.size()<<"\n";
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]+1<<(i+1<ans.size()?" ":"");
		}
		cout<<"\n";
	}
	else{
		cout<<"-1\n";
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