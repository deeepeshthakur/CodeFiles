#include<bits/stdc++.h>
#define ll int
#define pll std::pair<ll,ll>
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define per(i,a,b) for(ll i=(ll)a;i>(ll)b;i--)
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

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	std::string str;
	std::cin>>str;
	std::vector<int> a(n,0),s(n,0);
	rep(i,0,n){
		if(str[i]=='('){
			a[i]=-1;
		}
		else{
			a[i]=1;
		}
	}

	per(i,n-1,-1){
		s[i]=a[i];
		if(i+1<n){
			s[i]+=s[i+1];
		}
	}
	if(n%2){
		std::cout<<"0\n";
		return 0;
	}

	int ans=0,c=0;
	rep(i,0,n){
		c+=a[i];
		if(c<0&&i+1<n&&s[i+1]>0&&(s[i+1]+c==-2||s[i+1]+c==2)){
			ans++;
		}
	}

	std::cout<<ans<<std::endl;
	return 0;
}