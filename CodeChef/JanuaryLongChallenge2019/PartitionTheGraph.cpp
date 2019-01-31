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

struct node{
	bool odd,vis;
	int sz,col;
	std::vector<int> children;
	node(){
		odd=false;
		vis=false;
		col=-1;
		sz=0;
		children.resize(0);
	}
};

void f103(int root,int colour,std::vector<node>& tree){
	if(tree[root].vis){
		return;
	}

	tree[root].vis=true;
	tree[root].col=colour;
	int on=0;
	rep(i,0,tree[root].children.size()){
		if(!tree[tree[root].children[i]].vis){
			if(tree[tree[root].children[i]].sz%2){
				if(on%2){
					f103(tree[root].children[i],colour,tree);
				}
				else{
					f103(tree[root].children[i],1-colour,tree);
				}
				on++;
			}
			else{
				f103(tree[root].children[i],1-colour,tree);
			}
		}
	}

}

void f102(int root,std::vector<node>& tree){
	if(tree[root].vis){
		return;
	}

	tree[root].vis=true;
	rep(i,0,tree[root].children.size()){
		if(!tree[tree[root].children[i]].vis){
			f102(tree[root].children[i],tree);
			tree[root].sz+=tree[tree[root].children[i]].sz;
		}
	}
	tree[root].sz++;
}


void f101(int root,int& k,bool label,std::vector<node>& tree){
	if(tree[root].vis){
		return;
	}

	tree[root].vis=true;
	if(label){
		k++;
	}
	tree[root].odd=label;

	rep(i,0,tree[root].children.size()){
		f101(tree[root].children[i],k,!label,tree);
	}
}

void f100(){
	int n;
	std::cin>>n;
	std::vector<node> tree(n);
	rep(i,0,n-1){
		int s,e;
		std::cin>>s>>e;
		s--;
		e--;
		tree[s].children.pb(e);
		tree[e].children.pb(s);
	}
	rep(i,0,n){
		tree[i].vis=false;
	}

	//check for k=1
	int k=0;
	f101(0,k,true,tree);
	if(k*2==n){
		std::cout<<1<<"\n";
		rep(i,0,n){
			if(tree[i].odd){
				std::cout<<i+1<<" ";
			}
		}
		std::cout<<"\n";
		rep(i,0,n){
			if(!tree[i].odd){
				std::cout<<i+1<<" ";
			}
		}
		std::cout<<"\n";
		return;
	}

	rep(i,0,n){
		tree[i].vis=false;
	}
	f102(0,tree);

	rep(i,0,n){
		tree[i].vis=false;
	}

	f103(0,1,tree);
	std::cout<<2<<"\n";
	rep(i,0,n){
		if(tree[i].col){
			std::cout<<i+1<<" ";
		}
	}
	std::cout<<"\n";

	rep(i,0,n){
		if(tree[i].col==0){
			std::cout<<i+1<<" ";
		}
	}
	std::cout<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin>>t;
	while(t--){
		f100();
	}
	return 0;
}