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

bool tf(long long del, int n, vector<long long>& a){
	bool f1=true,f2=true;
	for(int i=1;i<n;i++){
		if(a[i-1]!=-1 && a[i]!=-1 && abs(a[i-1]-a[i])>del)
			f1=false;
	}

	long long x=0ll,y=3ll*int(1e9);
	for(int i=0;i<n;i++){
		if(a[i]==-1){
			if(i<n-1 && a[i+1]!=-1){
				x=max(x,a[i+1]-del);
				y=min(y,a[i+1]+del);
			}

			if(i>0 && a[i-1]!=-1){
				x=max(x,a[i-1]-del);
				y=min(y,a[i-1]+del);
			}
		}
	}

	// cout<< del<< " " << x << " " << y << "\n"; 
	if(x>y)
		f2=false;
	return f1&&f2;
}

void solve(){
	int n;
	cin>>n;
	vector<long long> a(n,0ll);
	for(int i=0;i<n;i++)
		cin>>a[i];

	long long l=0,r=3ll*MOD,mid;
	while(r-l>1){
		mid=(l+r)/2;
		if(tf(mid,n,a))
			r=mid;
		else
			l=mid;
	}

	if(tf(l,n,a))
		r=l;

	long long x=0,y=int(1e9);
	for(int i=0;i<n;i++){
		if(i<n-1){
			if(a[i]!=-1 && a[i+1]==-1){
				x=max(x,a[i]-r);
				y=min(y,a[i]+r);
			}
		}

		if(i>0){
			if(a[i]!=-1 && a[i-1]==-1){
				x=max(x,a[i]-r);
				y=min(y,a[i]+r);
			}
		}
	}

	cout<<r<<" "<<x<<"\n";
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