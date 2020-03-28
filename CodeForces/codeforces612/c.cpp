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

void solve(){
	int n;
	cin>>n;
	vector<int> a(n,0);
	for(int i=0;i<n;i++)
		cin>>a[i];
	int od=0,ev=0;
	for(int i=1;i<=n;i++){
		if(i%2==1)
			od++;
		else
			ev++;
		if(a[i-1]!=0 && a[i-1]%2==1)
			od--;
		if(a[i-1]!=0 && a[i-1]%2==0)
			ev--;
	}
	// cout<<ev<<" -- " << od << "\n";
	int ans=0;
	if(n==1){
		cout<<ans<<"\n";
		return;
	}

	for(int i=0;i+1<n;i++){
		if(a[i]!=0&&a[i+1]!=0&&(a[i]%2!=a[i+1]%2))
			ans++;
	}
	int l=0,r=n-1;
	if(a[0]==0 || a[n-1]==0){
		while(l<n && a[l]==0)
			l++;

		while(r>-1 && a[r]==0)
			r--;
		if(l>=r){
			cout<<ans+1<<"\n";
			return;
		}
	}

	vector<int> ee,oo,eo;

	vector<pair<int,int>> gaps;
	for(int i=l;i<=r;i++){
		if(a[i]!=0){
			gaps.pb({a[i]%2,i+1});
		}
	}
	for(int i=0;i+1<gaps.size();i++){
		if(gaps[i].second+1<gaps[i+1].second){
			if(gaps[i].first==1 && gaps[i+1].first==1){
				oo.pb(gaps[i+1].second - gaps[i].second - 1);
			}
			if(gaps[i].first==0 && gaps[i+1].first==0){
				ee.pb(gaps[i+1].second - gaps[i].second - 1);
			}
			if(gaps[i].first!=gaps[i+1].first){
				eo.pb(gaps[i+1].second - gaps[i].second - 1);
			}
		}
	}
	sort(full(ee));
	sort(full(oo));
	for(int i=0;i<ee.size();i++){
		if(ev>=ee[i]){
			ev-=ee[i];
		}
		else
			ans+=2;
	}

	for(int i=0;i<oo.size();i++){
		if(oo[i]<=od){
			od-=oo[i];
		}
		else
			ans+=2;
	}

	if(a[0]==0){
		if(gaps[0].first==1){
			if(od>=gaps[0].second-1){
				od-=gaps[0].second-1;
			}
			else{
				ans++;
			}
		}
		else{
			if(ev>=gaps[0].second-1){
				ev-=gaps[0].second-1;
			}
			else{
				ans++;
			}
		}
	}

	if(a[n-1]==0){
		if(gaps[gaps.size()-1].first==1){
			if(od>=n-gaps[gaps.size()-1].second){
				od-=n-gaps[gaps.size()-1].second;
			}
			else{
				ans++;
			}
		}
		else{
			if(ev>=n-gaps[gaps.size()-1].second){
				ev-=n-gaps[gaps.size()-1].second;
			}
			else{
				ans++;
			}
		}
	}

	ans+=eo.size();
	cout<<ans<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}