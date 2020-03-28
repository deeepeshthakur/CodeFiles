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

void print_vec(vector<int>& a,int n=-1){
	n = (n==-1 ? a.size():n);
	for(int i=0;i<n;i++)
		cout << a[i] << (i<n-1 ? " ":"\n");
}

void print_vec(vector<long long>& a,int n=-1){
	n=(n==-1 ? a.size():n);
	for(int i=0;i<n;i++)
		cout << a[i] << (i<n-1 ? " ":"\n");
}

long long max_solve(long long t, long long e, long long a, long long h, long long b){
	e=max(0ll,e);
	h=max(0ll,h);
	return (min(t/a,e)+min((t-a*min(t/a,e))/b,h));
}

void solve(){
	int n;
	long long t,a,b,h_tot=0,e_tot=0;

	cin>>n>>t>>a>>b;
	vector<long long> tp(n,0ll);
	vector<long long> ti(n,0ll);
	vector<pair<long long,long long>> ques_tmp(n);
	for(int i=0;i<n;i++)
		cin>>tp[i];

	for(int i=0;i<n;i++)
		cin>>ti[i];

	for(int i=0;i<n;i++){
		ques_tmp[i].first=ti[i];
		ques_tmp[i].second=tp[i];
		if(tp[i]==1)
			h_tot++;
		else
			e_tot++;
	}
	sort(full(ques_tmp));
	for(int i=0;i<n;i++){
		cout<< ques_tmp[i].first << " " << ques_tmp[i].second << "\n";
	}

	vector<vector<int>> hard_ness;
	vector<long long> ques;
	for(int i=0;i<n;i++){
		if(i>0 && ques_tmp[i].first == ques_tmp[i-1].first){
			hard_ness[hard_ness.size()-1].pb(int(ques_tmp[i].second));
		}
		else{
			ques.pb(ques_tmp[i].first);
			hard_ness.pb(vector<int>{int(ques_tmp[i].second)});
		}
	}

	if(ques[ques.size()-1]<t){
		ques.pb(t);
		hard_ness.pb(vector<int>{-1});
	}

	long long ans=0,tmp;
	bool flag=true;
	long long curr_time=0,pre_req=0,pre_easy=0,pre_hard=0,time_to_solve=0,easy_avail=0,hard_avail=0;
	for(int i=0;i<ques.size() && flag;i++){
		if(flag){
			// leave at ti[i]-1
			curr_time=min(ques[i]-1,t);
			time_to_solve=curr_time-pre_req;
			easy_avail=max(0ll,e_tot-pre_easy);
			hard_avail=max(0ll,h_tot-pre_hard);
			ans=max(ans,pre_hard+pre_easy+max_solve(time_to_solve,easy_avail,a,hard_avail,b));
			cout << curr_time << " " << ans << "\n";
			// stay till t[i]
			curr_time=ques[i];
			if(curr_time<=t){
				for(int j=0;j<hard_ness[i].size();j++){
					if(hard_ness[i][j]==1){
						pre_req+=b;
						pre_hard++;
					}
					if(hard_ness[i][j]==0){
						pre_req+=a;
						pre_easy++;
					}
				}

				if(curr_time<pre_req){
					flag=false;
				}
				else{
					time_to_solve=curr_time-pre_req;
					easy_avail=max(0ll,e_tot-pre_easy);
					hard_avail=max(0ll,h_tot-pre_hard);
					ans=max(ans,pre_hard+pre_easy+max_solve(time_to_solve,easy_avail,a,hard_avail,b));
				}
			}
			else{
				flag=false;
			}
		}
	}
	cout<<ans<<"\n";
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