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
	int n,k;
	std::cin>>n>>k;
	std::vector<int> bn{};
	{
		int a,b;
		a=n;
		b=1;
		while(a){
			if(a%2){
				bn.pb(b);
			}
			a/=2;
			b*=2;
		}
	}

	if(k<bn.size()||k>n){
		std::cout<<"NO\n";
		return 0;
	}
	std::cout<<"YES"<<std::endl;

	std::queue<int> q{},ans{};
	rep(i,0,bn.size()){
		q.push(bn[i]);
	}

	while(!q.empty()){
		if(q.size()==k){
			while(!q.empty()){
				ans.push(q.front());
				q.pop();
			}
		}
		else{
			if(q.front()==1){
				q.pop();
				ans.push(1);
				k--;
			}
			else{
				int a=q.front();
				q.pop();
				q.push(a/2);
				q.push(a/2);
			}
		}
	}

	while(!ans.empty()){
		std::cout<<ans.front()<<" ";
		ans.pop();
	}
	std::cout<<"\n";
	return 0;
}