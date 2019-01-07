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
const long long MOD=7+1e9;

int n,m;
std::vector<std::vector<bool>> state{};
std::unordered_map<std::string,long long> dp{};

void f103(std::string& a,std::vector<std::vector<bool>>& st){
	rep(i,0,n){
		rep(j,0,m){
			st[i][j]=(a[i*m+j]=='#')?false:true;
		}
	}
}

std::string f102(std::vector<std::vector<bool>>& st){
	std::string str(n*m,'.');
	rep(i,0,n){
		rep(j,0,m){
			if(!st[i][j])
				str[i*m+j]='#';
		}
	}
	return str;
}

long long f101(std::string s){
	{
		auto ptr=dp.find(s);
		if(ptr!=dp.end()){
			return ptr->second%MOD;
		}
	}
	f103(s,state);
	bool f=true;
	int x,y;
	long long ans=0;
	for(int i=0;i<n&&f;i++){
		for(int j=0;j<m&&f;j++){
			if(state[i][j]){
				x=i;
				y=j;
				f=false;
			}
		}
	}
	if(!f){
		std::vector<std::string> fc{};
		//first L
		if(state[x][y]&&x+1<n&&state[x+1][y]&&y-1>=0&&state[x+1][y-1]&&y-2>=0&&state[x+1][y-2]){
			std::string sd(s);
			sd[x*m+y]='#';
			sd[(x+1)*m+y]='#';
			sd[(x+1)*m+y-1]='#';
			sd[(x+1)*m+y-2]='#';
			fc.pb(sd);
		}

		//second L
		if(state[x][y]&&x+1<n&&state[x+1][y]&&y+1<m&&state[x+1][y+1]&&y+2<m&&state[x+1][y+2]){
			std::string sd(s);
			sd[x*m+y]='#';
			sd[(x+1)*m+y]='#';
			sd[(x+1)*m+y+1]='#';
			sd[(x+1)*m+y+2]='#';
			fc.pb(sd);
		}

		//third L
		if(state[x][y]&&x+1<n&&state[x+1][y]&&y+1<m&&state[x][y+1]&&y+2<m&&state[x][y+2]){
			std::string sd(s);
			sd[x*m+y]='#';
			sd[(x+1)*m+y]='#';
			sd[(x)*m+y+1]='#';
			sd[(x)*m+y+2]='#';
			fc.pb(sd);
		}

		// fourth L
		if(state[x][y]&&y+1<m&&state[x][y+1]&&y+2<m&&state[x][y+2]&&x+1<n&&state[x+1][y+2]){
			std::string sd(s);
			sd[x*m+y]='#';
			sd[x*m+y+1]='#';
			sd[x*m+y+2]='#';
			sd[(x+1)*m+y+2]='#';
			fc.pb(sd);
		}

		// fifth L
		if(state[x][y]&&y+1<m&&x+2<n&&state[x+1][y]&&state[x+2][y]&&state[x+2][y+1]){
			std::string sd(s);
			sd[x*m+y]='#';
			sd[(x+1)*m+y]='#';
			sd[(x+2)*m+y]='#';
			sd[(x+2)*m+y+1]='#';
			fc.pb(sd);
		}

		// sixth L
		if(state[x][y]&&y-1>=0&&x+2<n&&state[x+1][y]&&state[x+2][y]&&state[x+2][y-1]){
			std::string sd(s);
			sd[x*m+y]='#';
			sd[(x+1)*m+y]='#';
			sd[(x+2)*m+y]='#';
			sd[(x+2)*m+y-1]='#';
			fc.pb(sd);
		}

		// seventh L
		if(state[x][y]&&y+1<m&&x+2<n&&state[x+1][y]&&state[x+2][y]&&state[x][y+1]){
			std::string sd(s);
			sd[x*m+y]='#';
			sd[(x+1)*m+y]='#';
			sd[(x+2)*m+y]='#';
			sd[x*m+y+1]='#';
			fc.pb(sd);
		}

		// eighth L
		if(state[x][y]&&y+1<m&&x+2<n&&state[x][y+1]&&state[x+1][y+1]&&state[x+2][y+1]){
			std::string sd(s);
			sd[x*m+y]='#';
			sd[x*m+y+1]='#';
			sd[(x+1)*m+y+1]='#';
			sd[(x+2)*m+y+1]='#';
			fc.pb(sd);
		}
		rep(i,0,fc.size()){
			ans+=f101(fc[i]);
			ans%=MOD;
		}
		ans%MOD;
	}
	dp.insert({s,ans});
	return ans;
}

void f100(){
	std::cin>>n>>m;
	state.resize(n,std::vector<bool>(m,false));
	dp.clear();
	dp.insert({f102(state),1});
	rep(i,0,n){
		std::string a;
		std::cin>>a;
		rep(j,0,m){
			if(a[j]=='.'){
				state[i][j]=true;
			}
		}
	}

	std::string s=f102(state);
	std::cout<<f101(s)%MOD<<std::endl;
	state.clear();
	dp.clear();
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int q;
	std::cin>>q;
	while(q--){
		f100();
	}
	return 0;
}