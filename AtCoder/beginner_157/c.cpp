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
	int n,m;
	cin>>n>>m;
	vector<int> s(m,0),c(max(m,n),-1);
	bool flag=true;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--;
		if(x==0 && n!=1 && y==0)
			flag=false;
		if(c[x]==-1 || c[x]==y)
			c[x]=y;
		else
			flag=false;
	}

	if(flag){
		int mul=1,ans=0;
		for(int i=c.size()-1;i>=0;i--){
			if(c[i]==-1){
				c[i]=0;
			}
			ans+=mul*c[i];
			mul*=10;
		}
		// bool flag1=false;
		if(n==1){
			if(ans<10){
				cout<<ans<<"\n";
			}
			else{
				cout<<-1<<"\n";
			}
		}
		if(n==2){
			if(ans<10){
				cout<<ans+10<<"\n";
			}
			if(ans>=10 && ans<100)
				cout<<ans<<"\n";
			if(ans>=100){
				cout<<-1<<"\n";
			}
		}
		if(n==3){
			if(ans<100){
				cout<<ans+100<<"\n";
			}
			if(ans>=100 && ans<1000)
				cout<<ans<<"\n";
			if(ans>=1000){
				cout<<-1<<"\n";
			}
		}
	}
	else{
		cout<<-1<<"\n";
	}
}	

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}