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
long long MOD=1e8;

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

int get_f(int ind,long long x, long long y, long long t, int n, vector<pair<long long, long long>>& points){
	int ans=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(ind+i<n && ind-j>=0){
				if(abs(x-points[ind+i].first)+abs(y-points[ind+i].second)+abs(points[ind-j].first-points[ind+i].first)+abs(points[ind-j].second-points[ind+i].second)<=t){
					ans=max(ans,i+j);
				}
				if(abs(x-points[ind-j].first)+abs(y-points[ind-j].second)+abs(points[ind-j].first-points[ind+i].first)+abs(points[ind-j].second-points[ind+i].second)<=t){
					ans=max(ans,i+j);
				}
			}
		}
	}
	return ans;
}

void solve(){
	MOD=MOD*MOD*10ll;
	long long x0,y0,ax,bx,ay,by,xs,ys,t;
	cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
	vector<pair<long long,long long>> points;
	points.pb({x0,y0});
	int ind=0;
	while(points[ind].first < MOD && points[ind].second < MOD){
		points.pb({ax*points[ind].first+bx,ay*points[ind].second+by});
		ind++;
	}

	int n=points.size();
	// for(int i=0;i<n;i++){
	// 	cout<<i+1 << " ----" << points[i].first<<" " <<points[i].second<<"\n";
	// }
	int curr;
	long long ttmp=t;
	int ans=0;
	for(int i=0;i<n;i++){
		ttmp=t;
		curr=i;
		if(abs(xs-points[curr].first)<=t && abs(ys-points[curr].second) <= t && abs(xs-points[curr].first)+abs(ys-points[curr].second)<=t){
			ttmp-=abs(xs-points[curr].first)+abs(ys-points[curr].second);
			ans=max(ans,1+get_f(curr,points[curr].first,points[curr].second,ttmp,n,points));
		}
		// cout<<i+1<< " " << ans<<"\n";
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