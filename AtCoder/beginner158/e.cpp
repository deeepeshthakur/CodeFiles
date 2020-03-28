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

long long rec(vector<long long>& a, int x, int y, long long p){
	long long ans=0;
	if(y<x)
		return 0ll;
	if(y-x+1<=10){
		for(int i=x;i<=y;i++){
			long long tmp=0ll;
			for(int j=i;j<=y;j++){
				tmp=tmp*10ll+a[j];
				if(tmp%p==0)
					ans++;
			}
		}
		return ans;
	}
	else{
		ans = rec(a,x,(x+y)/2,p)+rec(a,(x+y)/2+1,y,p);
		unordered_map<long long, int> ht;
		int mid=(x+y)/2+1;
		vector<long long> tmp;
		long long tot=0;
		for(int i=mid;i<=y;i++){
			tot=(tot*10ll+a[i])%p;
			tmp.pb(tot);
		}
		tot=1;
		for(int i=y;i>=mid;i--){
			tmp[i-mid]=(1ll*tmp[i-mid]*tot)%p;
			tot=(tot*10)%p;
		}

		for(int i=0;i<tmp.size();i++){
			if(ht.find(tmp[i])!=ht.end()){
				(ht.find(tmp[i]))->second++;
			}
			else{
				ht[tmp[i]]=1;
			}
		}
		tot=1;
		long long half_sum=0,other_half;
		for(int i=mid;i<=y;i++){
			tot=(tot*10ll)%p;
		}

		for(int i=mid-1;i>=x;i--){
			half_sum=(half_sum+a[i]*tot)%p;
			tot=(tot*10)%p;
			other_half=(p-half_sum)%p;
			if(ht.find(other_half)!=ht.end()){
				ans+=((ht.find(other_half))->second);
			}
		}
	}
	return ans;
}

void solve(){
	int n;
	long long p;
	string s;
	cin>>n>>p>>s;
	vector<long long> a(n,0);
	for(int i=0;i<n;i++)
		a[i]=int(s[i]-'0');
	long long ans=0;
	if(p!=2 && p!=5)
		ans=rec(a,0,n-1,p);
	else{
		if(p==2){
			for(int i=0;i<n;i++)
				if(a[i]%2==0)
					ans+=(i+1);
		}
		else{
			for(int i=0;i<n;i++)
				if(a[i]%5==0)
					ans+=(i+1);
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