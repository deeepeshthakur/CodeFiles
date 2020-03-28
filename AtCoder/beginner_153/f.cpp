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

bool cmp_fun(const pair<long long,long long>& a,const pair<long long,long long>& b){

}

void solve(){
	int n;
	long long d,a;
	cin>>n>>d>>a;
	vector<long long> x(n,0ll),h(n,0ll);
	vector<pair<long long,long long>> xh(n,{0ll,0ll});
	for(int i=0;i<n;i++){
		cin>>x[i]>>h[i];
		if(h[i]%a==0){
			h[i]=h[i]/a;
		}
		else{
			h[i]=(h[i]/a)+1;
		}
	}

	for(int i=0;i<n;i++){
		xh[i].first=x[i];
		xh[i].second=h[i];
	}
	sort(full(xh));
	int ind=0;
	vector<pair<long long,long long>> xh1;
	for(int i=0;i<n;i++){
		if(i>0){
			if(xh1[ind].first==xh[i].first){
				xh1[ind].second=max(xh1[ind].second,xh[i].second);
			}
			else{
				ind++;
				xh1.pb({xh[i].first,xh[i].second});
			}
		}
		else{
			xh1.pb({xh[i].first,xh[i].second});
			ind=0;
		}
	}
	x.resize(xh1.size());
	h.resize(xh1.size());
	n=xh1.size();
	for(int i=0;i<n;i++){
		x[i]=xh1[i].first;
		h[i]=xh1[i].second;
	}

	long long del=0,curr_h=0;
	queue<pair<long long,long long>> diff_q;
	long long ans=0;
	for(int i=0;i<n;i++){
		// cout<< i+1 << " " << del << " " << curr_h << "\n";
		if(!diff_q.empty() && diff_q.front().first<=x[i]){
			del+=diff_q.front().second;
			diff_q.pop();
		}
		if(curr_h>del){
			curr_h-=del;
			del=0ll;
		}
		if(del+h[i]>curr_h){
			long long tmp =(del+h[i]-curr_h);
			curr_h=del+h[i];
			ans+=tmp;
			diff_q.push({x[i]+2ll*d+1ll,tmp});
		}
	}	
	cout<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}